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
int tempCount = 1, labelCount = 1;
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

#line 128 "fastLang.tab.c"

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
  YYSYMBOL_return_type = 48,               /* return_type  */
  YYSYMBOL_base_type = 49,                 /* base_type  */
  YYSYMBOL_parameters = 50,                /* parameters  */
  YYSYMBOL_parameter_list = 51,            /* parameter_list  */
  YYSYMBOL_parameter = 52,                 /* parameter  */
  YYSYMBOL_main_function = 53,             /* main_function  */
  YYSYMBOL_compound_stmt = 54,             /* compound_stmt  */
  YYSYMBOL_VarDeclaration = 55,            /* VarDeclaration  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_idList = 57,                    /* idList  */
  YYSYMBOL_idInit = 58,                    /* idInit  */
  YYSYMBOL_stmt_list = 59,                 /* stmt_list  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_expr_stmt = 61,                 /* expr_stmt  */
  YYSYMBOL_selection_stmt = 62,            /* selection_stmt  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_M = 68,                         /* M  */
  YYSYMBOL_iteration_stmt = 69,            /* iteration_stmt  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_return_stmt = 73,               /* return_stmt  */
  YYSYMBOL_io_stmt = 74,                   /* io_stmt  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_76_10 = 76,                     /* $@10  */
  YYSYMBOL_AndExpr = 77,                   /* AndExpr  */
  YYSYMBOL_78_11 = 78,                     /* $@11  */
  YYSYMBOL_NotExpr = 79,                   /* NotExpr  */
  YYSYMBOL_RelExpr = 80,                   /* RelExpr  */
  YYSYMBOL_RelOp = 81,                     /* RelOp  */
  YYSYMBOL_E = 82,                         /* E  */
  YYSYMBOL_AddOp = 83,                     /* AddOp  */
  YYSYMBOL_T = 84,                         /* T  */
  YYSYMBOL_MultOp = 85,                    /* MultOp  */
  YYSYMBOL_U = 86,                         /* U  */
  YYSYMBOL_F = 87                          /* F  */
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
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       0,    96,    96,   100,   101,   105,   109,   110,   114,   115,
     116,   117,   121,   122,   126,   127,   131,   135,   139,   143,
     143,   146,   150,   151,   155,   158,   166,   167,   171,   171,
     171,   171,   171,   171,   174,   181,   184,   186,   181,   191,
     194,   191,   202,   206,   208,   211,   206,   219,   220,   224,
     228,   238,   238,   241,   245,   245,   247,   251,   251,   255,
     262,   266,   266,   266,   266,   266,   266,   270,   276,   280,
     280,   284,   290,   294,   294,   294,   298,   307,   311,   316,
     319,   324,   329,   332
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
  "return_type", "base_type", "parameters", "parameter_list", "parameter",
  "main_function", "compound_stmt", "VarDeclaration", "$@1", "idList",
  "idInit", "stmt_list", "statement", "expr_stmt", "selection_stmt", "$@2",
  "$@3", "$@4", "$@5", "$@6", "M", "iteration_stmt", "$@7", "$@8", "$@9",
  "return_stmt", "io_stmt", "expression", "$@10", "AndExpr", "$@11",
  "NotExpr", "RelExpr", "RelOp", "E", "AddOp", "T", "MultOp", "U", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -64,     4,    93,   -64,     7,   -64,   -64,   -64,   -64,   -64,
      23,   -64,   -64,   -11,    22,    19,   102,    25,   -64,    52,
      27,    28,   -64,   102,   -64,   -64,    25,   102,   -64,   -64,
     -64,   -64,    64,    32,    55,    36,    46,    68,    53,   -64,
       2,    57,    74,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,    13,   -64,    64,    13,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,    75,    13,   -64,    13,    48,   -28,   -64,   -64,
      65,    16,   -64,   -64,    13,    92,   -64,   -64,    78,   -64,
      83,   -64,    67,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,    26,    26,   -64,   -64,   -64,
      26,    84,    85,   -64,   -64,   -64,   -64,    13,    77,    -7,
      16,   -64,    86,    87,    13,    13,   -64,   -64,    13,   -64,
     -64,    88,    91,   -64,   -64,   -64,   -64,    13,    56,    56,
      94,   -64,   -64,   -64,   106,    56,   -64,   -64,    56,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     8,     9,    10,    11,     6,     3,
       0,     7,     2,     0,     0,     0,    13,     0,     8,     0,
       0,    12,    14,    21,    17,    16,     0,     0,    19,    27,
       5,    15,     0,     0,    24,     0,    22,     0,     0,    42,
       0,     0,     0,    18,    29,    26,    28,    30,    31,    32,
      33,     0,    20,     0,     0,    42,    43,    78,    79,    82,
      81,    80,     0,     0,    48,     0,     0,    53,    56,    58,
      60,    68,    72,    77,     0,     0,    25,    23,     0,    42,
       0,    76,     0,    57,    47,    51,    54,    69,    70,    61,
      62,    66,    65,    63,    64,     0,     0,    73,    74,    75,
       0,     0,     0,    34,    35,    42,    83,     0,     0,    59,
      67,    71,     0,     0,     0,     0,    42,    52,     0,    49,
      50,     0,     0,    44,    55,    36,    40,     0,     0,     0,
       0,    42,    41,    45,     0,     0,    37,    46,     0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -64,    20,   -64,   -64,    98,   -64,
      10,   -64,   -64,    73,   -64,   -64,   -30,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -54,   -64,   -64,   -64,   -64,   -64,
     -64,   -51,   -64,   -64,   -64,   -63,   -64,   -64,    33,   -64,
      24,   -64,    29,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    19,    20,    21,    22,    12,
      44,    29,    32,    35,    36,    33,    45,    46,    47,   114,
     128,   138,   115,   129,    56,    48,    80,   127,   135,    49,
      50,    66,   107,    67,   108,    68,    69,    95,    70,    96,
      71,   100,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    79,    83,    78,     3,    57,    58,    59,    60,    61,
      85,   -42,    82,    86,    87,    88,    57,    58,    59,    60,
      61,    15,    11,   101,    62,   104,    13,    24,    14,    57,
      58,    59,    60,    61,    63,    62,    30,    37,    64,    97,
      98,    99,    65,    28,    38,    63,    39,    40,    62,    41,
      42,   116,    17,    65,    16,   124,   117,    25,    63,    23,
      26,    37,   123,   121,   122,    27,    23,    43,    38,    34,
      39,    40,    52,    41,    42,    51,   130,   134,    57,    58,
      59,    60,    61,    53,    84,    55,    87,    88,    54,    74,
      23,    89,    90,    91,    92,    93,    94,   102,   131,   132,
     106,     4,     5,     6,     7,   137,    75,    63,   139,     8,
      18,     5,     6,     7,   103,   105,   118,   112,   113,   136,
     110,   125,   119,   120,   126,    31,    77,   133,   109,   111,
       0,    81
};

