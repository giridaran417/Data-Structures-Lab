		   //circular queue
#include<stdio.h>
#include<conio.h>
#define SIZE 10

struct queue{
	int front;
	int rear;
	int arr[SIZE];
};

int isempty(struct queue *q)
{
	if(q->front==-1 && q->rear==-1)
		return 1;
	else
		return 0;
}

int isfull(struct queue *q)
{
	if(q->rear==SIZE-1)
		return 1;
	else
		return 0;
}

int enqueue(struct queue *q,int data)
{
	if(isfull(q))
		return 0;
	if(isempty(q)) {
		q->front=0;
		q->rear=0;
		}
	else
	{
		q->rear=q->rear+1;
	}
	q->arr[q->rear]=data;
	return 1;

}
int dequeue(struct queue *q,int *data)
{
	if(isempty(q)){
		return 0;}
	*data=q->arr[q->front];
	if(q->front==q->rear)
		q->front=q->rear=-1;
	else
	{
		q->front=q->front+1;

	}
	return 1;
}

int getfront(struct queue *q,int *data)
{
	if(isempty(q))
		return 0;
	else
	{
		*data=q->arr[q->front];
		return 1;
	}
}
int getrear(struct queue *q,int *data)
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
	struct queue q;
	int i,data;
	q.front=-1;
	q.rear=-1;
	clrscr();
	for(i=1;i<=SIZE;i++)
	{
		enqueue(&q,1);
	}
	for(i=1;i<=SIZE;i++)
	{
		dequeue(&q,&data);
		printf("%d\n",data);
	}
	getch();
}