#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


char productions[30][30];
int n;

//startindex means where it has started the recursion;

char firstFunctions[30][30];

void firstFunctionCall(int presentindex,int startindex,int *iter)
{
	
	if(productions[presentindex][0]==productions[presentindex][3])
	{
		//it means left recursion;
		return;
	}
	
	//now it means there is no left recursion;
	
	//split bcz it may have | productions;
	
	char splitProductions[30][30];
	
	int j=0;
	int i;
	
	int jj=0,kk=0;
	
	for(j=3;j<strlen(productions[presentindex]);j++)
	{
		if(productions[presentindex][j]=='|')
		{
				jj=0;
				kk++;
			
		}
		else
		{
				splitProductions[kk][jj++]=productions[presentindex][j];
				
				//printf("\n %c \n",productions[presentindex][j]);
				
		}
	}
	
	for(i=0;i<=kk;i++)
	{
			if(!isupper(splitProductions[i][0]))
			{
					
					firstFunctions[startindex][*iter]=splitProductions[i][0];
					(*iter)++;
					//printf(" %c ",splitProductions[i][0]);
				
			}
			else
			{
				for(jj=0;jj<n;jj++)
				{
						if(productions[jj][0]==splitProductions[i][0])
						{
								
							firstFunctionCall(jj,startindex,(iter));
							break;
						
						}
				}
				
			}
		
	}
	
}

void followFunctionCall()
{

	int i,j,k;
	
	for(i=0;i<n;i++)
	{
			if(i==0)
			{
				printf("Follow(%c) => $\n",productions[0][0]);
			}
			for(j=3;productions[i][j]!='\0';j++)
			{
				if(productions[i][j] >='A' && productions[i][j]<='Z')
				{
					if(strlen(productions[i])-1==j)
					{
						printf("Follow(%c) => Follow(%c)\n",productions[i][j],productions[i][0]);
					}
					if(!isupper(productions[i][j+1]) && (productions[i][j+1])!='\0')
					{
						printf("Follow(%c) => %c\n",productions[i][j],productions[i][j+1]);
					}
					if(isupper(productions[i][j+1]))
					{
						int flag=0;
						for(k=0;k<n;k++)
						{
								if(productions[k][0]=productions[i][j+1])
								{
									flag=k;
									break;
								}
						}
						
						printf("Follow(%c) => ",productions[i][j]);
						for(int iter=0;iter<strlen(firstFunctions[k]);iter++)
						{
								
							printf(" %c ",firstFunctions[k][iter]);
						}
						printf("\n");
					}
				}
				
			}
		
	}
	
	
}

int main()
{
	
	
	printf("Enter the number of productions\n");
	scanf("%d",&n);

	printf("Enter the %d productions in the format of A->X1|X2\n",n);

	
	
	int i,k;
	for(i=0;i<n;i++)
	{
		scanf("%s",productions[i]);
	}

	//now need to print the first for the functions;
	
	for(i=0;i<n;i++)
	{
			char nT=productions[i][0];
	
			int presentindex=i;
			int startindex=i;
			int iter=0;
			
			firstFunctionCall(presentindex,startindex,&iter);
		
	}

	printf("Printing First Functions:\n");
	for(i=0;i<n;i++)
	{
	
			printf("FIRST(%c) =>{",productions[i][0]);
			
			int j;
			
			
			for(j=0;j<strlen(firstFunctions[i]);j++)
			{
				printf(" %c ",firstFunctions[i][j]);
			}		
		
			printf("}\n");
	}
	
	followFunctionCall();
	
	return 0;
}
