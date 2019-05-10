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

int resfun(int h0,int h2,int k)
{
	h0=(h0+(k*h2))%SIZE;
	return h0;
}

void main()
{
	struct linhash a[SIZE]={0,0};
	int i,n,a1,k,slot,r=7,h0,h2;
	clrscr();
	printf("Enter no. of inserts:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a1);
		slot=hashfun(a1);
		h0=slot;
		h2=r-(a1%r);
		k=1;
		while((a[slot].data)!=0)
		{
			slot=resfun(h0,h2,k);
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
		h0=slot;
		h2=r-(a1%r);
		k=1;
	while(!(a[slot].data==0 && a[slot].flag==0))
	{
		if(a[slot].data==a1)
		{
			break;
		}
		else
		{
			slot=resfun(h0,h2,k);
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
	printf("\nHASH TABLE:\n\n");
	for(i=0;i<SIZE;i++)
	{
		printf("\t\t\t%d | %2d |\n",i,(a[i].data));
	}
	printf("\n\n");
	getch();
}

