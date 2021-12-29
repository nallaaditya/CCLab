#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
}Node;

Node *stack[20];

Node *root;

char input[80];

int top=-1;

int maxSize=20;


void inorder(Node *curr)
{
	if(curr!=NULL)
	{
		inorder(curr->left);
		printf("%c",curr->data);
		inorder(curr->right);
	}
	
}

void pushNode(Node *currNode)
{
		if(top+1>=maxSize)
		{
			printf("Stack is FULL\n");
		}
		top++;
		stack[top]=currNode;
	
}

Node* popNode()
{
	Node *returnNode;
	
	if(top==-1)
	{
		printf("Stack is Empty\n");	
		return NULL;
	}
	
	returnNode=stack[top];
	top--;
	
	return returnNode;
	
}

void buildTree()
{

	int i;
	for(i=0;input[i]!='\0';i++)
	{

		char ch=input[i];
		
		Node *temp=(Node *)malloc(sizeof(Node));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=ch;
		
		if(isalpha(ch))
		{
			pushNode(temp);
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
			temp->right=popNode();
			temp->left=popNode();
			
			pushNode(temp);
		}
	}

	root=popNode();


}

int main()
{
	
	printf("Enter the input String\n");
	scanf("%s",input);

	buildTree();	

	inorder(root);
	
	return 0;
}

