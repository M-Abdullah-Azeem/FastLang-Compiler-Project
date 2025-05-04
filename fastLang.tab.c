/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "fastLang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lstart=-1, ltrue=-1, lfalse=-1, lend=-1;  //Variables for controlling the control structures (if-else and while).
char curType[10];
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

const char* getType(const char* name) {
    for (int i = 0; i < symCount; ++i) {
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

#line 148 "fastLang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "fastLang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_BOOL_LITERAL = 4,               /* BOOL_LITERAL  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_SCAN = 18,                      /* SCAN  */
  YYSYMBOL_MAIN = 19,                      /* MAIN  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_TIMES = 23,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 24,                    /* DIVIDE  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 34,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 35,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 36,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_UMINUS = 41,                    /* UMINUS  */
  YYSYMBOL_LOWER = 42,                     /* LOWER  */
  YYSYMBOL_HIGHER = 43,                    /* HIGHER  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_function_declarations = 46,     /* function_declarations  */
  YYSYMBOL_function_decl = 47,             /* function_decl  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_return_type = 49,               /* return_type  */
  YYSYMBOL_base_type = 50,                 /* base_type  */
  YYSYMBOL_parameters = 51,                /* parameters  */
  YYSYMBOL_parameter_list = 52,            /* parameter_list  */
  YYSYMBOL_parameter = 53,                 /* parameter  */
  YYSYMBOL_main_function = 54,             /* main_function  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_compound_stmt = 57,             /* compound_stmt  */
  YYSYMBOL_VarDeclaration = 58,            /* VarDeclaration  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_idList = 60,                    /* idList  */
  YYSYMBOL_idInit = 61,                    /* idInit  */
  YYSYMBOL_stmt_list = 62,                 /* stmt_list  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_expr_stmt = 64,                 /* expr_stmt  */
  YYSYMBOL_selection_stmt = 65,            /* selection_stmt  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_FollowIf = 68,                  /* FollowIf  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_N = 70,                         /* N  */
  YYSYMBOL_M = 71,                         /* M  */
  YYSYMBOL_iteration_stmt = 72,            /* iteration_stmt  */
  YYSYMBOL_73_8 = 73,                      /* $@8  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_return_stmt = 76,               /* return_stmt  */
  YYSYMBOL_io_stmt = 77,                   /* io_stmt  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_AndExpr = 80,                   /* AndExpr  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_NotExpr = 82,                   /* NotExpr  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_RelExpr = 84,                   /* RelExpr  */
  YYSYMBOL_RelOp = 85,                     /* RelOp  */
  YYSYMBOL_E = 86,                         /* E  */
  YYSYMBOL_AddOp = 87,                     /* AddOp  */
  YYSYMBOL_T = 88,                         /* T  */
  YYSYMBOL_MultOp = 89,                    /* MultOp  */
  YYSYMBOL_U = 90,                         /* U  */
  YYSYMBOL_F = 91,                         /* F  */
  YYSYMBOL_function_call = 92,             /* function_call  */
  YYSYMBOL_arguementList = 93,             /* arguementList  */
  YYSYMBOL_94_14 = 94                      /* $@14  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   125,   128,   132,   132,   143,   144,   148,
     149,   150,   151,   155,   156,   160,   163,   169,   175,   177,
     175,   184,   188,   188,   191,   195,   196,   200,   203,   211,
     212,   216,   216,   216,   216,   216,   216,   216,   219,   223,
     230,   235,   230,   250,   250,   255,   260,   266,   270,   272,
     275,   270,   283,   284,   288,   292,   300,   300,   308,   314,
     314,   323,   329,   329,   336,   342,   347,   353,   353,   353,
     353,   353,   353,   357,   363,   369,   369,   373,   379,   383,
     383,   383,   387,   396,   400,   405,   408,   413,   418,   421,
     422,   426,   437,   437,   441
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LITERAL",
  "BOOL_LITERAL", "IDENTIFIER", "STRING_LITERAL", "CHAR_LITERAL", "INT",
  "BOOL", "STRING", "CHAR", "IF", "ELSE", "WHILE", "RETURN", "VOID",
  "PRINT", "SCAN", "MAIN", "ASSIGN", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "MOD", "LT", "GT", "LE", "GE", "EQ", "NE", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMICOLON", "COMMA", "OR", "AND", "NOT", "UMINUS", "LOWER",
  "HIGHER", "$accept", "program", "function_declarations", "function_decl",
  "$@1", "return_type", "base_type", "parameters", "parameter_list",
  "parameter", "main_function", "$@2", "$@3", "compound_stmt",
  "VarDeclaration", "$@4", "idList", "idInit", "stmt_list", "statement",
  "expr_stmt", "selection_stmt", "$@5", "$@6", "FollowIf", "$@7", "N", "M",
  "iteration_stmt", "$@8", "$@9", "$@10", "return_stmt", "io_stmt",
  "expression", "$@11", "AndExpr", "$@12", "NotExpr", "$@13", "RelExpr",
  "RelOp", "E", "AddOp", "T", "MultOp", "U", "F", "function_call",
  "arguementList", "$@14", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,    12,   124,  -110,    -3,  -110,  -110,  -110,  -110,  -110,
      29,  -110,  -110,  -110,     6,    10,    47,    19,  -110,    42,
      27,    33,  -110,  -110,  -110,  -110,    47,    39,    39,  -110,
    -110,  -110,  -110,    82,    64,    66,  -110,     1,    71,    78,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
      14,  -110,  -110,  -110,  -110,    81,  -110,  -110,    72,    14,
    -110,  -110,    49,    -8,  -110,  -110,    98,   -14,  -110,  -110,
    -110,    14,   113,   116,    50,    54,  -110,    90,    14,  -110,
     103,    14,  -110,  -110,    84,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,    21,    21,  -110,  -110,  -110,    21,    93,
     104,   105,   119,   106,   107,  -110,  -110,  -110,   108,  -110,
    -110,    14,  -110,    28,   -14,  -110,  -110,   109,   110,    14,
    -110,   116,  -110,  -110,   111,  -110,    14,    14,  -110,  -110,
    -110,  -110,    14,  -110,  -110,  -110,  -110,   115,    14,  -110,
     117,    97,  -110,   130,    97,  -110,  -110,  -110,  -110,    97,
    -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     9,    10,    11,    12,     7,     3,
       0,     8,     2,    18,     0,     0,    14,     0,     9,     0,
       0,    13,    15,    19,    17,     5,     0,     0,     0,    16,
      30,    20,     6,     0,     0,     0,    47,     0,     0,     0,
      21,    22,    33,    31,    29,    32,    34,    35,    36,    37,
       0,    46,    48,    84,    85,    88,    87,    86,     0,     0,
      53,    62,     0,    58,    61,    64,    66,    74,    78,    83,
      90,     0,     0,     0,     0,    90,    47,     0,     0,    82,
       0,     0,    52,    56,     0,    75,    76,    67,    68,    72,
      71,    69,    70,     0,     0,    79,    80,    81,     0,    94,
       0,     0,    27,     0,    25,    38,    47,    47,     0,    89,
      63,     0,    59,    65,    73,    77,    92,     0,     0,     0,
      23,     0,    40,    47,     0,    57,     0,     0,    54,    55,
      28,    26,     0,    49,    91,    60,    93,     0,     0,    41,
       0,    24,    50,    45,    24,    47,    42,    51,    43,    24,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,  -110,    13,  -110,  -110,   123,
    -110,  -110,  -110,    53,  -110,  -110,    30,  -110,  -110,  -109,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   -62,  -110,  -110,
    -110,  -110,  -110,  -110,   -37,  -110,  -110,  -110,   -78,  -110,
    -110,  -110,    59,  -110,    60,  -110,    55,    99,   112,   -76,
    -110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,    28,    10,    41,    20,    21,    22,
      12,    15,    27,    42,    43,    73,   103,   104,    33,    44,
      45,    46,   132,   141,   146,   149,    76,    52,    47,    77,
     138,   144,    48,    49,    99,   111,    63,   126,    64,    81,
      65,    93,    66,    94,    67,    98,    68,    69,    70,   100,
     127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    84,   108,   110,    53,    54,    55,    56,    57,    95,
      96,    97,     3,    74,   106,    11,    13,    53,    54,    55,
      56,    57,    80,    58,    53,    54,    55,    56,    57,    19,
      83,   -47,   143,    59,    14,   147,    58,    60,    16,    19,
     150,    61,    17,    58,   122,   123,    59,    24,   135,    85,
      86,   136,    23,    59,    61,    18,     5,     6,     7,   -39,
      25,   133,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
      26,   -39,   -39,    30,   125,    53,    54,    55,    56,    57,
      31,    32,   130,   148,    50,    82,   105,    34,   -39,   -39,
      18,     5,     6,     7,    35,   137,    36,    37,    51,    38,
      39,   140,    34,    71,    59,    18,     5,     6,     7,    35,
      72,    36,    37,    78,    38,    39,    30,    40,   101,    85,
      86,   102,   107,   112,    87,    88,    89,    90,    91,    92,
     116,    30,     4,     5,     6,     7,   109,   117,   118,   119,
       8,   124,   120,   145,   121,   128,   129,   134,   139,    29,
     142,   131,   113,   115,   114,     0,     0,    79,     0,     0,
       0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      37,    63,    78,    81,     3,     4,     5,     6,     7,    23,
      24,    25,     0,    50,    76,     2,    19,     3,     4,     5,
       6,     7,    59,    22,     3,     4,     5,     6,     7,    16,
      38,    39,   141,    32,     5,   144,    22,    36,    32,    26,
     149,    40,    32,    22,   106,   107,    32,     5,   126,    21,
      22,   127,    33,    32,    40,     8,     9,    10,    11,     5,
      33,   123,     8,     9,    10,    11,    12,    13,    14,    15,
      37,    17,    18,    34,   111,     3,     4,     5,     6,     7,
      27,    28,   119,   145,    20,    36,    36,     5,    34,    35,
       8,     9,    10,    11,    12,   132,    14,    15,    32,    17,
      18,   138,     5,    32,    32,     8,     9,    10,    11,    12,
      32,    14,    15,    32,    17,    18,    34,    35,     5,    21,
      22,     5,    32,    39,    26,    27,    28,    29,    30,    31,
      37,    34,     8,     9,    10,    11,    33,    33,    33,    20,
      16,    33,    36,    13,    37,    36,    36,    36,    33,    26,
      33,   121,    93,    98,    94,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     8,     9,    10,    11,    16,    47,
      49,    50,    54,    19,     5,    55,    32,    32,     8,    50,
      51,    52,    53,    33,     5,    33,    37,    56,    48,    53,
      34,    57,    57,    62,     5,    12,    14,    15,    17,    18,
      35,    50,    57,    58,    63,    64,    65,    72,    76,    77,
      20,    32,    71,     3,     4,     5,     6,     7,    22,    32,
      36,    40,    78,    80,    82,    84,    86,    88,    90,    91,
      92,    32,    32,    59,    78,    92,    70,    73,    32,    91,
      78,    83,    36,    38,    71,    21,    22,    26,    27,    28,
      29,    30,    31,    85,    87,    23,    24,    25,    89,    78,
      93,     5,     5,    60,    61,    36,    71,    32,    93,    33,
      82,    79,    39,    86,    88,    90,    37,    33,    33,    20,
      36,    37,    71,    71,    33,    78,    81,    94,    36,    36,
      78,    60,    66,    71,    36,    82,    93,    78,    74,    33,
      78,    67,    33,    63,    75,    13,    68,    63,    71,    69,
      63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    48,    47,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    55,    56,
      54,    57,    59,    58,    58,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      66,    67,    65,    69,    68,    68,    70,    71,    73,    74,
      75,    72,    76,    76,    77,    77,    79,    78,    78,    81,
      80,    80,    83,    82,    82,    84,    84,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    92,    94,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     2,     0,     0,
       7,     3,     0,     4,     0,     1,     3,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     0,    11,     0,     4,     0,     0,     0,     0,     0,
       0,    11,     3,     2,     5,     5,     0,     4,     1,     0,
       5,     1,     0,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     5,     0,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* function_declarations: function_declarations function_decl  */
#line 125 "fastLang.y"
                                        {
        funcScope++;
    }
#line 1348 "fastLang.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 132 "fastLang.y"
                                                              {
        fprintf(out, "%s: //User Defined Function \n", (yyvsp[-3].stringVal));
    }
#line 1356 "fastLang.tab.c"
    break;

  case 6: /* function_decl: return_type IDENTIFIER LPAREN parameters RPAREN $@1 compound_stmt  */
#line 134 "fastLang.y"
                    {
        globalScope = 1;
        addSymbol((yyvsp[-5].stringVal), (yyvsp[-6].stringVal));
        globalScope = 0;
        paramCount = 0;
    }
#line 1367 "fastLang.tab.c"
    break;

  case 7: /* return_type: VOID  */
#line 143 "fastLang.y"
           { (yyval.stringVal) = "void"; }
#line 1373 "fastLang.tab.c"
    break;

  case 9: /* base_type: INT  */
#line 148 "fastLang.y"
            { (yyval.stringVal) = "int"; }
#line 1379 "fastLang.tab.c"
    break;

  case 10: /* base_type: BOOL  */
#line 149 "fastLang.y"
            { (yyval.stringVal) = "bool"; }
#line 1385 "fastLang.tab.c"
    break;

  case 11: /* base_type: STRING  */
#line 150 "fastLang.y"
            { (yyval.stringVal) = "string"; }
#line 1391 "fastLang.tab.c"
    break;

  case 12: /* base_type: CHAR  */
#line 151 "fastLang.y"
            { (yyval.stringVal) = "char"; }
#line 1397 "fastLang.tab.c"
    break;

  case 15: /* parameter_list: parameter  */
#line 160 "fastLang.y"
              {
        paramCount++;
    }
#line 1405 "fastLang.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA parameter  */
#line 163 "fastLang.y"
                                     {
        paramCount++;
    }
#line 1413 "fastLang.tab.c"
    break;

  case 17: /* parameter: base_type IDENTIFIER  */
#line 169 "fastLang.y"
                         { 
        addSymbol((yyvsp[0].stringVal), (yyvsp[-1].stringVal));
    }
#line 1421 "fastLang.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 175 "fastLang.y"
             {
        globalScope = 0;
    }
#line 1429 "fastLang.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 177 "fastLang.y"
                    {
        fprintf(out, "main: //Main Function \n");
        addSymbol("main", "function");
    }
#line 1438 "fastLang.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 188 "fastLang.y"
                   {
        strcpy(curType, (yyvsp[0].stringVal));
    }
#line 1446 "fastLang.tab.c"
    break;

  case 27: /* idInit: IDENTIFIER  */
#line 200 "fastLang.y"
               {
        addSymbol((yyvsp[0].stringVal), curType);
    }
#line 1454 "fastLang.tab.c"
    break;

  case 28: /* idInit: IDENTIFIER ASSIGN expression  */
#line 203 "fastLang.y"
                                   {
        checkType(curType, (yyvsp[0].expr).type);
        addSymbol((yyvsp[-2].stringVal), curType);
        fprintf(out, "%s := %s\n", (yyvsp[-2].stringVal), (yyvsp[0].expr).place);
    }
#line 1464 "fastLang.tab.c"
    break;

  case 38: /* expr_stmt: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 219 "fastLang.y"
                                           {
        checkType(getType((yyvsp[-3].stringVal)), (yyvsp[-1].expr).type);
        fprintf(out, "%s := %s\n", (yyvsp[-3].stringVal), (yyvsp[-1].expr).place);
    }
#line 1473 "fastLang.tab.c"
    break;

  case 39: /* expr_stmt: IDENTIFIER ASSIGN function_call  */
#line 223 "fastLang.y"
                                      {
        checkType(getType((yyvsp[-2].stringVal)), (yyvsp[0].expr).type);
        fprintf(out, "%s := %s\n", (yyvsp[-2].stringVal), (yyvsp[0].expr).place);
    }
#line 1482 "fastLang.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 230 "fastLang.y"
                                                  {
        if(ltrue != -1) (yyvsp[-2].ListVal).ltrue = ltrue;
        if(lfalse != -1) (yyvsp[-2].ListVal).lfalse = lfalse;
        ltrue = (yyvsp[-1].intVal);
        lfalse = (yyvsp[0].intVal);
    }
#line 1493 "fastLang.tab.c"
    break;

  case 41: /* $@6: %empty  */
#line 235 "fastLang.y"
                             {
        checkType((yyvsp[-1].expr).type, "bool");
        if(notCheck == 0)
            fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, (yyvsp[-4].intVal), (yyvsp[-3].intVal), (yyvsp[-4].intVal));
        else {
            fprintf(out, "if %s goto L%d\n", (yyvsp[-1].expr).place, (yyvsp[-3].intVal));
            notCheck = 0;
        }
    }
#line 1507 "fastLang.tab.c"
    break;

  case 42: /* selection_stmt: IF LPAREN N M M $@5 expression RPAREN $@6 statement FollowIf  */
#line 243 "fastLang.y"
                         {
        if((yyvsp[-8].ListVal).ltrue != -1) ltrue = (yyvsp[-8].ListVal).ltrue;
        if((yyvsp[-8].ListVal).lfalse != -1) lfalse = (yyvsp[-8].ListVal).lfalse;
    }
#line 1516 "fastLang.tab.c"
    break;

  case 43: /* $@7: %empty  */
#line 250 "fastLang.y"
                     {
        fprintf(out, "goto L%d\nL%d:\n", (yyvsp[0].intVal), lfalse);
    }
#line 1524 "fastLang.tab.c"
    break;

  case 44: /* FollowIf: ELSE M $@7 statement  */
#line 252 "fastLang.y"
                {
        fprintf(out, "L%d:\n", (yyvsp[-2].intVal));
    }
#line 1532 "fastLang.tab.c"
    break;

  case 45: /* FollowIf: %empty  */
#line 255 "fastLang.y"
      {
        fprintf(out, "L%d:\n", lfalse);
    }
#line 1540 "fastLang.tab.c"
    break;

  case 46: /* N: %empty  */
#line 260 "fastLang.y"
    {
        (yyval.ListVal).ltrue = -1;
        (yyval.ListVal).lfalse = -1;
    }
#line 1549 "fastLang.tab.c"
    break;

  case 47: /* M: %empty  */
#line 266 "fastLang.y"
    { (yyval.intVal) = labelCount++; }
#line 1555 "fastLang.tab.c"
    break;

  case 48: /* $@8: %empty  */
#line 270 "fastLang.y"
                        {
        fprintf(out, "L%d:\n", (yyvsp[0].intVal));
    }
#line 1563 "fastLang.tab.c"
    break;

  case 49: /* $@9: %empty  */
#line 272 "fastLang.y"
                                        {
        ltrue = (yyvsp[-1].intVal);
        lfalse = (yyvsp[0].intVal);
    }
#line 1572 "fastLang.tab.c"
    break;

  case 50: /* $@10: %empty  */
#line 275 "fastLang.y"
                             {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, (yyvsp[-4].intVal), (yyvsp[-3].intVal), (yyvsp[-4].intVal));
    }
