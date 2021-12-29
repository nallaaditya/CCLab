#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{

	//input is the file in which our C program or input is written;
	//output is the file where we output or execution output into it;
	
	FILE *input,*output;

	input=fopen("input.txt","r");
	output=fopen("output.txt","w");
	
	
	//the keywords;
	char keyword[30][30]={"int","main","void","return","if","else","printf","goto","switch"};
	
	int lineno=1;
	int tokenno=1;
	
	char ch;
	
	char str[30];
	
	fprintf(output,"LineNo\tTokenNO\tToken\tLexene\n");
	
	while(!feof(input))
	{
		ch=fgetc(input);
		int i=0;
		int flag=0;
		
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		{
			fprintf(output,"%d\t%d\tOperator %c\n",lineno,tokenno,ch);
			tokenno++;
		}
		else if(ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==',' || ch=='#')
		{
			fprintf(output,"%d\t%d\tSymbols %c\n",lineno,tokenno,ch);
			tokenno++;
		}
		else if(isdigit(ch))
		{
			fprintf(output,"%d\t%d\tDigit %c\n",lineno,tokenno,ch);
			tokenno++;	
		}
		else if(ch=='\n')
		{
				lineno++;
		}
		else if(isalpha(ch))
		{
			
			//if we encounter an character we need to find whether it is an identifier or a keyword;
			
			i=0;
			str[i++]=ch;
			ch=fgetc(input);
			
			while(isalnum(ch) && ch!=' ')
			{
				str[i++]=ch;
				ch=fgetc(input);
			}
			str[i]='\0';
			
			int j;
			//check is it an identifier or a keyword;
			for(j=0;j<8;j++)
			{
				if(strcmp(str,keyword[j])==0)
				{
					flag=1;
					break;
				}
			}
			
			if(flag==1)
			{
				fprintf(output,"%d\t%d\tKeyword %s\n",lineno,tokenno,str);
				tokenno++;	
			}
			else
			{
				fprintf(output,"%d\t%d\tIdentifier %s\n",lineno,tokenno,str);
				tokenno++;	
			}
			flag=0;
		}
	}
			
	return 0;
}