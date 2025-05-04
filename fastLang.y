// === FILE: fastlang.y (Bison parser with Semantic Analyzer — no $-N references) ===
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lstart=-1, ltrue=-1, lfalse=-1, lend=-1;  //Variables for controlling the control structures (if-else and while).
char curType[10], typeChecker[10];
int tempCount = 1, labelCount = 1, argCount = 0, paramCount = 0, globalScope = 0, funcScope = 1, notCheck = 0;
extern int yylineno;
FILE *out;

// Symbol table entry
typedef struct {
    char name[64];
    char type[10];
    int argc;
    int scope;
} Symbol;

Symbol symtab[100];
int symCount = 0;

char* newTemp() {
    char* buf = malloc(10);
    sprintf(buf, "t%d", tempCount++);
    return buf;
}

void checkReturnType(const char* lhs, const char* rhs) {
    if(lhs == rhs){
        fprintf(stderr, "Semantic Error at line %d: Must return a value of type (%s)\n", yylineno, lhs);
        exit(1);
    }
}
void addSymbol(const char* name, const char* type) {
    for (int i = 0; i < symCount; ++i) {
        if (strcmp(symtab[i].name, name) == 0 && (symtab[i].scope == funcScope || symtab[i].scope == 0)) {
            fprintf(stderr, "Semantic Error at line %d: Redeclaration of variable '%s'\n", yylineno, name);
            exit(1);
        }
    }
    strcpy(symtab[symCount].name, name);
    strcpy(symtab[symCount].type, type);
    symtab[symCount].argc = paramCount;
    if(globalScope == 1)
        symtab[symCount].scope = 0;
    else
        symtab[symCount].scope = funcScope;
    symCount++;
}
void checkCompatibility(const char* lhs, const char* rhs) {
    if (strcmp(lhs, rhs) != 0) {
        fprintf(stderr, "Semantic Error at line %d: Arithmetic Operations are only compatible with type int\n", yylineno);
        exit(1);
    }
}

