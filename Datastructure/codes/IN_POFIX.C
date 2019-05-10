#include<stdio.h>
#include<conio.h>
#include<cgiri.h>
#define HIGH 10
#define LOW 5
#define EXSIZE 10
int pri(char c)
	{
	if(c=='+'||c=='-')
		return LOW;
	else
		return HIGH;
	}
void main()
{
	struct giri s;
	char temp='\0';
	char infix[EXSIZE],postfix[EXSIZE];
	int i=0,j=0;
	clrscr();
	s.top=-1;
	printf("enter the infix string\n");
	scanf("%s",&infix);
	while(infix[i]!='\0')
	{
		if(infix[i]>=48&&infix[i]<=57)
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			myPush(&s,'(');
		}
		else if(infix[i]==')')
		{
			myPop(&s,&temp);
			while(temp !='(')
			{
				postfix[j++]=temp;
				myPop(&s,&temp);
			}
		}
		else
		{
			myPeek(&s,&temp);
			while((!myisEmpty(&s))&&(pri(infix[i]))<=(pri(temp)))
			{
				myPop(&s,&temp);
				postfix[j++]=temp;
				myPeek(&s,&temp);
			}
			myPush(&s,infix[i]);
		}

		i++;
	} //end while(infix!=0
	while(!myisEmpty(&s))
	{
		myPop(&s,&temp);
		postfix[j++]=temp;
	}
	printf("postfix:%s",postfix);
	getch();

}