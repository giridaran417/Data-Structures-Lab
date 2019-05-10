#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define SIZE 20
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct giri

{
	int top;
	struct node  *arr[SIZE];
};

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
int mypush(struct giri *s,struct node *var)
{
	if(myisFull(s)==1)
		return 0;
	else
		s->top=s->top+1;
		s->arr[s->top]=var;
		return 1;
}
int mypop(struct giri *s,struct node **var)
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
int mypeek(struct giri *s,struct node **var)
{
	if(myisEmpty(s)==1)
		return 0;
	else
		{
		*var=s->arr[s->top];
		return 1;
		}
}
int insert(struct node **root,struct node *newnode)
{
	if(!(*root))
	{
		*root=newnode;
		return 1;
	}
	if(newnode->data < (*root)->data)
		return insert(&((*root)->left),newnode);
	else if(newnode->data > (*root)->data)
		return insert(&((*root)->right),newnode);
	else
	{
		printf("duplicates insertion");
		return 0;
	}
}
struct node* newnode(int data)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void main(){
	struct node *root=NULL,*temp;
	struct giri s;
	int n,i,data;
	s.top=-1;
	clrscr();
	printf("enter the no of nodes to be inserted");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(&root,newnode(data));
	}
	mypush(&s,root);
   //	mypop(&s,&temp);
     //	printf("%d",temp->data);
	i=0;
	while(s.top!=-1 )
	{
		mypop(&s,&temp);
		printf("%d\t",temp->data);
		if(temp->right!=NULL)
			mypush(&s,root->right);
		if(temp->left!=NULL)
			mypush(&s,root->left);
		printf("s.top%d\n",s.top);
		i++;
	}
	getch();
}
