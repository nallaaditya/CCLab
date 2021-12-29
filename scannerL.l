%{
#include<stdio.h>
#include<stdlib.h>
int commentFlag=0;
%}

id[a-z][a-Z0-9]*

%%

#.* {printf("%s is an Preprocessor Directive\n",yytext);}

"/*" {commentFlag=1;printf("%s Start of comment\n",yytext);}

"*/" {commentFlag=0;printf("%s is an End of Comment\n",yytext);}

int|float|char|double|main|return|printf|switch|goto|if|else|for|while|case {if(commentFlag==0){printf("%s is an Keyword\n",yytext);}} 

\<=|\>=|\<|\>|\== {if(commentFlag==0){printf("%s is an Relational Operator\n",yytext);}}

\{ {if(commentFlag==0){printf("%s is Start of block\n",yytext);}}

\} {if(commentFlag==0){printf("%s is End of block\n",yytext);}}

\( {if(commentFlag==0){printf("%s is Open Pranthesis\n",yytext);}}

\) {if(commentFlag==0){printf("%s is End of Paranthesis\n",yytext);}}

\= {if(commentFlag==0){printf("%s is Assignement Operator\n",yytext);}}


{id}\( {if(commentFlag==0){printf("%s is Function\n",yytext);}}

[0-9]+ {if(commentFlag==0){printf("%s is a Number\n",yytext);}}

{id}(\[[0-9]*\])? {if(commentFlag==0){printf("%s is an Identifier\n",yytext);}}

"\n" {;}


%%

int main(int argc,char **argv)
{
	FILE *input;
	input=fopen("inputc.c","r");
	if(!input)
	{	
		printf("File is not present");		
		exit(0);
	}

	yyin=input;
	yylex();

	return 0;
}

int yywrap()
{
	return 0;
}
