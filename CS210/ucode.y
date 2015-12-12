%{
#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
FILE *yyin;
extern char *yyfilename;
extern char *yytext;
extern int num_lines;
int yydebug = 1;
%}

%token VERSIONSTAMP
%token UCODESTAMP
%token DECCONST
%token COMMA
%token OCTCONST
%token CONTROL_L
%token REALCONST
%token FILENAME
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
%token Op_Negv
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
%token IDENTIFIER

%%

executable:	u2 CONTROL_L u1;

u2:		version uid records impl links invocable global;

version:	Op_Version VERSIONSTAMP;

uid:		Op_Uid UCODESTAMP;

records:	records Op_Record IDENTIFIER COMMA DECCONST recordlist | ;

recordlist:	recordlist DECCONST COMMA IDENTIFIER | 
		recordlist DECCONST COMMA Op_Init | 
		recordlist DECCONST COMMA noargopcode | ;

impl:		Op_Impl Op_Local |
		Op_Impl Op_Error;

invocable:	invocable Op_Invocable DECCONST |
		invocable Op_Invocable IDENTIFIER | ;

links:		links Op_Link FILENAME | ;

global:		Op_Global DECCONST globallist;

globallist:	globallist DECCONST COMMA OCTCONST COMMA IDENTIFIER COMMA DECCONST | ;

u1:		u1 variables | ;

variables:	Op_Proc IDENTIFIER variablelist Op_Declend oplist Op_End;

variablelist:	locals cons |
		locals |
		cons;

locals:		locals locallist | ;

locallist:	Op_Local DECCONST COMMA OCTCONST COMMA IDENTIFIER |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Proc |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Cset |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Keywd |
		Op_Local DECCONST COMMA OCTCONST COMMA Op_Line |
		Op_Local DECCONST COMMA OCTCONST COMMA noargopcode;

cons:		cons Op_Con conline | ;

conline:	DECCONST COMMA OCTCONST conlist;

conlist:	COMMA DECCONST |
		COMMA OCTCONST |
		COMMA REALCONST |
		conlist COMMA OCTCONST |
		conlist COMMA REALCONST |
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
		Op_Negv |
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
		Op_Lsusp;

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
		Op_Field noargopcode;

keywd:		Op_Keywd Op_Cset |
		Op_Keywd IDENTIFIER |
		Op_Keywd noargopcode;


proc:		Op_Proc IDENTIFIER |
		Op_Proc noargopcode;

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
