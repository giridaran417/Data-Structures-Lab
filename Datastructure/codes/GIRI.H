#define SIZE 10
struct giri
{
	char arr[SIZE];
	char top;
};
int myisFull(struct giri *);
int myisEmpty(struct giri *);
int myPush(struct giri *,int);
int myPop(struct giri *,int *);
int myPeek(struct giri *,int *);