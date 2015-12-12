%{
// Jonathan Buch CS210 ucode.y Homework #5 November 19th, 2015

#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
FILE *yyin;
extern char *yyfilename;
extern char *yytext;
extern int num_lines;
int yydebug = 0;
%}

%token VERSIONSTAMP
%token UCODESTAMP
%token DECCONST
%token COMMA
%token OCTCONST
%token CONTROL_L
%token REALCONST
%token FILENAME
%token BASE2
%token BASE16
%token LABEL
%token Op_Proc
%token Op_Declend
%token Op_End
%token Op_Link
%token Op_Version
%token Op_Con
%token Op_Filen
%token Op_Record
%token Op_Impl
%token Op_Error
%token Op_Trace
%token Op_Lab
%token Op_Invocable
%token Op_Copyd
%token Op_Trapret
%token Op_Trapfail
%token Op_Synt
%token Op_Uid
%token Op_Asgn
%token Op_Bang
%token Op_Cat
%token Op_Compl
%token Op_Diff
%token Op_Div
%token Op_Eqv
%token Op_Inter
%token Op_Lconcat
%token Op_Lexeq
%token Op_Lexge
%token Op_Lexgt
%token Op_Lexle
%token Op_Lexlt
%token Op_Lexne
%token Op_Minus
%token Op_Mod
%token Op_Mult
%token Op_Neg
%token Op_Neqv
%token Op_Nonull
%token Op_Nonnull
%token Op_Noop
%token Op_Null
%token Op_Number
%token Op_Numeq
%token Op_Numge
%token Op_Numgt
%token Op_Numle
%token Op_Numlt
%token Op_Numne
%token Op_Plus
%token Op_Power
%token Op_Random
%token Op_Rasgn
%token Op_Rcv
%token Op_RcvBk
%token Op_Refresh
%token Op_Rswap
%token Op_Sect
%token Op_Snd
%token Op_SndBk
%token Op_Size
%token Op_Subsc
%token Op_Swap
%token Op_Tabmat
%token Op_Toby
%token Op_Unions
%token Op_Value
%token Op_Bscan
%token Op_Ccase
%token Op_Chfail
%token Op_Coact
%token Op_Cofail
%token Op_Coret
%token Op_Create
%token Op_Cset
%token Op_Dup
%token Op_Efail
%token Op_EInit
%token Op_Eret
%token Op_Escan
%token Op_Esusp
%token Op_Field
%token Op_Goto
%token Op_Init
%token Op_Int
%token Op_Invoke
%token Op_Keywd
%token Op_Limit
%token Op_Line
%token Op_Llist
%token Op_Lsusp
%token Op_Mark
%token Op_Pfail
%token Op_Pnull
%token Op_Pop
%token Op_Pret
%token Op_Psusp
%token Op_Push1
%token Op_Pushn1
%token Op_Real
%token Op_Sdup
%token Op_Str
%token Op_Unmark
%token Op_Var
%token Op_Arg
%token Op_Static
%token Op_Local
%token Op_Global
%token Op_Mark0
%token Op_Quit
%token Op_FQuit
%token Op_Tally
%token Op_Apply
%token Op_Acset
%token Op_Areal
%token Op_Astr
%token Op_Aglobal
%token Op_Astatic
%token Op_Agoto
%token Op_Amark
%token Op_Colm
%token Op_Any
%token Op_Case
%token Op_Endcase
%token Op_Every
%token Op_Endevery
%token Op_If
%token Op_Endif
%token Op_Ifelse
%token Op_Endifelse
%token Op_Repeat
%token Op_Endrepeat
%token Op_Suspend
%token Op_Endsuspend
%token Op_Until
%token Op_Enduntil
%token Op_While
%token Op_Endwhile
%token Op_Allocated
%token Op_Clock
%token Op_Collections
%token Op_Column
%token Op_Current
%token Op_Date
%token Op_Now
%token Op_Dateline
%token Op_Digits
%token Op_E
%token Op_Errornumber
%token Op_Errortext
%token Op_Errorvalue
%token Op_Errout
%token Op_Fail
%token Op_Eventcode
%token Op_Eventsource
%token Op_Eventvalue
%token Op_Features
%token Op_File
%token Op_Host
%token Op_Input
%token Op_Lcase
%token Op_Letters
%token Op_Level
%token Op_Main
%token Op_Output
%token Op_Phi
%token Op_Pi
%token Op_Pick
%token Op_Pos
%token Op_Progname
%token Op_Regions
%token Op_Source
%token Op_Storage
%token Op_Subject
%token Op_Time
%token Op_Dump
%token Op_Ucase
%token Op_Errno
%token Op_Window
%token Op_Col
%token Op_Row
%token Op_X
%token Op_Y
%token Op_Interval
%token Op_Control
%token Op_Shift
%token Op_Meta
%token Op_Lpress
%token Op_Mpress
%token Op_Rpress
%token Op_Lrelease
%token Op_Mrelease
%token Op_Rrelease
%token Op_Ldrag
%token Op_Mdrag
%token Op_Rdrag
%token Op_Resize
%token Op_Ascii

