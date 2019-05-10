#include<stdio.h>
#include<conio.h>
#define SIZE 10

struct aysll
{
	int data;
	struct aysll *next;
};

int hashfun(int x)
{
	return (x%SIZE);
}

int aylsearch(struct aysll *head,int data,struct aysll **prev)
{
	struct aysll *temp=head;
	*prev=NULL;
	while(temp!=NULL && data!=temp->data)
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

int aylinsert(struct aysll **head,int data)
{
       struct aysll *prev=NULL,*newnode=NULL;

       if(aylsearch(*head,data,&prev))
       {
		return 0;
       }

       newnode=(struct aysll *)malloc(sizeof(struct aysll));
       if(newnode==NULL)
       {
		printf("\nCannot allocate memory..\n");
		return 0;
       }
       newnode->data=data;
       newnode->next=*head;
       *head=newnode;
       return 1;
}


int ayldelete(struct aysll **head,int data)
{
	struct aysll *prev,*temp=NULL;
	prev=NULL;
	if(!aylsearch(*head,data,&prev))
	{
		 return 0;
	}
	if(prev==NULL)
	{
		 temp=*head;
		 *head=(*head)->next;
		 free(temp);
	}
	else
	{
		 temp=prev->next;
		 prev->next=temp->next;
		 free(temp);
	}
	return 1;
}

int ayltraversal(struct aysll *head)
{
	struct aysll *temp=head;
	if(head==NULL)
		return 0;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return 1;
}

void main()
{
	int n,i,a1,slot;
	struct aysll *a[SIZE]={NULL};
	clrscr();
	printf("Enter no. of inserts:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1);
		slot=hashfun(a1);
		aylinsert(&a[slot],a1);
	}
	printf("Enter no. of deletions:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1);
		slot=hashfun(a1);
		ayldelete(&a[slot],a1);
	}
	ayltraversal(a[0]);
	getch();
}




