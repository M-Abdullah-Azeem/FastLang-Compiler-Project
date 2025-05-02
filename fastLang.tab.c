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

int lstart, ltrue, lfalse, lend;  //Variables for controlling the control structures (if-else and while).
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
  YYSYMBOL_LOWER_THAN_ELSE = 38,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_function_declarations = 45,     /* function_declarations  */
  YYSYMBOL_function_decl = 46,             /* function_decl  */
  YYSYMBOL_return_type = 47,               /* return_type  */
  YYSYMBOL_base_type = 48,                 /* base_type  */
  YYSYMBOL_parameters = 49,                /* parameters  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_parameter = 51,                 /* parameter  */
  YYSYMBOL_main_function = 52,             /* main_function  */
  YYSYMBOL_compound_stmt = 53,             /* compound_stmt  */
  YYSYMBOL_VarDeclaration = 54,            /* VarDeclaration  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_idList = 56,                    /* idList  */
  YYSYMBOL_idInit = 57,                    /* idInit  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_expr_stmt = 60,                 /* expr_stmt  */
  YYSYMBOL_selection_stmt = 61,            /* selection_stmt  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_FollowIf = 63,                  /* FollowIf  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_iteration_stmt = 65,            /* iteration_stmt  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_return_stmt = 67,               /* return_stmt  */
  YYSYMBOL_io_stmt = 68,                   /* io_stmt  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_AndExpr = 70,                   /* AndExpr  */
  YYSYMBOL_NotExpr = 71,                   /* NotExpr  */
  YYSYMBOL_RelExpr = 72,                   /* RelExpr  */
  YYSYMBOL_RelOp = 73,                     /* RelOp  */
  YYSYMBOL_E = 74,                         /* E  */
  YYSYMBOL_AddOp = 75,                     /* AddOp  */
  YYSYMBOL_T = 76,                         /* T  */
  YYSYMBOL_MultOp = 77,                    /* MultOp  */
  YYSYMBOL_U = 78,                         /* U  */
  YYSYMBOL_F = 79                          /* F  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    98,    99,   103,   107,   108,   112,   113,
     114,   115,   119,   120,   124,   125,   129,   133,   137,   141,
     141,   144,   148,   149,   153,   156,   164,   165,   169,   169,
     169,   169,   169,   169,   172,   179,   179,   187,   190,   190,
     198,   198,   209,   210,   214,   218,   228,   228,   232,   232,
     236,   236,   240,   247,   251,   251,   251,   251,   251,   251,
     255,   261,   265,   265,   269,   275,   279,   279,   279,   283,
     292,   296,   301,   304,   309,   314,   317
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
  "RBRACE", "SEMICOLON", "COMMA", "LOWER_THAN_ELSE", "OR", "AND", "NOT",
  "UMINUS", "$accept", "program", "function_declarations", "function_decl",
  "return_type", "base_type", "parameters", "parameter_list", "parameter",
  "main_function", "compound_stmt", "VarDeclaration", "$@1", "idList",
  "idInit", "stmt_list", "statement", "expr_stmt", "selection_stmt", "$@2",
  "FollowIf", "$@3", "iteration_stmt", "$@4", "return_stmt", "io_stmt",
  "expression", "AndExpr", "NotExpr", "RelExpr", "RelOp", "E", "AddOp",
  "T", "MultOp", "U", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -27,    22,    74,   -27,    17,   -27,   -27,   -27,   -27,   -27,
      30,   -27,   -27,     5,    32,    36,    91,    31,   -27,    45,
      41,    66,   -27,    91,   -27,   -27,    31,    91,   -27,   -27,
     -27,   -27,    99,    13,    85,    71,    69,    88,    77,    78,
      -3,    79,    80,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,     2,   -27,    99,     2,     2,     2,   -27,   -27,   -27,
     -27,   -27,    55,     2,   -27,     2,   -13,    73,   -27,   -27,
      50,    70,   -27,   -27,     2,   109,    76,   -27,    16,     6,
       7,   -27,    58,   -27,   -27,     2,     2,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,    10,    10,   -27,   -27,   -27,
      10,    59,    83,   -27,   -27,   -27,   -27,    73,   -27,   -11,
      70,   -27,    81,    82,    39,    39,   -27,   -27,   106,   -27,
     -27,   -27,    39,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     8,     9,    10,    11,     6,     3,
       0,     7,     2,     0,     0,     0,    13,     0,     8,     0,
       0,    12,    14,    21,    17,    16,     0,     0,    19,    27,
       5,    15,     0,     0,    24,     0,    22,     0,     0,     0,
       0,     0,     0,    18,    29,    26,    28,    30,    31,    32,
      33,     0,    20,     0,     0,     0,     0,    71,    72,    75,
      74,    73,     0,     0,    43,     0,     0,    47,    49,    51,
      53,    61,    65,    70,     0,     0,    25,    23,     0,     0,
       0,    69,     0,    50,    42,     0,     0,    62,    63,    54,
      55,    59,    58,    56,    57,     0,     0,    66,    67,    68,
       0,     0,     0,    34,    35,    40,    76,    46,    48,    52,
      60,    64,     0,     0,     0,     0,    44,    45,    37,    36,
      41,    38,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -27,   -27,    18,   -27,   -27,    93,   -27,
      -5,   -27,   -27,    68,   -27,   -27,   -26,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,    12,    37,   -16,   -27,
     -27,    28,   -27,    29,   -27,    24,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    19,    20,    21,    22,    12,
      44,    29,    32,    35,    36,    33,    45,    46,    47,   114,
     119,   122,    48,   115,    49,    50,    66,    67,    68,    69,
      95,    70,    96,    71,   100,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    58,    59,    60,    61,    57,    58,    59,    60,    61,
      87,    88,    24,    57,    58,    59,    60,    61,    37,    62,
      11,    30,     3,    84,    62,    38,    85,    39,    40,    63,
      41,    42,    62,    64,    63,    14,    13,    15,    65,   104,
     105,    28,    63,    65,    37,    85,    85,    23,    43,    83,
      25,    38,   103,    39,    40,    85,    41,    42,    57,    58,
      59,    60,    61,    76,    16,    23,    78,    79,    80,    17,
     108,    87,    88,    23,    26,    82,    89,    90,    91,    92,
      93,    94,     4,     5,     6,     7,   101,    63,   118,   120,
       8,   106,   112,    97,    98,    99,   123,    85,    85,    18,
       5,     6,     7,    27,    34,    51,    53,    52,    54,    55,
      56,    74,    75,    86,   102,    85,   113,   116,   117,   121,
      31,    77,   107,   109,   111,   110,    81
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      21,    22,    17,     3,     4,     5,     6,     7,     5,    22,
       2,    26,     0,    36,    22,    12,    39,    14,    15,    32,
      17,    18,    22,    36,    32,     5,    19,    32,    41,    33,
      33,    23,    32,    41,     5,    39,    39,    34,    35,    65,
       5,    12,    36,    14,    15,    39,    17,    18,     3,     4,
       5,     6,     7,    51,    32,    34,    54,    55,    56,    33,
      86,    21,    22,    34,    33,    63,    26,    27,    28,    29,
      30,    31,     8,     9,    10,    11,    74,    32,   114,   115,
      16,    33,    33,    23,    24,    25,   122,    39,    39,     8,
       9,    10,    11,    37,     5,    20,    37,    36,    20,    32,
      32,    32,    32,    40,     5,    39,    33,    36,    36,    13,
      27,    53,    85,    95,   100,    96,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     8,     9,    10,    11,    16,    46,
      47,    48,    52,    19,     5,    32,    32,    33,     8,    48,
      49,    50,    51,    34,    53,     5,    33,    37,    48,    54,
      53,    51,    55,    58,     5,    56,    57,     5,    12,    14,
      15,    17,    18,    35,    53,    59,    60,    61,    65,    67,
      68,    20,    36,    37,    20,    32,    32,     3,     4,     5,
       6,     7,    22,    32,    36,    41,    69,    70,    71,    72,
      74,    76,    78,    79,    32,    32,    69,    56,    69,    69,
      69,    79,    69,    71,    36,    39,    40,    21,    22,    26,
      27,    28,    29,    30,    31,    73,    75,    23,    24,    25,
      77,    69,     5,    36,    33,    33,    33,    70,    71,    74,
      76,    78,    33,    33,    62,    66,    36,    36,    59,    63,
      59,    13,    64,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    50,    50,    51,    52,    53,    55,
      54,    54,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    62,    61,    63,    64,    63,
      66,    65,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     2,     5,     4,     0,
       4,     0,     1,     3,     1,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     4,     0,     6,     1,     0,     4,
       0,     6,     3,     2,     5,     5,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     3
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
#line 107 "fastLang.y"
           { (yyval.stringVal) = "void"; }
#line 1282 "fastLang.tab.c"
    break;

  case 8: /* base_type: INT  */
