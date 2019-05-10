#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

int search(struct node *head,struct node **prev,int data)
{
	struct node *temp=NULL;

	temp=head;
	if(!head)
	{
		return 0;
	}
	while(temp && data>temp->data);
	{
		*prev=temp;
		temp=temp->next;
	}
	if(data==temp->data)
		return 1;
	else if(temp==NULL)
		return 0;
	else
		return 0;
}

int insert(struct node **head,struct node **tail,int data)
{
	struct node *newnode,*prev=NULL;
	if(search(*head,&prev,data))
	{
		printf("duplicates");
		return 0;

	}
	newnode=(struct node *)malloc(sizeof(struct node));
	if(!newnode)
	{
		printf("memory allocation fail");
		return 0;
	}
	newnode->data=data;
	if(!prev)
	{
		newnode->prev=NULL;
		newnode->next=*head;
		if(*head)
		{
			(*head)->prev=newnode;
		}
		else
		{
			*head=newnode;
			*tail=newnode;
		}

		*head=newnode;
	}
	else
	{
		newnode->prev=prev;
		newnode->next=prev->next;
		prev->next=newnode;
		if(newnode->next)
			newnode->next->prev=newnode;
	       //	else
	       //	{
		 //	*tail=newnode;
		//}

	}
	return 1;

}

int ldelete(struct node **head,struct node **tail,int data)
{
	struct node *temp,*prev=NULL;
	if(!search(*head,&prev,data))
		return 0;
	if(!prev)
	{
		temp=*head;
		*head=(*head)->next;
		if((*head)->next)
			(*head)->prev=NULL;
		else
		{
			*tail=NULL;
		}
		free(temp);
	}
	else
	{
		temp=prev->next;
		prev->next=temp->next;
		if(temp->next)
			temp->next->prev=prev;
		else
		{
			*tail=prev;
		}
		free(temp);
	}
	return 1;
}

int traversefront(struct node *head)
{
	struct node *temp=head;
	if(!head)
		return 0;
	while(temp)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	return 1;
}

int traverseback(struct node *tail)
{
	struct node *temp=tail;
	while(temp)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
	return 1;
}


void main()
{
	struct node *head,*tail,*prev;
     //	int a,n,i;
	head=NULL;
	tail=NULL;
	clrscr();
     /*	printf("enter how many numbers to be inserted\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	printf("enter the no. to be inserted\n");
	scanf("%d",&a);
	insert(&head,&tail,a);
	}
	traversefront(head);
	traverseback(tail);
	printf("enter how many numbers to be searched\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	printf("enter the no. to be searched\n");
	scanf("%d",&a);
	if(search(&head,a,&prev))
		printf("the no %d is in the doublylinkedlist\n",a);
	else
		printf("the no %d is not in the doublylinkedlist\n",a);
	}
	printf("enter how many numbers to be deleted\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	printf("enter the no. to be deleted\n");
	scanf("%d",&a);
	insert(&head,&tail,a);
	}
	traversefront(head);
	traverseback(tail);      */
	insert(&head,&tail,3);
	insert(&head,&tail,3);
	traversefront(head);
	getch();
}