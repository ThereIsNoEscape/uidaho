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
    BASE2 = 266,
    BASE16 = 267,
    LABEL = 268,
    Op_Proc = 269,
    Op_Declend = 270,
    Op_End = 271,
    Op_Link = 272,
    Op_Version = 273,
    Op_Con = 274,
    Op_Filen = 275,
    Op_Record = 276,
    Op_Impl = 277,
    Op_Error = 278,
    Op_Trace = 279,
    Op_Lab = 280,
    Op_Invocable = 281,
    Op_Copyd = 282,
    Op_Trapret = 283,
    Op_Trapfail = 284,
    Op_Synt = 285,
    Op_Uid = 286,
    Op_Asgn = 287,
    Op_Bang = 288,
    Op_Cat = 289,
    Op_Compl = 290,
    Op_Diff = 291,
    Op_Div = 292,
    Op_Eqv = 293,
    Op_Inter = 294,
    Op_Lconcat = 295,
    Op_Lexeq = 296,
    Op_Lexge = 297,
    Op_Lexgt = 298,
    Op_Lexle = 299,
    Op_Lexlt = 300,
    Op_Lexne = 301,
    Op_Minus = 302,
    Op_Mod = 303,
    Op_Mult = 304,
    Op_Neg = 305,
    Op_Neqv = 306,
    Op_Nonull = 307,
    Op_Nonnull = 308,
    Op_Noop = 309,
    Op_Null = 310,
    Op_Number = 311,
    Op_Numeq = 312,
    Op_Numge = 313,
    Op_Numgt = 314,
    Op_Numle = 315,
    Op_Numlt = 316,
    Op_Numne = 317,
    Op_Plus = 318,
    Op_Power = 319,
    Op_Random = 320,
    Op_Rasgn = 321,
    Op_Rcv = 322,
    Op_RcvBk = 323,
    Op_Refresh = 324,
    Op_Rswap = 325,
    Op_Sect = 326,
    Op_Snd = 327,
    Op_SndBk = 328,
    Op_Size = 329,
    Op_Subsc = 330,
    Op_Swap = 331,
    Op_Tabmat = 332,
    Op_Toby = 333,
    Op_Unions = 334,
    Op_Value = 335,
    Op_Bscan = 336,
    Op_Ccase = 337,
    Op_Chfail = 338,
    Op_Coact = 339,
    Op_Cofail = 340,
    Op_Coret = 341,
    Op_Create = 342,
    Op_Cset = 343,
    Op_Dup = 344,
    Op_Efail = 345,
    Op_EInit = 346,
    Op_Eret = 347,
    Op_Escan = 348,
    Op_Esusp = 349,
    Op_Field = 350,
    Op_Goto = 351,
    Op_Init = 352,
    Op_Int = 353,
    Op_Invoke = 354,
    Op_Keywd = 355,
    Op_Limit = 356,
    Op_Line = 357,
    Op_Llist = 358,
    Op_Lsusp = 359,
    Op_Mark = 360,
    Op_Pfail = 361,
    Op_Pnull = 362,
    Op_Pop = 363,
    Op_Pret = 364,
    Op_Psusp = 365,
    Op_Push1 = 366,
    Op_Pushn1 = 367,
    Op_Real = 368,
    Op_Sdup = 369,
    Op_Str = 370,
    Op_Unmark = 371,
    Op_Var = 372,
    Op_Arg = 373,
    Op_Static = 374,
    Op_Local = 375,
    Op_Global = 376,
    Op_Mark0 = 377,
    Op_Quit = 378,
    Op_FQuit = 379,
    Op_Tally = 380,
    Op_Apply = 381,
    Op_Acset = 382,
    Op_Areal = 383,
    Op_Astr = 384,
    Op_Aglobal = 385,
    Op_Astatic = 386,
    Op_Agoto = 387,
    Op_Amark = 388,
    Op_Colm = 389,
    Op_Any = 390,
    Op_Case = 391,
    Op_Endcase = 392,
    Op_Every = 393,
    Op_Endevery = 394,
    Op_If = 395,
    Op_Endif = 396,
    Op_Ifelse = 397,
    Op_Endifelse = 398,
    Op_Repeat = 399,
    Op_Endrepeat = 400,
    Op_Suspend = 401,
    Op_Endsuspend = 402,
    Op_Until = 403,
    Op_Enduntil = 404,
    Op_While = 405,
    Op_Endwhile = 406,
    Op_Allocated = 407,
    Op_Clock = 408,
    Op_Collections = 409,
    Op_Column = 410,
    Op_Current = 411,
    Op_Date = 412,
    Op_Now = 413,
    Op_Dateline = 414,
    Op_Digits = 415,
    Op_E = 416,
    Op_Errornumber = 417,
    Op_Errortext = 418,
    Op_Errorvalue = 419,
    Op_Errout = 420,
    Op_Fail = 421,
    Op_Eventcode = 422,
    Op_Eventsource = 423,
    Op_Eventvalue = 424,
    Op_Features = 425,
    Op_File = 426,
    Op_Host = 427,
    Op_Input = 428,
    Op_Lcase = 429,
    Op_Letters = 430,
    Op_Level = 431,
    Op_Main = 432,
    Op_Output = 433,
    Op_Phi = 434,
    Op_Pi = 435,
    Op_Pick = 436,
    Op_Pos = 437,
    Op_Progname = 438,
    Op_Regions = 439,
    Op_Source = 440,
    Op_Storage = 441,
    Op_Subject = 442,
    Op_Time = 443,
    Op_Dump = 444,
    Op_Ucase = 445,
    Op_Errno = 446,
    Op_Window = 447,
    Op_Col = 448,
    Op_Row = 449,
    Op_X = 450,
    Op_Y = 451,
    Op_Interval = 452,
    Op_Control = 453,
    Op_Shift = 454,
    Op_Meta = 455,
    Op_Lpress = 456,
    Op_Mpress = 457,
    Op_Rpress = 458,
    Op_Lrelease = 459,
    Op_Mrelease = 460,
    Op_Rrelease = 461,
    Op_Ldrag = 462,
    Op_Mdrag = 463,
    Op_Rdrag = 464,
    Op_Resize = 465,
    Op_Ascii = 466,
    IDENTIFIER = 467
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