static const yytype_int16 yycheck[] =
{
      51,    55,    65,    54,     0,     3,     4,     5,     6,     7,
      38,    39,    63,    67,    21,    22,     3,     4,     5,     6,
       7,    32,     2,    74,    22,    79,    19,    17,     5,     3,
       4,     5,     6,     7,    32,    22,    26,     5,    36,    23,
      24,    25,    40,    23,    12,    32,    14,    15,    22,    17,
      18,   105,    33,    40,    32,   118,   107,     5,    32,    34,
      33,     5,   116,   114,   115,    37,    34,    35,    12,     5,
      14,    15,    36,    17,    18,    20,   127,   131,     3,     4,
       5,     6,     7,    37,    36,    32,    21,    22,    20,    32,
      34,    26,    27,    28,    29,    30,    31,     5,   128,   129,
      33,     8,     9,    10,    11,   135,    32,    32,   138,    16,
       8,     9,    10,    11,    36,    32,    39,    33,    33,    13,
      96,    33,    36,    36,    33,    27,    53,    33,    95,   100,
      -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     8,     9,    10,    11,    16,    47,
      48,    49,    53,    19,     5,    32,    32,    33,     8,    49,
      50,    51,    52,    34,    54,     5,    33,    37,    49,    55,
      54,    52,    56,    59,     5,    57,    58,     5,    12,    14,
      15,    17,    18,    35,    54,    60,    61,    62,    69,    73,
      74,    20,    36,    37,    20,    32,    68,     3,     4,     5,
       6,     7,    22,    32,    36,    40,    75,    77,    79,    80,
      82,    84,    86,    87,    32,    32,    75,    57,    75,    68,
      70,    87,    75,    79,    36,    38,    68,    21,    22,    26,
      27,    28,    29,    30,    31,    81,    83,    23,    24,    25,
      85,    75,     5,    36,    68,    32,    33,    76,    78,    82,
      84,    86,    33,    33,    63,    66,    68,    75,    39,    36,
      36,    75,    75,    68,    79,    33,    33,    71,    64,    67,
      75,    60,    60,    33,    68,    72,    13,    60,    65,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    53,    54,    56,
      55,    55,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    61,    63,    64,    65,    62,    66,
      67,    62,    68,    70,    71,    72,    69,    73,    73,    74,
      74,    76,    75,    75,    78,    77,    77,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     2,     5,     4,     0,
       4,     0,     1,     3,     1,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     4,     0,     0,     0,    13,     0,
       0,     9,     0,     0,     0,     0,    11,     3,     2,     5,
       5,     0,     4,     1,     0,     5,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     3
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
  case 6: /* return_type: VOID  */
#line 109 "fastLang.y"
           { (yyval.stringVal) = "void"; }
#line 1300 "fastLang.tab.c"
    break;

  case 8: /* base_type: INT  */
#line 114 "fastLang.y"
            { (yyval.stringVal) = "int"; }
#line 1306 "fastLang.tab.c"
    break;

  case 9: /* base_type: BOOL  */
#line 115 "fastLang.y"
            { (yyval.stringVal) = "bool"; }
#line 1312 "fastLang.tab.c"
    break;

  case 10: /* base_type: STRING  */
#line 116 "fastLang.y"
            { (yyval.stringVal) = "string"; }
#line 1318 "fastLang.tab.c"
    break;

  case 11: /* base_type: CHAR  */
#line 117 "fastLang.y"
            { (yyval.stringVal) = "char"; }
#line 1324 "fastLang.tab.c"
    break;

  case 16: /* parameter: base_type IDENTIFIER  */
#line 131 "fastLang.y"
                         { addSymbol((yyvsp[0].stringVal), (yyvsp[-1].stringVal)); }
#line 1330 "fastLang.tab.c"
    break;

  case 19: /* $@1: %empty  */
#line 143 "fastLang.y"
                   {
        strcpy(curType, (yyvsp[0].stringVal));
    }
#line 1338 "fastLang.tab.c"
    break;

  case 24: /* idInit: IDENTIFIER  */
#line 155 "fastLang.y"
               {
        addSymbol((yyvsp[0].stringVal), curType);
    }
#line 1346 "fastLang.tab.c"
    break;

  case 25: /* idInit: IDENTIFIER ASSIGN expression  */
#line 158 "fastLang.y"
                                   {
        checkType(curType, (yyvsp[0].expr).type);
        addSymbol((yyvsp[-2].stringVal), curType);
        fprintf(out, "%s := %s\n", (yyvsp[-2].stringVal), (yyvsp[0].expr).place);
    }
#line 1356 "fastLang.tab.c"
    break;

  case 34: /* expr_stmt: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 174 "fastLang.y"
                                           {
        checkType(getType((yyvsp[-3].stringVal)), (yyvsp[-1].expr).type);
        fprintf(out, "%s := %s\n", (yyvsp[-3].stringVal), (yyvsp[-1].expr).place);
    }
#line 1365 "fastLang.tab.c"
    break;

  case 35: /* $@2: %empty  */
#line 181 "fastLang.y"
                                                      {
        ltrue = (yyvsp[-1].intVal);
        lfalse = (yyvsp[0].intVal);
    }
#line 1374 "fastLang.tab.c"
    break;

  case 36: /* $@3: %empty  */
#line 184 "fastLang.y"
                             {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, (yyvsp[-4].intVal), (yyvsp[-3].intVal), (yyvsp[-4].intVal));
    }
