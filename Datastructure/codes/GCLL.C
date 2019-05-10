
#define NULL 0
#include<alloc.h>
#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};

int search(struct node *head,int data,struct node **prev)
{


	struct node *temp=NULL;
	*prev=NULL;
	if(!head)
	{
		return 0;
	}
	temp=head;
	do
	{
		if(data<=temp->data) {
			break;     }
		*prev=temp;
		temp=temp->next;

	}while(temp!=head);
	if(temp->data==data)
		return 1;
	else
		return 0;

}


int insert(struct node **head,int data)
{
	struct node *prev=NULL,*last=NULL,*newnode;
	if(search(*head,data,&prev))
	{
		return 0;
	}
	newnode=(struct node *)malloc(sizeof(struct node *));
	if(!newnode){
		return 0;}
	newnode->data=data;
	if(!(*head))
	{
		newnode->next=newnode;
		*head=newnode;
		return 1;
	}
	 if(!prev)                    //cll is not empty insertion at begining
	{
		last=*head;
		while(last->next!=*head)
		{
			last=last->next;
		}
		last->next=newnode;
		newnode->next=*head;
		*head=newnode;
		return 1;
	}
	else
	{
		newnode->next=prev->next;
		prev->next=newnode;

		return 1;
	}
}

int ldelete(struct node **head,int data)
{
	struct node *prev=NULL,*temp=NULL,*last=NULL;
	if(!search(*head,data,&prev))
	{
		return 0;
	}
	if((*head)->next==*head)
	{
		free(*head);
		*head=NULL;
		return 1;
	}
	if(!prev)
	{
		temp=*head;
		last=*head;
		while(last->next!=*head)
		{
			last=last->next;
		}
		*head=(*head)->next;
		last->next=*head;
		free(temp);
		return 1;
	}
	else
	{
		temp=prev->next;
		prev->next=temp->next;
		free(temp);
		return 1;
	}

}

int traverse(struct node *head)
{

	struct node *temp=NULL;
	if(!head)
	{
		return 0;
	}
	temp=head;
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;

	}while(temp!=head);
	return 1;

}

void main()
{
	struct node *head=NULL;
	int i,a,n;
	clrscr();
	printf("enter how many no to be inserted\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("enter the no  to be inserted\n");
		scanf("%d",&a);
		insert(&head,a);

	}
	traverse(head);
	printf("\n");
	printf("how many to be deleted\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the no to be deleted\n");
		scanf("%d",&a);
		ldelete(&head,a);
	}
	traverse(head);
	getch();

}