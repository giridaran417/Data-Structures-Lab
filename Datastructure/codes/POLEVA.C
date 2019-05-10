
#define NULL 0
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct ll
{
	int coe;
	int exp;
	struct ll * next;
};


int search(struct ll *head,int exp,struct ll **prev)
{
	struct ll *temp=NULL;

	temp=head;
	while(temp && exp<temp->exp)
	{
		*prev=temp;
		temp=temp->next;
	}
	if(!temp)
		return 0;
	else if(exp==temp->exp)
		return 1;
	else
		return 0;
}   //search fn ends

int insert(struct ll **head,int coe,int exp)
{
	struct ll *prev=NULL;
	struct ll *newnode;
	newnode=(struct ll *)malloc(sizeof(struct ll ));
	if(!newnode)
	{
		printf("memory allocation fail");
		return 0;
	}
	newnode->coe=coe;
	newnode->exp=exp;
	if(search(*head,exp,&prev))
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

int ldelete(struct ll **head,int exp)
{
	struct ll *prev=NULL,*temp=NULL;
	if(!search(*head,exp,&prev))
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
		printf("%d\t%d->",temp->coe,temp->exp);
		temp=temp->next;
	}
	printf("NULL\n");

}

int p1plusp2(struct ll *p1,struct ll *p2,struct ll **p3)
{
	struct ll *temp1,*temp2;
	temp1=p1;
	temp2=p2;
	while(temp1 && temp2)
	{
		if(temp1->exp<temp2->exp)
		{

			insert(p3,temp2->coe,temp2->exp);
			temp2=temp2->next;
		}
		else if(temp2->exp<temp1->exp)
		{

			insert(p3,temp1->coe,temp1->exp);
			temp1=temp1->next;
		}
		else
		{
			insert(p3,(temp1->coe+temp2->coe),temp1->exp);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(temp1)
		{
			temp2=temp1;
		}
		while(temp2)
		{
			insert(p3,temp2->coe,temp2->exp);
			temp2=temp2->next;
		}


	}
	return 1;

}


void main()
{
	struct ll *p1,*p2,*p3,*temp1,*temp2;
	int deg1,deg2,i,coe,exp;
	clrscr();
	p1=p2=NULL;
      //	temp1=p1;
       //	temp2=p2;
	printf("enter the higehest degree for p1\n");
	scanf("%d",&deg1);
	printf("enter the higehest degree for p2\n");
	scanf("%d",&deg2);
	for(i=0;i<=deg1;i++)
	{
		printf("enter the coe and exp for p1");
		scanf("%d%d",&coe,&exp);
		insert(&p1,coe,exp);
	}
       //	traverse(p1);

	for(i=0;i<=deg2;i++)
	{
		printf("enter the coe and exp for p2");
		scanf("%d%d",&coe,&exp);
		insert(&p2,coe,exp);
	}

	p1plusp2(p1,p2,&p3);
	traverse(p3);



	getch();
}