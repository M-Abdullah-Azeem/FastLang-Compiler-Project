/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FASTLANG_TAB_H_INCLUDED
# define YY_YY_FASTLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LITERAL = 258,             /* INT_LITERAL  */
    BOOL_LITERAL = 259,            /* BOOL_LITERAL  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    CHAR_LITERAL = 262,            /* CHAR_LITERAL  */
    INT = 263,                     /* INT  */
    BOOL = 264,                    /* BOOL  */
    STRING = 265,                  /* STRING  */
    CHAR = 266,                    /* CHAR  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    RETURN = 270,                  /* RETURN  */
    VOID = 271,                    /* VOID  */
    PRINT = 272,                   /* PRINT  */
    SCAN = 273,                    /* SCAN  */
    MAIN = 274,                    /* MAIN  */
    ASSIGN = 275,                  /* ASSIGN  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    TIMES = 278,                   /* TIMES  */
    DIVIDE = 279,                  /* DIVIDE  */
    MOD = 280,                     /* MOD  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    LE = 283,                      /* LE  */
    GE = 284,                      /* GE  */
    EQ = 285,                      /* EQ  */
    NE = 286,                      /* NE  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    SEMICOLON = 291,               /* SEMICOLON  */
    COMMA = 292,                   /* COMMA  */
    OR = 293,                      /* OR  */
    AND = 294,                     /* AND  */
    NOT = 295,                     /* NOT  */
    UMINUS = 296,                  /* UMINUS  */
    LOWER = 297,                   /* LOWER  */
    HIGHER = 298                   /* HIGHER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 89 "fastLang.y"

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

#line 121 "fastLang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FASTLANG_TAB_H_INCLUDED  */