#line 1580 "fastLang.tab.c"
    break;

  case 51: /* iteration_stmt: WHILE M $@8 LPAREN M M $@9 expression RPAREN $@10 statement  */
#line 277 "fastLang.y"
                {
        fprintf(out, "goto L%d\nL%d:\n", (yyvsp[-9].intVal), (yyvsp[-5].intVal));
    }
#line 1588 "fastLang.tab.c"
    break;

  case 52: /* return_stmt: RETURN expression SEMICOLON  */
#line 283 "fastLang.y"
                                { fprintf(out, "return %s\n", (yyvsp[-1].expr).place); }
#line 1594 "fastLang.tab.c"
    break;

  case 53: /* return_stmt: RETURN SEMICOLON  */
#line 284 "fastLang.y"
                       { fprintf(out, "return\n"); }
#line 1600 "fastLang.tab.c"
    break;

  case 54: /* io_stmt: PRINT LPAREN arguementList RPAREN SEMICOLON  */
#line 288 "fastLang.y"
                                                {
        fprintf(out, "Call print, %d\n", argCount);
        argCount = 0;
    }
#line 1609 "fastLang.tab.c"
    break;

  case 55: /* io_stmt: SCAN LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 292 "fastLang.y"
                                              {
        getType((yyvsp[-2].stringVal));
        fprintf(out, "param %s\n", (yyvsp[-2].stringVal));
        fprintf(out, "call scan, 1\n");
    }
#line 1619 "fastLang.tab.c"
    break;

  case 56: /* $@11: %empty  */