const char* getType(const char* name) {
    for (int i = 0; i < symCount; ++i)  {
        if (strcmp(symtab[i].name, name) == 0 && (symtab[i].scope == funcScope || symtab[i].scope == 0)) return symtab[i].type;
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

void checkArgCount(const char* name, int c) {
    for (int i = 0; i < symCount; ++i) {
        if (strcmp(symtab[i].name, name) == 0) {
            if(symtab[i].argc != c) {
                fprintf(stderr, "Semantic Error at line %d: Function (%s) Expected Arguement Count: %d, Recieved: %d\n", yylineno, name, symtab[i].argc, c);
                exit(1);
            }
            else {
                printf("%s %d\n", name, symtab[i].scope);            }
        }
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
    struct {
        int ltrue;
        int lfalse;
    } ListVal;
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

%type <stringVal> return_stmt compound_stmt base_type idInit return_type AddOp MultOp RelOp 
%type <expr> expression E T U F function_call RelExpr AndExpr NotExpr
%type <intVal> M
%type <ListVal> N selection_stmt

%nonassoc LOWER
%nonassoc HIGHER

%%
program:
    function_declarations main_function
    ;

function_declarations:
    function_declarations function_decl {
        funcScope++;
    }
    |
    ;

function_decl:
    return_type[type] IDENTIFIER[id] LPAREN parameters RPAREN {
        strcpy(typeChecker, $type);
        fprintf(out, "%s: //User Defined Function \n", $2);
    } compound_stmt[type2] {
        checkReturnType($type, $type2);
        globalScope = 1;
        addSymbol($id, typeChecker);
        globalScope = 0;
        paramCount = 0;
    }
    ;

return_type:
    VOID   { $$ = "void"; }
    | base_type[type] {
        $$=$type;
    }
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
    parameter {
        paramCount++;
    }
    | parameter_list COMMA parameter {
        paramCount++;
    }
    ;

parameter:
    base_type IDENTIFIER { 
        addSymbol($2, $1);
    }
    ;

main_function:
    INT MAIN {
        globalScope = 0;
    } LPAREN RPAREN {
        fprintf(out, "main: //Main Function \n");
        addSymbol("main", "function");
    } compound_stmt
    ;

compound_stmt:
    LBRACE stmt_list return_stmt[type] RBRACE {
        $$=$type;
    }
    | LBRACE stmt_list RBRACE
    ;

VarDeclaration:
    base_type[ret] {
        strcpy(curType, $ret);
    } idList SEMICOLON
    |
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
    | 
    ;

statement:
    VarDeclaration |expr_stmt | compound_stmt | selection_stmt | iteration_stmt | io_stmt;

expr_stmt:
    IDENTIFIER ASSIGN expression SEMICOLON {
        checkType(getType($1), $3.type);
        fprintf(out, "%s := %s\n", $1, $3.place);
    }
    | IDENTIFIER ASSIGN function_call {
        checkType(getType($1), $3.type);
        fprintf(out, "%s := %s\n", $1, $3.place);
    }
    ;

selection_stmt:
    IF LPAREN N[lList] M[trueLabel] M[falseLabel] {
        if(ltrue != -1) $lList.ltrue = ltrue;
        if(lfalse != -1) $lList.lfalse = lfalse;
        ltrue = $trueLabel;
        lfalse = $falseLabel;
    } expression[exp] RPAREN {
        checkType($exp.type, "bool");
        if(notCheck == 0)
            fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", $exp.place, $trueLabel, $falseLabel, $trueLabel);
        else {
            fprintf(out, "if %s goto L%d\n", $exp.place, $falseLabel);
            notCheck = 0;
        }
    } statement FollowIf {
        if($lList.ltrue != -1) ltrue = $lList.ltrue;
        if($lList.lfalse != -1) lfalse = $lList.lfalse;
    }
    ;

FollowIf:
    ELSE M[endLabel] {
        fprintf(out, "goto L%d\nL%d:\n", $endLabel, lfalse);
    } statement {
        fprintf(out, "L%d:\n", $endLabel);
    }
    | {
        fprintf(out, "L%d:\n", lfalse);
    }

N: 
    {
        $$.ltrue = -1;
        $$.lfalse = -1;
    }

M:
    { $$ = labelCount++; }
    ;

iteration_stmt:
    WHILE M[startLabel] {
        fprintf(out, "L%d:\n", $startLabel);
    } LPAREN M[trueLabel] M[falseLabel] {
        ltrue = $trueLabel;
        lfalse = $falseLabel;
    } expression[exp] RPAREN {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", $exp.place, $trueLabel, $falseLabel, $trueLabel);
    } statement {
        fprintf(out, "goto L%d\nL%d:\n", $startLabel, $falseLabel);
    }
    ;

return_stmt:
    RETURN expression[exp] SEMICOLON {
        fprintf(out, "return %s\n", $2.place);
        $$ = $exp.type;
        }
    | RETURN SEMICOLON {
        fprintf(out, "return\n");
        $$ = "void";
    }
    ;

io_stmt:
    PRINT LPAREN arguementList RPAREN SEMICOLON {
        fprintf(out, "Call print, %d\n", argCount);
        argCount = 0;
    }
    | SCAN LPAREN IDENTIFIER RPAREN SEMICOLON {
        getType($3);
        fprintf(out, "param %s\n", $3);
        fprintf(out, "call scan, 1\n");
    }
    ;

expression:
    AndExpr[exp] OR {
        if(notCheck != -1) {
            fprintf(out, "if %s goto L%d\n", $exp.place, ltrue);
        }
        notCheck = 0;
    } expression[exp2] {
        $$ = (typeof($$)){ .place = $exp2.place, .type = $exp2.type };
    }
    | AndExpr[exp] {
        $$ = (typeof($$)){ .place = $exp.place, .type = $exp.type };
    }
    ;

AndExpr:
    AndExpr[exp] M[trueLabel] AND {
        checkType($exp.type, "bool");
        if(notCheck != -1) {
            fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", $exp.place, $trueLabel, lfalse, $trueLabel);
        }
        notCheck = 0;
    }  NotExpr[exp2] {
        $$ = (typeof($$)){ .place = $exp2.place, .type = $exp2.type };
    }
    | NotExpr[exp] {
        $$ = (typeof($$)){ .place = $exp.place, .type = $exp.type };
    }
    ;

NotExpr:
    NOT {
        notCheck = 1 - notCheck;
    } NotExpr[exp] {
        fprintf(out, "if %s goto L%d\n", $exp.place, lfalse);
        notCheck = -1;
        $$ = (typeof($$)){ .place = $exp.place, .type = $exp.type };
    }
    | RelExpr[exp] {
        $$ = (typeof($$)){ .place = $exp.place, .type = $exp.type };
    }
    ;

RelExpr:
    E RelOp[op] E {
        char buf[1024];
        sprintf(buf, "%s %s %s", $1.place, $op, $3.place);
        $$ = (typeof($$)){ .place = buf, .type = "bool" };
    }
    | E[exp] {
        $$ = (typeof($$)){ .place = $exp.place, .type = $exp.type };
    }
    ;

RelOp[op]:
    LT {$$ = "<";} | GT {$$ = ">";} | EQ {$$ = "==";} | NE {$$ = "!=";} | GE {$$ = ">=";} | LE {$$ = "<=";}
    ;

E:
    E AddOp[op] T {
        checkType($1.type, $3.type);
        checkCompatibility($1.type, "int");
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, $1.place, $op, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | T { 
        $$ = (typeof($$)){ .place = $1.place, .type = $1.type };
    }
    ;

AddOp[op]:
    PLUS {$$ = "+";} | MINUS {$$ = "-";}
    ;

T:
    T MultOp[op] U {
        checkType($1.type, $3.type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, $1.place, $op, $3.place);
        $$ = (typeof($$)){ .place = t, .type = $1.type };
    }
    | U { $$ = $1; }
    ;

MultOp[op]:
    TIMES {$$ = "*";} | DIVIDE {$$ = "/";} | MOD {$$ = "%";}
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
        sprintf(buf, "%s", $1);
        $$ = (typeof($$)){ .place = buf, .type = "string" };
    }
    | IDENTIFIER {
        $$ = (typeof($$)){ .place = $1, .type = (char*)getType($1) };
    }
    | LPAREN expression RPAREN { $$ = $2; }
    | function_call {$$=$1;}
    ;

function_call:
    IDENTIFIER LPAREN arguementList RPAREN SEMICOLON {
        char buf[20] = "";
        checkArgCount($1, argCount);
        fprintf(out, "Call %s, %d\n", $1, argCount);
        argCount = 0;
        
        $$ = (typeof($$)){ .place = "return_value", .type = (char*)getType($1) };
    }
    ;

arguementList:
    expression COMMA {
        argCount++;
        fprintf(out, "param %s\n", $1.place);
    } arguementList 
    | expression {
        argCount++;
        fprintf(out, "param %s\n", $1.place);
    }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, %s\n", yylineno, s);
}

