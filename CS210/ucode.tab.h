/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_UCODE_TAB_H_INCLUDED
# define YY_YY_UCODE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VERSIONSTAMP = 258,
    UCODESTAMP = 259,
    DECCONST = 260,
    COMMA = 261,
    OCTCONST = 262,
    CONTROL_L = 263,
    REALCONST = 264,
    FILENAME = 265,
    LABEL = 266,
    Op_Proc = 267,
    Op_Declend = 268,
    Op_End = 269,
    Op_Link = 270,
    Op_Version = 271,
    Op_Con = 272,
    Op_Filen = 273,
    Op_Record = 274,
    Op_Impl = 275,
    Op_Error = 276,
    Op_Trace = 277,
    Op_Lab = 278,
    Op_Invocable = 279,
    Op_Copyd = 280,
    Op_Trapret = 281,
    Op_Trapfail = 282,
    Op_Synt = 283,
    Op_Uid = 284,
    Op_Asgn = 285,
    Op_Bang = 286,
    Op_Cat = 287,
    Op_Compl = 288,
    Op_Diff = 289,
    Op_Div = 290,
    Op_Eqv = 291,
    Op_Inter = 292,
    Op_Lconcat = 293,
    Op_Lexeq = 294,
    Op_Lexge = 295,
    Op_Lexgt = 296,
    Op_Lexle = 297,
    Op_Lexlt = 298,
    Op_Lexne = 299,
    Op_Minus = 300,
    Op_Mod = 301,
    Op_Mult = 302,
    Op_Neg = 303,
    Op_Negv = 304,
    Op_Nonull = 305,
    Op_Nonnull = 306,
    Op_Noop = 307,
    Op_Null = 308,
    Op_Number = 309,
    Op_Numeq = 310,
    Op_Numge = 311,
    Op_Numgt = 312,
    Op_Numle = 313,
    Op_Numlt = 314,
    Op_Numne = 315,
    Op_Plus = 316,
    Op_Power = 317,
    Op_Random = 318,
    Op_Rasgn = 319,
    Op_Rcv = 320,
    Op_RcvBk = 321,
    Op_Refresh = 322,
    Op_Rswap = 323,
    Op_Sect = 324,
    Op_Snd = 325,
    Op_SndBk = 326,
    Op_Size = 327,
    Op_Subsc = 328,
    Op_Swap = 329,
    Op_Tabmat = 330,
    Op_Toby = 331,
    Op_Unions = 332,
    Op_Value = 333,
    Op_Bscan = 334,
    Op_Ccase = 335,
    Op_Chfail = 336,
    Op_Coact = 337,
    Op_Cofail = 338,
    Op_Coret = 339,
    Op_Create = 340,
    Op_Cset = 341,
    Op_Dup = 342,
    Op_Efail = 343,
    Op_EInit = 344,
    Op_Eret = 345,
    Op_Escan = 346,
    Op_Esusp = 347,
    Op_Field = 348,
    Op_Goto = 349,
    Op_Init = 350,
    Op_Int = 351,
    Op_Invoke = 352,
    Op_Keywd = 353,
    Op_Limit = 354,
    Op_Line = 355,
    Op_Llist = 356,
    Op_Lsusp = 357,
    Op_Mark = 358,
    Op_Pfail = 359,
    Op_Pnull = 360,
    Op_Pop = 361,
    Op_Pret = 362,
    Op_Psusp = 363,
    Op_Push1 = 364,
    Op_Pushn1 = 365,
    Op_Real = 366,
    Op_Sdup = 367,
    Op_Str = 368,
    Op_Unmark = 369,
    Op_Var = 370,
    Op_Arg = 371,
    Op_Static = 372,
    Op_Local = 373,
    Op_Global = 374,
    Op_Mark0 = 375,
    Op_Quit = 376,
    Op_FQuit = 377,
    Op_Tally = 378,
    Op_Apply = 379,
    Op_Acset = 380,
    Op_Areal = 381,
    Op_Astr = 382,
    Op_Aglobal = 383,
    Op_Astatic = 384,
    Op_Agoto = 385,
    Op_Amark = 386,
    Op_Colm = 387,
    Op_Any = 388,
    Op_Case = 389,
    Op_Endcase = 390,
    Op_Every = 391,
    Op_Endevery = 392,
    Op_If = 393,
    Op_Endif = 394,
    Op_Ifelse = 395,
    Op_Endifelse = 396,
    Op_Repeat = 397,
    Op_Endrepeat = 398,
    Op_Suspend = 399,
    Op_Endsuspend = 400,
    Op_Until = 401,
    Op_Enduntil = 402,
    Op_While = 403,
    Op_Endwhile = 404,
    IDENTIFIER = 405
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_UCODE_TAB_H_INCLUDED  */