#line 1382 "fastLang.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 186 "fastLang.y"
                                 {
        fprintf(out, "goto L%d\nL%d:\n", (yyvsp[-1].intVal), (yyvsp[-7].intVal));
    }
#line 1390 "fastLang.tab.c"
    break;

  case 38: /* selection_stmt: IF LPAREN M M $@2 expression RPAREN $@3 statement M ELSE $@4 statement  */
#line 188 "fastLang.y"
                {
        fprintf(out, "L%d:\n", (yyvsp[-3].intVal));
    }
#line 1398 "fastLang.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 191 "fastLang.y"
                                                        {
        ltrue = (yyvsp[-1].intVal);
        lfalse = (yyvsp[0].intVal);
    }
#line 1407 "fastLang.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 194 "fastLang.y"
                             {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, (yyvsp[-4].intVal), (yyvsp[-3].intVal), (yyvsp[-4].intVal));
    }
#line 1415 "fastLang.tab.c"
    break;

  case 41: /* selection_stmt: IF LPAREN M M $@5 expression RPAREN $@6 statement  */
#line 196 "fastLang.y"
                {
        fprintf(out, "L%d:\n", (yyvsp[-5].intVal));
    }
#line 1423 "fastLang.tab.c"
    break;

  case 42: /* M: %empty  */
