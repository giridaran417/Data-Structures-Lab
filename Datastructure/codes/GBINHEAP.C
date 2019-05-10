#include<stdio.h>
#include<conio.h>
#define CAP 20
#include<math.h>

struct binheap
{
	int arr[CAP];
	int size;
};

int insert(struct binheap *h,int data)
{
	int i;
	if(h->size==CAP)
		return 0;
	printf("size %d",h->size);
	for(i=1+(h->size); h->arr[(i/2)]>data;i=i/2)
	{
	       //	printf("i= %d\n",h->arr[(i/2)]);
		h->arr[i]=h->arr[(i/2)];

	}
      //	printf("asdf\n");
	h->arr[i]=data;
	h->size+=1;
     //	printf("size %d",h->size);
	return 1;
}

int deletemin(struct binheap *h,int *min)
{
	int lastelement,child,i;
	if(h->arr[h->size]==0)
		return 0;
	if(h->arr[h->size]==1)
	{
		*min=h->arr[1];
		h->size=h->size-1;
		return 1;
	}
	*min=h->arr[1];
	lastelement=h->arr[h->size];
	for(i=1;i*2<=h->size;i=child)
	{
		child=2*i;
		if(child!=h->size && h->arr[child+1]<h->arr[child])
			child++;
		if(lastelement>h->arr[child])
			h->arr[i]=h->arr[child];
		else
			break;
	}
	h->arr[i]=lastelement;
	h->size-=1;
	return 1;
}

void buildheap(struct binheap *h)
{
	int i,j,child,temp;
	for(i=(h->size)/2;i>=1;i--)
	{
		for(j=i;j*2<=h->size;j=child)
		{
			child=2*j;
			if(child!=h->size && h->arr[child+1]<h->arr[child])
				child++;
			if(h->arr[i]>h->arr[child])
			{
			temp=h->arr[i];
			h->arr[i]=h->arr[child];
			h->arr[child]=temp;
			}
		}
	}
}

void main()
{
	struct binheap *h;
	int i,n,data,min=0;
	h->arr[0]=-32000;
	clrscr();
	printf("enter how many values to be inserted\n");
	scanf("%d",&n);
	h->size=n;
	for(i=1;i<=n;i++)
	{
		printf("enter the data to be inserted\n");
		scanf("%d",&h->arr[i]);
	}
	buildheap(h);
      //	printf("the value of min after buliding heap is %d\n",h->arr[2]);
	insert(h,1);
	deletemin(h,&min);
	deletemin(h,&min);
	deletemin(h,&min);
	printf("the value of min after delting  is %d\n",h->arr[1]);
	getch();
}