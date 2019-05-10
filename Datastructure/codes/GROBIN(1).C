#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct process
{
	int pid;
	int tet;
	int ret;
	struct process* next;
};


int search(struct process *head,int pid,struct process **prev)
{
	struct process *temp;
	*prev=NULL;
	temp=head;
	if(!head)
	{
		return 0;
	}
	do
	{
		if(pid<=temp->pid)
		{
			break;
		}
		*prev=temp;

		temp=temp->next;


	}while(temp!=head);

	if(temp->pid==pid)
		return 1;
	else if(temp==head)
		return 0;
	else
		return 0;


}

int insert(struct process **head,int pid,int tet,int ret)
{
	struct process *prev,*newnode;
	prev=NULL;
	if(search(*head,pid,&prev))
	{
		return 0;
	}
	newnode=(struct process *)malloc(sizeof(struct process ));
	if(!newnode)
	{
		printf("memory allocation fail");
		return 0;
	}
	newnode->pid=pid;
	newnode->tet=tet;
	newnode->ret=ret;
	if(!(*head))
	{
		newnode->next=newnode;
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
int ldelete(struct process  **head,int pid)
{
	struct process *prev=NULL,*last=NULL,*temp=NULL;
	last=*head;
	if(!search(*head,pid,&prev))
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

		}
		else
		{
			temp=prev->next;
			prev->next=temp->next;
			free(temp);
		}
		return 1;
}
int traverse(struct process *head)
{
	struct process *temp;
	if(head==NULL)
	{
		return 0;
	}
	temp=head;
	do
	{

		printf("process id=%d\ttotal time=%d\tremaining time=%d->\n",temp->pid,temp->tet,temp->ret);
		temp=temp->next;

	}while(temp!=head);
	return 1;
}

void main()
{
	struct process *head=NULL,*temp,*pre;
	int i,n,pid,tet,ret,tq;
	head=NULL;
	clrscr();
	printf("enter the value of time quantum\n");
	scanf("%d",&tq);
	printf("enter the no of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the processid and totel execution time\n");
		scanf("%d%d",&pid,&tet);
		ret=tet;
		insert(&head,pid,tet,ret);
	}
	temp=head;
	printf("process id\ttotaltime\tremaining time\n");
	while(head!=NULL )
	{
		temp->ret=(temp->ret)-tq;
		if(temp->ret<1)
		{
			temp->ret=0;
			printf("%d\t\t%d\t\t%d\n",temp->pid,temp->tet,temp->ret);
			pre=temp;
			temp=temp->next;
			ldelete(&head,pre->pid);
		}
		else
		{
		       printf("%d\t\t%d\t\t%d\n",temp->pid,temp->tet,temp->ret);
		       temp=temp->next;
		}

	}
	getch();
}