#line 202 "fastLang.y"
    { (yyval.intVal) = labelCount++; }
#line 1429 "fastLang.tab.c"
    break;

  case 43: /* $@7: %empty  */
#line 206 "fastLang.y"
                        {
        fprintf(out, "L%d:\n", (yyvsp[0].intVal));
    }
#line 1437 "fastLang.tab.c"
    break;

  case 44: /* $@8: %empty  */
#line 208 "fastLang.y"
                                        {
        ltrue = (yyvsp[-1].intVal);
        lfalse = (yyvsp[0].intVal);
    }
#line 1446 "fastLang.tab.c"
    break;

  case 45: /* $@9: %empty  */
#line 211 "fastLang.y"
                             {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, (yyvsp[-4].intVal), (yyvsp[-3].intVal), (yyvsp[-4].intVal));
    }
#line 1454 "fastLang.tab.c"
    break;

  case 46: /* iteration_stmt: WHILE M $@7 LPAREN M M $@8 expression RPAREN $@9 statement  */
#line 213 "fastLang.y"
                {
        fprintf(out, "goto L%d\nL%d:\n", (yyvsp[-9].intVal), (yyvsp[-5].intVal));
    }
#line 1462 "fastLang.tab.c"
    break;

  case 47: /* return_stmt: RETURN expression SEMICOLON  */
#line 219 "fastLang.y"
                                { fprintf(out, "return %s\n", (yyvsp[-1].expr).place); }
#line 1468 "fastLang.tab.c"
    break;

  case 48: /* return_stmt: RETURN SEMICOLON  */
#line 220 "fastLang.y"
                       { fprintf(out, "return\n"); }
#line 1474 "fastLang.tab.c"
    break;

  case 49: /* io_stmt: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 224 "fastLang.y"
                                             {
        fprintf(out, "param %s\n", (yyvsp[-2].expr).place);
        fprintf(out, "call print, 1\n");
    }
#line 1483 "fastLang.tab.c"
    break;

  case 50: /* io_stmt: SCAN LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 228 "fastLang.y"
                                              {
        getType((yyvsp[-2].stringVal));
        fprintf(out, "param %s\n", (yyvsp[-2].stringVal));
        fprintf(out, "call scan, 1\n");
    }
#line 1493 "fastLang.tab.c"
    break;

  case 51: /* $@10: %empty  */
#line 238 "fastLang.y"
               {
        fprintf(out, "if %s goto L%d\n", (yyvsp[-1].stringVal), ltrue);
    }
#line 1501 "fastLang.tab.c"
    break;

  case 54: /* $@11: %empty  */
#line 245 "fastLang.y"
                         {
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].stringVal), (yyvsp[0].intVal), lfalse, (yyvsp[0].intVal));
    }
#line 1509 "fastLang.tab.c"
    break;

  case 59: /* RelExpr: E RelOp E  */
#line 255 "fastLang.y"
                  {
        char buf[1024]="";
        strcat(buf, (yyvsp[-2].expr).place);
        strcat(buf, (yyvsp[-1].stringVal));
        strcat(buf, (yyvsp[0].expr).place);
        (yyval.stringVal) = buf;
    }
#line 1521 "fastLang.tab.c"
    break;

  case 61: /* RelOp: LT  */
#line 266 "fastLang.y"
       {(yyval.stringVal) = "<";}
#line 1527 "fastLang.tab.c"
    break;

  case 62: /* RelOp: GT  */
#line 266 "fastLang.y"
                        {(yyval.stringVal) = ">";}
