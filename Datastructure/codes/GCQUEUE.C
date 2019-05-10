		   //circular queue
#include<stdio.h>
#include<conio.h>
#define SIZE 10

struct cqueue{
	int front;
	int rear;
	int arr[SIZE];
};

int isempty(struct cqueue *q)
{
	if(q->front==-1 && q->rear==-1)
		return 1;
	else
		return 0;
}

int isfull(struct cqueue *q)
{
	if((q->rear+1) %SIZE==q->front)
		return 1;
	else
		return 0;
}

int enqueue(struct cqueue *q,int data)
{
	if(isfull(q))
		return 0;
	if(isempty(q)) {
		q->front=0;
		q->rear=0;
		}
	else
	{
		q->rear=(q->rear+1)%SIZE;
	}
	q->arr[q->rear]=data;
	return 1;

}
int dequeue(struct cqueue *q,int *data)
{
	if(isempty(q)){
		return 0;}
	*data=q->arr[q->front];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else
	{
		q->front=(q->front+1)%SIZE;

	}
	return 1;
}

int getfront(struct cqueue *q,int *data)
{
	if(isempty(q))
		return 0;
	else
	{
		*data=q->arr[q->front];
		return 1;
	}
}
int getrear(struct cqueue *q,int *data)
{
	if(isempty(q))
		return 0;
	else
	{
		*data=q->arr[q->rear];
		return 1;
	}
}


void main()
{
	struct cqueue q;
	int data,i,x,n,y;
	q.front=-1;
	q.rear=-1;
	clrscr();


	for(i=1;i<=SIZE;i++)
	{
		enqueue(&q,1);
	}
	for(i=1;i<=SIZE-5;i++)
	{
		dequeue(&q,&data);
	}
	for(i=1;i<=SIZE-5;i++)
	{
		enqueue(&q,2);
	}
	for(i=1;i<=SIZE;i++)
	{
		dequeue(&q,&data);
		printf("%d\n",data);
	}


	getch();

}