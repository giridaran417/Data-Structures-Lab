#include<stdio.h>
#include<conio.h>
#define SIZE 10

struct linhash
{
	int flag;
	int data;
};

int hashfun(int x)
{
	x=x%SIZE;
	return (x);
}

int resfun(int temp,int k)
{
	temp=(k+temp)%SIZE;
	return temp;
}

void main()
{
	struct linhash a[SIZE]={0,0};
	int i,n,a1,k,slot,temp;
	clrscr();
	printf("Enter no. of inserts:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1);
		slot=hashfun(a1);
		temp=slot;
		k=1;
		while((a[slot].data)!=0)
		{
			slot=resfun(temp,k);
			++k;
		}
		printf("slot=%d\n",slot);
		a[slot].data=a1;
	}
	printf("Enter no. of deletions:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1);
		slot=hashfun(a1);
		temp=slot;
		k=1;
	while(!(a[slot].data==0 && a[slot].flag==0))
	{
		if(a[slot].data==a1)
		{
			break;
		}
		else
		{
			slot=resfun(temp,k);
			++k;
		}
	}
	if(a[slot].data==a1)
	{
		a[slot].data=0;
		a[slot].flag=1;
	}
	else
	{
		printf("NOT FOUND\n");
	}
	}
	//printf("%d\t%d\t%d\t%d\t%d",a[0].data,a[1].data,a[2].data,a[3].data,a[4].data);
	getch();
}

