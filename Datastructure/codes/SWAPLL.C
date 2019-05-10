#include<stdio.h>
#include<conio.h>
#define NULL 0
#include<alloc.h>

struct ll
{
	int data;
	struct ll *next;
};
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

int swap(struct ll **head)
{
	struct ll *prev1,*prev2,*temp1,*temp3,*temp2,*temp4,*prev;
	int x,y;
	printf("enter the two key to be swaped\n");
	scanf("%d%d",&x,&y);
	search(*head,x,&prev);
	prev1=prev;   //when prev1==null then we can't acess prev->next
	if(prev1)
		temp1=prev->next;        //be carefull
	else
		temp1=*head;
	search(*head,y,&prev);
	prev2=prev;
	temp2=prev->next;
	if(!prev1)
	{

		temp3=temp2->next;
		if(prev2!=temp1)             //when two nodes are not at adjacent location
			prev2->next=temp1;   //be carefull
		temp2->next=prev2;
		temp1->next=temp3;
		*head=temp2;
	}
	else
	{
		temp3=temp1->next;
		prev1->next=temp2;
		temp1->next=temp2->next;
		if(prev2!=temp1)
		{                           //when two nodes are not at adjacent location
			prev2->next=temp1;
			temp2->next=temp3;
		}
		else
			temp2->next=temp1;
	}
	return 1;
}

void main()
{
	struct  ll *head=NULL;
	int i,n,data;
	clrscr();
	printf("enter how may nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the data to be inserted\n");
		scanf("%d",&data);
		insert(&head,data);
	}
	traverse(head);
	printf("\n");
	swap(&head);
	traverse(head);


	getch();


}