
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef struct Node *linklist;
linklist init_create()
{
	linklist L;
	L=(linklist)malloc(sizeof(Node));
	L->next=NULL;
	return L;
}
int insert_list(linklist L,int num,int place)
{
	linklist pnew,p;
	p=L;
	int i=0;
	while(i<place-1&&p!=NULL)
	{
		p=p->next;
		i++;
	}
	if(i>place-1||p==NULL)
	{
		printf("out of space\n");
		return 0;
	}
	else{
		pnew=(linklist)malloc(sizeof(Node));
		pnew->data=num;
		pnew->next=p->next;
		p->next=pnew;
		return 1;
	}
 } 
 void show(linklist L)
 {
 	linklist p;
 	p=L->next;
 	while(p!=NULL)
 	{
 		printf("%4d",p->data);
 		p=p->next;
	 }
 }
 int main()
 {
 	linklist l;
 	l=init_create();
 	for(int i=1;i<=10;i++)
 {
 	insert_list(l,i,i);
 }
 show(l);
 return 0;
}