#line 1533 "fastLang.tab.c"
    break;

  case 63: /* RelOp: EQ  */
#line 266 "fastLang.y"
                                         {(yyval.stringVal) = "==";}
#line 1539 "fastLang.tab.c"
    break;

  case 64: /* RelOp: NE  */
#line 266 "fastLang.y"
                                                           {(yyval.stringVal) = "!=";}
#line 1545 "fastLang.tab.c"
    break;

  case 65: /* RelOp: GE  */
#line 266 "fastLang.y"
                                                                             {(yyval.stringVal) = ">=";}
#line 1551 "fastLang.tab.c"
    break;

  case 66: /* RelOp: LE  */
#line 266 "fastLang.y"
                                                                                               {(yyval.stringVal) = "<=";}
#line 1557 "fastLang.tab.c"
    break;

  case 67: /* E: E AddOp T  */
#line 270 "fastLang.y"
                  {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1568 "fastLang.tab.c"
    break;

  case 68: /* E: T  */
#line 276 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1574 "fastLang.tab.c"
    break;

  case 69: /* AddOp: PLUS  */
#line 280 "fastLang.y"
         {(yyval.stringVal) = "+";}
#line 1580 "fastLang.tab.c"
    break;

  case 70: /* AddOp: MINUS  */
#line 280 "fastLang.y"
                             {(yyval.stringVal) = "-";}
#line 1586 "fastLang.tab.c"
    break;

  case 71: /* T: T MultOp U  */
#line 284 "fastLang.y"
                   {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1597 "fastLang.tab.c"
    break;

  case 72: /* T: U  */
#line 290 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1603 "fastLang.tab.c"
    break;

  case 73: /* MultOp: TIMES  */
#line 294 "fastLang.y"
          {(yyval.stringVal) = "*";}
#line 1609 "fastLang.tab.c"
    break;

  case 74: /* MultOp: DIVIDE  */
#line 294 "fastLang.y"
                               {(yyval.stringVal) = "/";}
#line 1615 "fastLang.tab.c"
    break;

  case 75: /* MultOp: MOD  */
#line 294 "fastLang.y"
                                                 {(yyval.stringVal) = "%";}
#line 1621 "fastLang.tab.c"
    break;

  case 76: /* U: MINUS F  */
#line 298 "fastLang.y"
                         {
        if (strcmp((yyvsp[0].expr).type, "int") != 0) {
            fprintf(stderr, "Semantic Error at line %d: Unary minus on non-int\n", yylineno);
            exit(1);
        }
        char* t = newTemp();
        fprintf(out, "%s := -%s\n", t, (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = "int" };
    }
#line 1635 "fastLang.tab.c"
    break;

  case 77: /* U: F  */
#line 307 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1641 "fastLang.tab.c"
    break;

  case 78: /* F: INT_LITERAL  */
#line 311 "fastLang.y"
                {
        char* buf = malloc(10);
        sprintf(buf, "%d", (yyvsp[0].intVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "int" };
    }
#line 1651 "fastLang.tab.c"
    break;

  case 79: /* F: BOOL_LITERAL  */
#line 316 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].intVal) ? "true" : "false", .type = "bool" };
    }
#line 1659 "fastLang.tab.c"
    break;

  case 80: /* F: CHAR_LITERAL  */
#line 319 "fastLang.y"
                   {
        char* buf = malloc(4);
        sprintf(buf, "'%c'", (yyvsp[0].charVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "char" };
    }
#line 1669 "fastLang.tab.c"
    break;

  case 81: /* F: STRING_LITERAL  */
#line 324 "fastLang.y"
                     {
        char* buf = malloc(1024);
        sprintf(buf, "\"%s\"", (yyvsp[0].stringVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "string" };
    }
#line 1679 "fastLang.tab.c"
    break;

  case 82: /* F: IDENTIFIER  */
#line 329 "fastLang.y"
                 {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].stringVal), .type = (char*)getType((yyvsp[0].stringVal)) };
    }
#line 1687 "fastLang.tab.c"
    break;

  case 83: /* F: LPAREN expression RPAREN  */
#line 332 "fastLang.y"
                               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1693 "fastLang.tab.c"
    break;


#line 1697 "fastLang.tab.c"

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

#line 335 "fastLang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, %s\n", yylineno, s);
}

