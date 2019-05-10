#define SIZE 10
#include<stdio.h>
#include<string.h>

struct giri
{
	char arr[SIZE];
	int top;
};


int isempty(struct giri *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int isfull(struct giri *s)
{
	if(s->top==SIZE-1)
		return 1;
	else
		return 0;
}
int push(struct giri *s,char temp)
{
	if(isfull(s))
		return 0;
	else
	{
		s->top=s->top+1;
		s->arr[s->top]=temp;
		return 1;
	}
}
int pop(struct giri *s,char *temp)
{
	if(isempty(s))
		return 0;
	else
	{
		*temp=s->arr[s->top];
		s->top=s->top-1;
		return 1;
	}
}
int peek(struct giri *s,char *temp)
{
	if(isempty(s))
		return 0;
	else
	{
		*temp=s->arr[s->top];
		return 1;
	}
}




void main()
{
	struct giri s;
	char op2,op1;
	char postfix[100];
	int result;
	char temp;
	int i=0;
	s.top=-1;
	clrscr();
	printf("enter the postfix string\n");
	scanf("%s",postfix);
	while(postfix[i]!='\0')
	{
		while(postfix[i]>=48&& postfix[i]<=57)
		{
			push(&s,postfix[i]);
			i++;
			}


			pop(&s,&op2);
			pop(&s,&op1);
			if(postfix[i]=='+')
				result=(op1-48)+(op2-48);
			else if(postfix[i]=='-')
				result=(op1-48)-(op2-48);
			else if(postfix[i]=='*')
				result=(op1-48)*(op2-48);
			else {
				result=(op1-48)/(op2-48);}

			temp=result+48;

		push(&s,temp);
		i++;
	}
	printf("result=%d\n",result);
	getch();
}