#line 112 "fastLang.y"
            { (yyval.stringVal) = "int"; }
#line 1288 "fastLang.tab.c"
    break;

  case 9: /* base_type: BOOL  */
#line 113 "fastLang.y"
            { (yyval.stringVal) = "bool"; }
#line 1294 "fastLang.tab.c"
    break;

  case 10: /* base_type: STRING  */
#line 114 "fastLang.y"
            { (yyval.stringVal) = "string"; }
#line 1300 "fastLang.tab.c"
    break;

  case 11: /* base_type: CHAR  */
#line 115 "fastLang.y"
            { (yyval.stringVal) = "char"; }
#line 1306 "fastLang.tab.c"
    break;

  case 16: /* parameter: base_type IDENTIFIER  */
#line 129 "fastLang.y"
                         { addSymbol((yyvsp[0].stringVal), (yyvsp[-1].stringVal)); }
#line 1312 "fastLang.tab.c"
    break;

  case 19: /* $@1: %empty  */
#line 141 "fastLang.y"
                   {
        strcpy(curType, (yyvsp[0].stringVal));
    }
#line 1320 "fastLang.tab.c"
    break;

  case 24: /* idInit: IDENTIFIER  */
#line 153 "fastLang.y"
               {
        addSymbol((yyvsp[0].stringVal), curType);
    }
