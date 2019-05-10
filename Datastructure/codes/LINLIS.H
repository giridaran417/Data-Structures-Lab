struct ll {
	int data;
	struct ll *next;
};

int search(struct ll *head,int data,struct ll **prev);
int insert(struct ll **head,int data);
int ldelete(struct ll **head,int data);
void traverse(struct ll *head);