%token IDENTIFIER

%%

executable:	u2 CONTROL_L u1;

u2:		version uid records impl links invocable global;

version:	Op_Version VERSIONSTAMP;

uid:		Op_Uid UCODESTAMP;

records:	records Op_Record IDENTIFIER COMMA DECCONST recordlist | ;

recordlist:	recordlist DECCONST COMMA noargopcode | 
		recordlist DECCONST COMMA Op_Init |
		recordlist DECCONST COMMA Op_Var |
		recordlist DECCONST COMMA Op_Uid |
		recordlist DECCONST COMMA Op_Str |
		recordlist DECCONST COMMA Op_Proc |
		recordlist DECCONST COMMA IDENTIFIER | ;

impl:		Op_Impl Op_Local |
		Op_Impl Op_Error;

invocable:	invocable Op_Invocable DECCONST |
		invocable Op_Invocable IDENTIFIER | ;

links:		links Op_Link FILENAME | ;

global:		Op_Global DECCONST globallist;

globallist:	globallist DECCONST COMMA OCTCONST COMMA IDENTIFIER COMMA DECCONST |
		globallist DECCONST COMMA OCTCONST COMMA Op_Invoke COMMA DECCONST |
		globallist DECCONST COMMA OCTCONST COMMA noargopcode COMMA DECCONST | ;

u1:		u1 variables | ;

variables:	Op_Proc IDENTIFIER variablelist Op_Declend oplist Op_End |
		Op_Proc Op_Invoke variablelist Op_Declend oplist Op_End |
		Op_Proc noargopcode variablelist Op_Declend oplist Op_End;

variablelist:	locals cons;

locals:		locals locallist | ;

locallist:	Op_Local DECCONST COMMA OCTCONST COMMA noargopcode |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Real |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Proc |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Var |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Uid |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Str |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Field |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Init |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Invoke |
		Op_Local DECCONST COMMA OCTCONST COMMA LABEL |
		Op_Local DECCONST COMMA OCTCONST COMMA IDENTIFIER;

cons:		cons Op_Con conline | ;

conline:	DECCONST COMMA OCTCONST conlist;

conlist:	COMMA DECCONST |
		COMMA OCTCONST |
		COMMA REALCONST |
		COMMA BASE2 |
		COMMA BASE16 |
		conlist COMMA OCTCONST |
		conlist COMMA REALCONST |
		conlist COMMA BASE2 |
		conlist COMMA BASE16 |
		conlist COMMA DECCONST;

oplist:		oplist opcodes |
		opcodes;

opcodes:	noargopcode |
		opwdecconst |
		opwfile |
		opwidentifiers |
		opwlabel |
		opwsynt;

