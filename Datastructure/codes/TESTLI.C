#include<stdio.h>
#include<conio.h>
#include<linlis.h>
void main()
{
	struct ll *head=NULL,*prev=NULL;
	clrscr();
	insert(&head,5);
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);

	if(search(head,5,&prev))
	{
		printf("yes ");
	}
	traverse(head);
	ldelete(&head,10);
	traverse(head);
	getch();


}
