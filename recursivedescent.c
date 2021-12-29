#include<stdio.h>

char str[100];

int i=0;

void E();

void E1();

void T();

void T1();

void F();


void T()
{
	F();
	T1();
	
}

void E1()
{
	if(str[i]=='+')
	{
		i++;
		T();
		E1();
	}
	
}

void T1()
{
	//T'-->*FT'
	
	if(str[i]=='*')
	{
		i++;
		F();
		T1();
	}
	
}

void F()
{
	if(str[i]=='(')
	{
		i++;
		E();
		if(str[i]==')')
		{
			i++;
		}
		else
		{
			printf(") expected");
			//exit(0);
		}
	}
	else if(str[i]=='i')
	{
		i++;
	}
	else
	{
		return;
	}
}	

void E()
{
	//E-->TE'
	
	T();
	E1();
}


int main()
{

	//we will recontruct the recursive descent parser for only static production;
	
	//the production considered is
	/*
	 * E-->TE'
	 * E'-->+TE'
	 * T-->FT'
	 * T'-->*FT'
	 * F-->(E)|id
	 */	
	 
	
	printf("Enter the input String");
	scanf("%s",str);
	
	E();
	
	if(str[i]=='$')
	{
		printf("Parsing Successful");
	}
	else
	{
		printf("Parsing Failed");
	}
	 
	
	return 0;
}