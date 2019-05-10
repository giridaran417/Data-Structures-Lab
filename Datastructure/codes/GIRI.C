#include"giri.h"

int myisEmpty(struct giri *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int myisFull(struct giri *s)
{
	if(s->top+1==SIZE)
		return 1;
	else
		return 0;
}
int myPush(struct giri *s,int var)
{
	if(myisFull(s)==1)
		return 0;
	else
		s->top=s->top+1;
		s->arr[s->top]=var;
		return 1;
}
int myPop(struct giri *s,int *var)
{
	if(myisEmpty(s)==1)
		return 0;
	else
	{
		*var=s->arr[s->top];
		s->top=s->top-1;
		return 1;
	}
}
int myPeek(struct giri *s,int *var)
{
	if(myisEmpty(s)==1)
		return 0;
	else
		{
		*var=s->arr[s->top];
		return 1;
		}
}
