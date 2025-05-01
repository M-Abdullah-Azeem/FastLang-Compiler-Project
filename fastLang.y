// === FILE: fastlang.y (Bison parser with Semantic Analyzer — no $-N references) ===
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char curType[10];
int tempCount = 0;
extern int yylineno;
FILE *out;

// Symbol table entry
typedef struct {
    char name[64];
    char type[10];
} Symbol;

Symbol symtab[100];
int symCount = 0;

char* newTemp() {
    char* buf = malloc(10);
    sprintf(buf, "t%d", tempCount++);
    return buf;
}

void addSymbol(const char* name, const char* type) {
    for (int i = 0; i < symCount; ++i) {
        if (strcmp(symtab[i].name, name) == 0) {
            fprintf(stderr, "Semantic Error at line %d: Redeclaration of variable '%s'\n", yylineno, name);
            exit(1);
        }
    }
    strcpy(symtab[symCount].name, name);
    strcpy(symtab[symCount].type, type);
    symCount++;
}

const char* getType(const char* name) {
    for (int i = 0; i < symCount; ++i) {
        if (strcmp(symtab[i].name, name) == 0) return symtab[i].type;
    }
    fprintf(stderr, "Semantic Error at line %d: Undeclared variable '%s'\n", yylineno, name);
    exit(1);
}

void checkType(const char* lhs, const char* rhs) {
    if (strcmp(lhs, rhs) != 0) {
        fprintf(stderr, "Semantic Error at line %d: Type mismatch (%s vs %s)\n", yylineno, lhs, rhs);
        exit(1);
    }
}

void yyerror(const char *s);
int yylex();
%}

%union {
    int intVal;
    char charVal;
    char* stringVal;
    struct {
        char* place;
        char* type;
    } expr;
}

%token <intVal> INT_LITERAL BOOL_LITERAL
%token <stringVal> IDENTIFIER STRING_LITERAL
%token <charVal> CHAR_LITERAL

%token INT BOOL STRING CHAR IF ELSE WHILE RETURN VOID PRINT SCAN MAIN
%token ASSIGN PLUS MINUS TIMES DIVIDE MOD
%token LT GT LE GE EQ NE
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

%left OR
%left AND
%left EQ NE LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right NOT
%right UMINUS

%type <stringVal> base_type idInit return_type
%type <expr> expression E T U F

%%
program:
    function_declarations main_function
    ;

function_declarations:
    function_declarations function_decl
    | /* empty */
    ;

function_decl:
    return_type IDENTIFIER LPAREN parameters RPAREN compound_stmt
    ;

return_type:
    VOID   { $$ = "void"; }
    | base_type
    ;

base_type:
    INT     { $$ = "int"; }
    | BOOL  { $$ = "bool"; }
    | STRING{ $$ = "string"; }
    | CHAR  { $$ = "char"; }
    ;

parameters:
    parameter_list
    | /* empty */
    ;

parameter_list:
    parameter
    | parameter_list COMMA parameter
    ;

parameter:
    base_type IDENTIFIER { addSymbol($2, $1); }
    ;

main_function:
    INT MAIN LPAREN RPAREN compound_stmt
    ;

compound_stmt:
    LBRACE VarDeclaration stmt_list RBRACE 
    ;

VarDeclaration:
    base_type[ret] {
        strcpy(curType, $ret);
    } idList SEMICOLON
    ;

idList:
    idInit
    | idInit COMMA idList
    ;

idInit:
    IDENTIFIER {
        addSymbol($1, curType);
    }
    | IDENTIFIER ASSIGN expression {
        checkType(curType, $3.type);
        addSymbol($1, curType);
        fprintf(out, "%s := %s\n", $1, $3.place);
    }
    ;

stmt_list:
    stmt_list statement
    | /* empty */
    ;

statement:
    expr_stmt | compound_stmt | selection_stmt | iteration_stmt | return_stmt | io_stmt;

expr_stmt:
    IDENTIFIER ASSIGN expression SEMICOLON {
        checkType(getType($1), $3.type);
        fprintf(out, "%s := %s\n", $1, $3.place);
    }
    ;

selection_stmt:
    IF LPAREN expression RPAREN statement ELSE statement
    | IF LPAREN expression RPAREN statement
    ;

iteration_stmt:
    WHILE LPAREN expression RPAREN statement
    ;

return_stmt:
    RETURN expression SEMICOLON { fprintf(out, "return %s\n", $2.place); }
    | RETURN SEMICOLON { fprintf(out, "return\n"); }
    ;

io_stmt:
    PRINT LPAREN expression RPAREN SEMICOLON {
        fprintf(out, "param %s\n", $3.place);
        fprintf(out, "call print, 1\n");
    }
    | SCAN LPAREN IDENTIFIER RPAREN SEMICOLON {
        getType($3);
        fprintf(out, "param %s\n", $3);
        fprintf(out, "call scan, 1\n");
    }
    ;

expression:
    E { $$ = $1; }
    ;

E:
    E PLUS T {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s + %s\n", t, $1.place, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | E MINUS T {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s - %s\n", t, $1.place, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | T { $$ = $1; }
    ;

T:
    T TIMES U {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s * %s\n", t, $1.place, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | T DIVIDE U {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s / %s\n", t, $1.place, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | T MOD U {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s %% %s\n", t, $1.place, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | U { $$ = $1; }
    ;

U:
    MINUS F %prec UMINUS {
        if (strcmp($2.type, "int") != 0) {
            fprintf(stderr, "Semantic Error at line %d: Unary minus on non-int\n", yylineno);
            exit(1);
        }
        char* t = newTemp();
        fprintf(out, "%s := -%s\n", t, $2.place);
        $$ = (typeof($$)){ .place = t, .type = "int" };
    }
    | F { $$ = $1; }
    ;

F:
    INT_LITERAL {
        char* buf = malloc(10);
        sprintf(buf, "%d", $1);
        $$ = (typeof($$)){ .place = buf, .type = "int" };
    }
    | BOOL_LITERAL {
        $$ = (typeof($$)){ .place = $1 ? "true" : "false", .type = "bool" };
    }
    | CHAR_LITERAL {
        char* buf = malloc(4);
        sprintf(buf, "'%c'", $1);
        $$ = (typeof($$)){ .place = buf, .type = "char" };
    }
    | STRING_LITERAL {
        char* buf = malloc(1024);
        sprintf(buf, "\"%s\"", $1);
        $$ = (typeof($$)){ .place = buf, .type = "string" };
    }
    | IDENTIFIER {
        $$ = (typeof($$)){ .place = $1, .type = (char*)getType($1) };
    }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, %s\n", yylineno, s);
}