#line 1328 "fastLang.tab.c"
    break;

  case 25: /* idInit: IDENTIFIER ASSIGN expression  */
#line 156 "fastLang.y"
                                   {
        checkType(curType, (yyvsp[0].expr).type);
        addSymbol((yyvsp[-2].stringVal), curType);
        fprintf(out, "%s := %s\n", (yyvsp[-2].stringVal), (yyvsp[0].expr).place);
    }
#line 1338 "fastLang.tab.c"
    break;

  case 34: /* expr_stmt: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 172 "fastLang.y"
                                           {
        checkType(getType((yyvsp[-3].stringVal)), (yyvsp[-1].expr).type);
        fprintf(out, "%s := %s\n", (yyvsp[-3].stringVal), (yyvsp[-1].expr).place);
    }
#line 1347 "fastLang.tab.c"
    break;

  case 35: /* $@2: %empty  */
#line 179 "fastLang.y"
                                {
        ltrue = tempCount++;
        lfalse = tempCount++;
        fprintf(out, "if %s goto L%d\ngoto L%d\nL%d:\n", (yyvsp[-1].expr).place, ltrue, lfalse, ltrue);
    }
#line 1357 "fastLang.tab.c"
    break;

  case 37: /* FollowIf: statement  */
#line 187 "fastLang.y"
              {
        fprintf(out, "L%d:\n", lfalse);
    }
