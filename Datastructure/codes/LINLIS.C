#include"linlis.h"
#define NULL 0


int search(struct ll *head,int data,struct ll **prev)
{
	struct ll *temp=NULL;
	*prev=NULL;
	temp=head;
	while(temp && data>temp->data)
	{
		*prev=temp;
		temp=temp->next;
	}
	if(!temp)
		return 0;
	else if(data==temp->data)
		return 1;
	else
		return 0;
}   //search fn ends

int insert(struct ll **head,int data)
{
	struct ll *prev=NULL;
	struct ll *newnode;
	newnode=(struct ll *)malloc(sizeof(struct ll *));
	if(!newnode)
	{
		printf("memory allocation fail");
		return 0;
	}
	newnode->data=data;
	if(search(*head,data,&prev))
	{
		printf("duplicates");
		return 0;
	}
	if(!prev)    //insert at begining
		{
			newnode->next=*head;
			*head=newnode;
		}
		else     //inserting at middle or end
		{
			newnode->next=prev->next;
			prev->next=newnode;

		}


		return 1;

}//insert fn ends

int ldelete(struct ll **head,int data)
{
	struct ll *prev=NULL,*temp=NULL;
	if(!search(*head,data,&prev))
	{
		printf("data not in the linkedlist");
		return 0;
	}
	else
	{
		if(!prev)      //deleting at beging
		{
			temp=*head;
			*head=temp->next;
			free(temp);
		}
		else
		{
			temp=prev->next;
			prev->next=temp->next;
			free(temp);
		}

	}
	return 1;
}

void traverse(struct ll *head)
{
	struct ll *temp=NULL;
	temp=head;
	while(temp)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}