noargopcode:	Op_Asgn |
		Op_Bang |
		Op_Cat |
		Op_Compl |
		Op_Diff |
		Op_Div |
		Op_Eqv |
		Op_Inter |
		Op_Lconcat |
		Op_Lexeq |
		Op_Lexge |
		Op_Lexgt |
		Op_Lexle |
		Op_Lexlt |
		Op_Lexne |
		Op_Minus |
		Op_Mod |
		Op_Mult |
		Op_Neg |
		Op_Neqv |
		Op_Nonull |
		Op_Nonnull |
		Op_Null |
		Op_Number |
		Op_Numeq |
		Op_Numge |
		Op_Numgt |
		Op_Numle |
		Op_Numlt |
		Op_Numne |
		Op_Plus |
		Op_Power |
		Op_Random |
		Op_Rasgn |
		Op_Rcv |
		Op_RcvBk |
		Op_Refresh |
		Op_Rswap |
		Op_Sect |
		Op_Snd |
		Op_SndBk |
		Op_Size |
		Op_Subsc |
		Op_Swap |
		Op_Tabmat |
		Op_Toby |
		Op_Unions |
		Op_Value |
		Op_Bscan |
		Op_Ccase |
		Op_Coact |
		Op_Cofail |
		Op_Coret |
		Op_Dup |
		Op_Efail |
		Op_Eret |
		Op_Escan |
		Op_Esusp |
		Op_Limit |
		Op_Pfail |
		Op_Pnull |
		Op_Pop |
		Op_Pret |
		Op_Psusp |
		Op_Push1 |
		Op_Pushn1 |
		Op_Sdup |
		Op_Arg |
		Op_Static |
		Op_Quit |
		Op_FQuit |
		Op_Tally |
		Op_Apply |
		Op_Acset |
		Op_Areal |
		Op_Astr |
		Op_Aglobal |
		Op_Astatic |
		Op_Agoto |
		Op_Amark |
		Op_Noop |
		Op_Error |
		Op_Trace |
		Op_Copyd |
		Op_Trapret |
		Op_Trapfail |
		Op_Any |
		Op_Case |
		Op_Endcase |
		Op_Every |
		Op_Endevery |
		Op_If |
		Op_Endif |
		Op_Ifelse |
		Op_Endifelse |
		Op_Repeat |
		Op_Endrepeat |
		Op_Suspend |
		Op_Endsuspend |
		Op_Until |
		Op_Enduntil |
		Op_While |
		Op_Endwhile |
		Op_Unmark |
		Op_Mark0 |
		Op_Lsusp |
		Op_Clock |
		Op_Collections |
		Op_Column |
		Op_Current |
		Op_Date |
		Op_Now |
		Op_Dateline |
		Op_Digits |
		Op_E |
		Op_Errornumber |
		Op_Errortext |
		Op_Errorvalue |
		Op_Errout |
		Op_Fail |
		Op_Eventcode |
		Op_Eventsource |
		Op_Eventvalue |
		Op_Features |
		Op_File |
		Op_Host |
		Op_Input |
		Op_Lcase |
		Op_Letters |
		Op_Level |
		Op_Line |
		Op_Main |
		Op_Output |
		Op_Phi |
		Op_Pi |
		Op_Pick |
		Op_Pos |
		Op_Progname |
		Op_Regions |
		Op_Source |
		Op_Storage |
		Op_Subject |
		Op_Time |
		Op_Dump |
		Op_Ucase |
		Op_Errno |
		Op_Window |
		Op_Col |
		Op_Row |
		Op_X |
		Op_Y |
		Op_Interval |
		Op_Control |
		Op_Shift |
		Op_Meta |
		Op_Lpress |
		Op_Mpress |
		Op_Rpress |
		Op_Lrelease |
		Op_Mrelease |
		Op_Rrelease |
		Op_Ldrag |
		Op_Mdrag |
		Op_Rdrag |
		Op_Resize |
		Op_Ascii |
		Op_Cset;

opwdecconst:	Op_Colm DECCONST |
		Op_Cset DECCONST |
		Op_Global DECCONST |
		Op_Int DECCONST |
		Op_Invoke DECCONST |
		Op_Line DECCONST |
		Op_Llist DECCONST |
		Op_Real DECCONST |
		Op_Str DECCONST |
		Op_Var DECCONST;

opwfile:	Op_Filen FILENAME |
		Op_Local FILENAME;


opwidentifiers:	field |
		keywd |
		proc;

