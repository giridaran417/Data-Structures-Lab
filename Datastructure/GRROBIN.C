#define NULL 0
#include<stdio.h>
#include<conio.h>

struct process
{
	int tet;
	int ret;
	int pid;
	struct process *next;
};



int search(struct process *head,int pid,struct process **prev)
{
	struct process *temp;
	*prev=NULL;
	if(!head)
	{
		return 0;
	}
	temp=head;
	do
	{
		if(temp->pid<=pid) {
			break;     }
		*prev=temp;
		temp=temp->next;

	}while(temp!=head);
	if(temp->pid==pid)
		return 1;
	else
		return 0;

}


int insert(struct process **head,int pid,int tet,int ret)
{
	struct process *prev=NULL,*last=NULL,*newnode;
	if(search(*head,pid,&prev))
	{
		return 0;
	}
	newnode=(struct process *)malloc(sizeof(struct process ));
	if(!newnode){
		return 0;}
	newnode->pid=pid;
	newnode->tet=tet;
	newnode->ret=ret;
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

int ldelete(struct process **head,int pid)
{
	struct process *prev=NULL,*temp=NULL,*last=NULL;
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
	else if(!prev)
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

int traverse(struct process *head)
{
	struct process *temp;
	if(!head)
	{
		return 0;
	}

	temp=head;
	do{

		printf("%d\t%d\t%d\n",temp->pid,temp->tet,temp->ret);
		temp=temp->next;

	}while(temp!=head);
	return 1;

}



void main()
{
	struct process *head=NULL,**temp;
	int n,i,pid,tq,tet,ret;
	clrscr();
	printf("enter the value of time quantum");
	scanf("%d",&tq);
	printf("enter the number of processor\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the process id\n");
		scanf("%d%d",&pid,&tet);
		ret=tet;
		insert(&head,pid,tet,ret);

	}
	traverse(head);
	temp=&head;
	while(temp!=NULL)
	{
		(*temp)->ret= ((*temp)->tet)-tq;
		if(((*temp)->ret)<1)
		{
			//traverse(head);
			(*temp)=(*temp)->next;
			printf("rem=%d\n",(*temp)->ret);
			ldelete(&head,(*temp)->pid);
			//traverse(head);
		}
		else
		{
			(*temp)=(*temp)->next;
			printf("rem=%d\n",(*temp)->ret);
		}


	}

	getch();
}






























































































































