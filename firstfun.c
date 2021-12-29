#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


char productions[30][30];
int n;

//startindex means where it has started the recursion;

void firstFunctionCall(int presentindex)
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
					printf(" %c ",splitProductions[i][0]);
				
			}
			else
			{
				for(jj=0;jj<n;jj++)
				{
						if(productions[jj][0]==splitProductions[i][0])
						{
								
							firstFunctionCall(jj);
							break;
						
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
			
			printf("FIRST(%c) => ",nT);
			
			int presentindex=i;
			int startindex=i;
			
			
			firstFunctionCall(presentindex);
			
			printf("\n");
	}

	

	return 0;
}