field: 		Op_Field IDENTIFIER |
		Op_Field Op_Var |
		Op_Field Op_Uid |
		Op_Field Op_Init |
		Op_Field Op_Str |
		Op_Field Op_Proc |
		Op_Field noargopcode;

keywd:		Op_Keywd Op_Allocated |
		Op_Keywd Op_Clock |
		Op_Keywd Op_Collections |
		Op_Keywd Op_Column |
		Op_Keywd Op_Current |
		Op_Keywd Op_Date |
		Op_Keywd Op_Now |
		Op_Keywd Op_Dateline |
		Op_Keywd Op_Digits |
		Op_Keywd Op_E |
		Op_Keywd Op_Error |
		Op_Keywd Op_Errornumber |
		Op_Keywd Op_Errortext |
		Op_Keywd Op_Errorvalue |
		Op_Keywd Op_Errout |
		Op_Keywd Op_Fail |
		Op_Keywd Op_Eventcode |
		Op_Keywd Op_Eventsource |
		Op_Keywd Op_Eventvalue |
		Op_Keywd Op_Features |
		Op_Keywd Op_File |
		Op_Keywd Op_Host |
		Op_Keywd Op_Input |
		Op_Keywd Op_Lcase |
		Op_Keywd Op_Letters |
		Op_Keywd Op_Level |
		Op_Keywd Op_Line |
		Op_Keywd Op_Main |
		Op_Keywd Op_Output |
		Op_Keywd Op_Phi |
		Op_Keywd Op_Pi |
		Op_Keywd Op_Pick |
		Op_Keywd Op_Pos |
		Op_Keywd Op_Progname |
		Op_Keywd Op_Random |
		Op_Keywd Op_Regions |
		Op_Keywd Op_Source |
		Op_Keywd Op_Storage |
		Op_Keywd Op_Subject |
		Op_Keywd Op_Time |
		Op_Keywd Op_Trace |
		Op_Keywd Op_Dump |
		Op_Keywd Op_Ucase |
		Op_Keywd Op_Errno |
		Op_Keywd Op_Window |
		Op_Keywd Op_Col |
		Op_Keywd Op_Row |
		Op_Keywd Op_X |
		Op_Keywd Op_Y |
		Op_Keywd Op_Interval |
		Op_Keywd Op_Control |
		Op_Keywd Op_Shift |
		Op_Keywd Op_Meta |
		Op_Keywd Op_Lpress |
		Op_Keywd Op_Mpress |
		Op_Keywd Op_Rpress |
		Op_Keywd Op_Lrelease |
		Op_Keywd Op_Mrelease |
		Op_Keywd Op_Rrelease |
		Op_Keywd Op_Ldrag |
		Op_Keywd Op_Mdrag |
		Op_Keywd Op_Rdrag |
		Op_Keywd Op_Resize |
		Op_Keywd Op_Ascii |
		Op_Keywd Op_Null |
		Op_Keywd Op_Cset;


proc:		Op_Proc noargopcode |
		Op_Proc IDENTIFIER;

opwlabel:	Op_Chfail LABEL |
		Op_Create LABEL |
		Op_EInit LABEL |
		Op_Goto LABEL |
		Op_Init LABEL |
		Op_Lab LABEL |
		Op_Mark LABEL;

opwsynt:	Op_Synt Op_Any |
		Op_Synt Op_Case |
		Op_Synt Op_Endcase |
		Op_Synt Op_Every |
		Op_Synt Op_Endevery |
		Op_Synt Op_If |
		Op_Synt	Op_Endif |
		Op_Synt Op_Ifelse |
		Op_Synt Op_Endifelse |
		Op_Synt Op_Repeat |
		Op_Synt Op_Endrepeat |
		Op_Synt Op_Suspend |
		Op_Synt Op_Endsuspend |
		Op_Synt Op_Until |
		Op_Synt Op_Enduntil |
		Op_Synt Op_While |
		Op_Synt Op_Endwhile;

%%

void yyerror(const char *s)
{
	printf("%s: %s line %d token '%s'\n", s, yyfilename, num_lines, yytext);
}