#line 300 "fastLang.y"
                    {
        if(notCheck != -1) {
            fprintf(out, "if %s goto L%d\n", (yyvsp[-1].expr).place, ltrue);
        }
        notCheck = 0;
    }
#line 1630 "fastLang.tab.c"
    break;

  case 57: /* expression: AndExpr OR $@11 expression  */
#line 305 "fastLang.y"
                       {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1638 "fastLang.tab.c"
    break;

  case 58: /* expression: AndExpr  */
#line 308 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1646 "fastLang.tab.c"
    break;

  case 59: /* $@12: %empty  */
#line 314 "fastLang.y"
                                  {
        checkType((yyvsp[-2].expr).type, "bool");
        if(notCheck != -1) {
            fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-2].expr).place, (yyvsp[-1].intVal), lfalse, (yyvsp[-1].intVal));
        }
        notCheck = 0;
    }
#line 1658 "fastLang.tab.c"
    break;

  case 60: /* AndExpr: AndExpr M AND $@12 NotExpr  */
#line 320 "fastLang.y"
                     {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1666 "fastLang.tab.c"
    break;

  case 61: /* AndExpr: NotExpr  */
#line 323 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1674 "fastLang.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 329 "fastLang.y"
        {
        notCheck = 1 - notCheck;
    }
#line 1682 "fastLang.tab.c"
    break;

  case 63: /* NotExpr: NOT $@13 NotExpr  */
#line 331 "fastLang.y"
                   {
        fprintf(out, "if %s goto L%d\n", (yyvsp[0].expr).place, lfalse);
        notCheck = -1;
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1692 "fastLang.tab.c"
    break;

  case 64: /* NotExpr: RelExpr  */
#line 336 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1700 "fastLang.tab.c"
    break;

  case 65: /* RelExpr: E RelOp E  */
#line 342 "fastLang.y"
                  {
        char buf[1024];
        sprintf(buf, "%s %s %s", (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "bool" };
    }
#line 1710 "fastLang.tab.c"
    break;

  case 66: /* RelExpr: E  */
#line 347 "fastLang.y"
             {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1718 "fastLang.tab.c"
    break;

  case 67: /* RelOp: LT  */
#line 353 "fastLang.y"
       {(yyval.stringVal) = "<";}
#line 1724 "fastLang.tab.c"
    break;

  case 68: /* RelOp: GT  */
#line 353 "fastLang.y"
                        {(yyval.stringVal) = ">";}
#line 1730 "fastLang.tab.c"
    break;

  case 69: /* RelOp: EQ  */
#line 353 "fastLang.y"
                                         {(yyval.stringVal) = "==";}
#line 1736 "fastLang.tab.c"
    break;

  case 70: /* RelOp: NE  */
#line 353 "fastLang.y"
                                                           {(yyval.stringVal) = "!=";}
#line 1742 "fastLang.tab.c"
    break;

  case 71: /* RelOp: GE  */
#line 353 "fastLang.y"
                                                                             {(yyval.stringVal) = ">=";}
#line 1748 "fastLang.tab.c"
    break;

  case 72: /* RelOp: LE  */
#line 353 "fastLang.y"
                                                                                               {(yyval.stringVal) = "<=";}
#line 1754 "fastLang.tab.c"
    break;

  case 73: /* E: E AddOp T  */
#line 357 "fastLang.y"
                  {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1765 "fastLang.tab.c"
    break;

  case 74: /* E: T  */
#line 363 "fastLang.y"
        { 
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].expr).place, .type = (yyvsp[0].expr).type };
    }
#line 1773 "fastLang.tab.c"
    break;

  case 75: /* AddOp: PLUS  */
#line 369 "fastLang.y"
         {(yyval.stringVal) = "+";}
#line 1779 "fastLang.tab.c"
    break;

  case 76: /* AddOp: MINUS  */
#line 369 "fastLang.y"
                             {(yyval.stringVal) = "-";}
#line 1785 "fastLang.tab.c"
    break;

  case 77: /* T: T MultOp U  */
#line 373 "fastLang.y"
                   {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1796 "fastLang.tab.c"
    break;

  case 78: /* T: U  */
#line 379 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1802 "fastLang.tab.c"
    break;

  case 79: /* MultOp: TIMES  */
#line 383 "fastLang.y"
          {(yyval.stringVal) = "*";}
#line 1808 "fastLang.tab.c"
    break;

  case 80: /* MultOp: DIVIDE  */
#line 383 "fastLang.y"
                               {(yyval.stringVal) = "/";}
#line 1814 "fastLang.tab.c"
    break;

  case 81: /* MultOp: MOD  */
#line 383 "fastLang.y"
                                                 {(yyval.stringVal) = "%";}
#line 1820 "fastLang.tab.c"
    break;

  case 82: /* U: MINUS F  */
#line 387 "fastLang.y"
                         {
        if (strcmp((yyvsp[0].expr).type, "int") != 0) {
            fprintf(stderr, "Semantic Error at line %d: Unary minus on non-int\n", yylineno);
            exit(1);
        }
        char* t = newTemp();
        fprintf(out, "%s := -%s\n", t, (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = "int" };
    }
#line 1834 "fastLang.tab.c"
    break;

  case 83: /* U: F  */
#line 396 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1840 "fastLang.tab.c"
    break;

  case 84: /* F: INT_LITERAL  */
#line 400 "fastLang.y"
                {
        char* buf = malloc(10);
        sprintf(buf, "%d", (yyvsp[0].intVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "int" };
    }
#line 1850 "fastLang.tab.c"
    break;

  case 85: /* F: BOOL_LITERAL  */
#line 405 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].intVal) ? "true" : "false", .type = "bool" };
    }
#line 1858 "fastLang.tab.c"
    break;

  case 86: /* F: CHAR_LITERAL  */
#line 408 "fastLang.y"
                   {
        char* buf = malloc(4);
        sprintf(buf, "'%c'", (yyvsp[0].charVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "char" };
    }
#line 1868 "fastLang.tab.c"
    break;

  case 87: /* F: STRING_LITERAL  */
#line 413 "fastLang.y"
                     {
        char* buf = malloc(1024);
        sprintf(buf, "\"%s\"", (yyvsp[0].stringVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "string" };
    }
#line 1878 "fastLang.tab.c"
    break;

  case 88: /* F: IDENTIFIER  */
#line 418 "fastLang.y"
                 {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].stringVal), .type = (char*)getType((yyvsp[0].stringVal)) };
    }
#line 1886 "fastLang.tab.c"
    break;

  case 89: /* F: LPAREN expression RPAREN  */
#line 421 "fastLang.y"
                               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1892 "fastLang.tab.c"
    break;

  case 90: /* F: function_call  */
#line 422 "fastLang.y"
                    {(yyval.expr)=(yyvsp[0].expr);}
#line 1898 "fastLang.tab.c"
    break;

  case 91: /* function_call: IDENTIFIER LPAREN arguementList RPAREN SEMICOLON  */
#line 426 "fastLang.y"
                                                     {
        char buf[20] = "";
        checkArgCount((yyvsp[-4].stringVal), argCount);
        fprintf(out, "Call %s, %d\n", (yyvsp[-4].stringVal), argCount);
        argCount = 0;
        
        (yyval.expr) = (typeof((yyval.expr))){ .place = "return_value", .type = (char*)getType((yyvsp[-4].stringVal)) };
    }
#line 1911 "fastLang.tab.c"
    break;

  case 92: /* $@14: %empty  */
#line 437 "fastLang.y"
                     {
        argCount++;
        fprintf(out, "param %s\n", (yyvsp[-1].expr).place);
    }
#line 1920 "fastLang.tab.c"
    break;

  case 94: /* arguementList: expression  */
#line 441 "fastLang.y"
                 {
        argCount++;
        fprintf(out, "param %s\n", (yyvsp[0].expr).place);
    }
#line 1929 "fastLang.tab.c"
    break;


#line 1933 "fastLang.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 446 "fastLang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, %s\n", yylineno, s);
}

