#include"gllis.h"

int search(struct node *head,int data,struct node **prev)
{
	*prev=NULL;
	struct node *temp;
	temp=NULL;
	if(temp && data>temp->data)
	{
		*prev=temp;
		temp=temp->next;

	}
	if(temp==NULL)
		return 0;
	else if(data==temp->data)
		return 1;
	else
		return 0;

}
int ginsert(struct node **head,int data)
{
	struct node *newnode=NULL;
	struct node *prev=NULL;
	if(search(*head,data,&prev)
	{
		printf("duplicate canot be inserted");
		return 0;
	}
	newnode=(struct node *)malloc(sizeof(stuct node));
	if(
	if(prev==NULL)
	{

	*head=newnode;
	}

}