#line 1365 "fastLang.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 190 "fastLang.y"
                     {
        lend = tempCount++;
        fprintf(out, "goto L%d\nL%d:\n", lend, lfalse);
    }
#line 1374 "fastLang.tab.c"
    break;

  case 39: /* FollowIf: statement ELSE $@3 statement  */
#line 193 "fastLang.y"
                {
        fprintf(out, "L%d:\n", lend);
    }
#line 1382 "fastLang.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 198 "fastLang.y"
                                   {
        lstart = tempCount++;
        ltrue = tempCount++;
        lfalse = tempCount++;
        fprintf(out, "L%d:\nif %s goto L%d\ngoto L%d\nL%d:\n", lstart, (yyvsp[-1].expr).place, ltrue, lfalse, ltrue);
    }
#line 1393 "fastLang.tab.c"
    break;

  case 41: /* iteration_stmt: WHILE LPAREN expression RPAREN $@4 statement  */
#line 203 "fastLang.y"
                {
        fprintf(out, "goto L%d\nL%d:\n", lstart, lfalse);
    }
#line 1401 "fastLang.tab.c"
    break;

  case 42: /* return_stmt: RETURN expression SEMICOLON  */
#line 209 "fastLang.y"
                                { fprintf(out, "return %s\n", (yyvsp[-1].expr).place); }
#line 1407 "fastLang.tab.c"
    break;

  case 43: /* return_stmt: RETURN SEMICOLON  */
#line 210 "fastLang.y"
                       { fprintf(out, "return\n"); }
#line 1413 "fastLang.tab.c"
    break;

  case 44: /* io_stmt: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 214 "fastLang.y"
                                             {
        fprintf(out, "param %s\n", (yyvsp[-2].expr).place);
        fprintf(out, "call print, 1\n");
    }
#line 1422 "fastLang.tab.c"
    break;

  case 45: /* io_stmt: SCAN LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 218 "fastLang.y"
                                              {
        getType((yyvsp[-2].stringVal));
        fprintf(out, "param %s\n", (yyvsp[-2].stringVal));
        fprintf(out, "call scan, 1\n");
    }
#line 1432 "fastLang.tab.c"
    break;

  case 52: /* RelExpr: E RelOp E  */
#line 240 "fastLang.y"
                  {
        char buf[1024]="";
        strcat(buf, (yyvsp[-2].expr).place);
        strcat(buf, (yyvsp[-1].stringVal));
        strcat(buf, (yyvsp[0].expr).place);
        (yyval.stringVal) = buf;
    }
#line 1444 "fastLang.tab.c"
    break;

  case 54: /* RelOp: LT  */
#line 251 "fastLang.y"
       {(yyval.stringVal) = "<";}
#line 1450 "fastLang.tab.c"
    break;

  case 55: /* RelOp: GT  */
#line 251 "fastLang.y"
                        {(yyval.stringVal) = ">";}
#line 1456 "fastLang.tab.c"
    break;

  case 56: /* RelOp: EQ  */
#line 251 "fastLang.y"
                                         {(yyval.stringVal) = "==";}
#line 1462 "fastLang.tab.c"
    break;

  case 57: /* RelOp: NE  */
#line 251 "fastLang.y"
                                                           {(yyval.stringVal) = "!=";}
#line 1468 "fastLang.tab.c"
    break;

  case 58: /* RelOp: GE  */
#line 251 "fastLang.y"
                                                                             {(yyval.stringVal) = ">=";}
#line 1474 "fastLang.tab.c"
    break;

  case 59: /* RelOp: LE  */
#line 251 "fastLang.y"
                                                                                               {(yyval.stringVal) = "<=";}
#line 1480 "fastLang.tab.c"
    break;

  case 60: /* E: E AddOp T  */
