%{
#include<stdio.h>
%}

%%
.*00 {printf("ending with 00");}
[a-z][A-Z] {printf("It is a alphabet");}
[+-]?[0-9]+ {printf("It is a number");}
[+-]?[0-9]*\.[0-9]+ {printf("Float recognized");}
[a-zA-Z]* {printf("Word");}
[0-9a-zA-z] {printf("String");}
.* {printf("Nothing");}
%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 0;
}
