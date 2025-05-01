%{
#include "fastLang.tab.h"
#include <stdio.h>
#include <string.h>

extern int yylineno;
void yyerror(const char *s);
%}

/* Regex Patterns */
DIGIT       [0-9]
ID          [A-Za-z][A-Za-z0-9_]*
STRING      \"([^\\\"]|\\.)*\"
CHAR        \'([^\\\']|\\.)\'

%%

"int"            { return INT; }
"bool"           { return BOOL; }
"string"         { return STRING; }
"char"           { return CHAR; }
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"return"         { return RETURN; }
"true"           { yylval.intVal = 1; return BOOL_LITERAL; }
"false"          { yylval.intVal = 0; return BOOL_LITERAL; }
"and"            { return AND; }
"or"             { return OR; }
"not"            { return NOT; }
"void"           { return VOID; }
"print"          { return PRINT; }
"scan"           { return SCAN; }
"main"           { return MAIN; }

{DIGIT}+         { yylval.intVal = atoi(yytext); return INT_LITERAL; }
{ID}             { yylval.stringVal = strdup(yytext); return IDENTIFIER; }
{STRING}         { yylval.stringVal = strdup(yytext); return STRING_LITERAL; }
{CHAR}           { yylval.charVal = yytext[1]; return CHAR_LITERAL; }

":="             { return ASSIGN; }
"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return TIMES; }
"/"              { return DIVIDE; }
"%"              { return MOD; }
"<"              { return LT; }
">"              { return GT; }
"<="             { return LE; }
">="             { return GE; }
"=="             { return EQ; }
"!="             { return NE; }

";"              { return SEMICOLON; }
","              { return COMMA; }
"("              { return LPAREN; }
")"              { return RPAREN; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }

"//".*           ; // Ignore single-line comments
"/"([^]|\+[^/])\+"/"    ; // Ignore multi-line comments

\n       {yylineno++;}
[ \t\r]+       ;  // Ignore whitespace

.                { printf("Unknown character '%s' at line %d\n", yytext, yylineno); }

%%

int yywrap() { return 1; }