#line 255 "fastLang.y"
                  {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1491 "fastLang.tab.c"
    break;

  case 61: /* E: T  */
#line 261 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1497 "fastLang.tab.c"
    break;

  case 62: /* AddOp: PLUS  */
#line 265 "fastLang.y"
         {(yyval.stringVal) = "+";}
#line 1503 "fastLang.tab.c"
    break;

  case 63: /* AddOp: MINUS  */
#line 265 "fastLang.y"
                             {(yyval.stringVal) = "-";}
#line 1509 "fastLang.tab.c"
    break;

  case 64: /* T: T MultOp U  */
#line 269 "fastLang.y"
                   {
        checkType((yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        char* t = newTemp();
        fprintf(out, "%s := %s %s %s\n", t, (yyvsp[-2].expr).place, (yyvsp[-1].stringVal), (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = (yyvsp[-2].expr).type };
    }
#line 1520 "fastLang.tab.c"
    break;

  case 65: /* T: U  */
#line 275 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1526 "fastLang.tab.c"
    break;

  case 66: /* MultOp: TIMES  */
#line 279 "fastLang.y"
          {(yyval.stringVal) = "*";}
#line 1532 "fastLang.tab.c"
    break;

  case 67: /* MultOp: DIVIDE  */
#line 279 "fastLang.y"
                               {(yyval.stringVal) = "/";}
#line 1538 "fastLang.tab.c"
    break;

  case 68: /* MultOp: MOD  */
#line 279 "fastLang.y"
                                                 {(yyval.stringVal) = "%";}
#line 1544 "fastLang.tab.c"
    break;

  case 69: /* U: MINUS F  */
#line 283 "fastLang.y"
                         {
        if (strcmp((yyvsp[0].expr).type, "int") != 0) {
            fprintf(stderr, "Semantic Error at line %d: Unary minus on non-int\n", yylineno);
            exit(1);
        }
        char* t = newTemp();
        fprintf(out, "%s := -%s\n", t, (yyvsp[0].expr).place);
        (yyval.expr) = (typeof((yyval.expr))){ .place = t, .type = "int" };
    }
#line 1558 "fastLang.tab.c"
    break;

  case 70: /* U: F  */
#line 292 "fastLang.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1564 "fastLang.tab.c"
    break;

  case 71: /* F: INT_LITERAL  */
#line 296 "fastLang.y"
                {
        char* buf = malloc(10);
        sprintf(buf, "%d", (yyvsp[0].intVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "int" };
    }
#line 1574 "fastLang.tab.c"
    break;

  case 72: /* F: BOOL_LITERAL  */
#line 301 "fastLang.y"
                   {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].intVal) ? "true" : "false", .type = "bool" };
    }
#line 1582 "fastLang.tab.c"
    break;

  case 73: /* F: CHAR_LITERAL  */
#line 304 "fastLang.y"
                   {
        char* buf = malloc(4);
        sprintf(buf, "'%c'", (yyvsp[0].charVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "char" };
    }
#line 1592 "fastLang.tab.c"
    break;

  case 74: /* F: STRING_LITERAL  */
#line 309 "fastLang.y"
                     {
        char* buf = malloc(1024);
        sprintf(buf, "\"%s\"", (yyvsp[0].stringVal));
        (yyval.expr) = (typeof((yyval.expr))){ .place = buf, .type = "string" };
    }
#line 1602 "fastLang.tab.c"
    break;

  case 75: /* F: IDENTIFIER  */
#line 314 "fastLang.y"
                 {
        (yyval.expr) = (typeof((yyval.expr))){ .place = (yyvsp[0].stringVal), .type = (char*)getType((yyvsp[0].stringVal)) };
    }
#line 1610 "fastLang.tab.c"
    break;

  case 76: /* F: LPAREN expression RPAREN  */
#line 317 "fastLang.y"
                               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1616 "fastLang.tab.c"
    break;


#line 1620 "fastLang.tab.c"

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

#line 320 "fastLang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d, %s\n", yylineno, s);
}

