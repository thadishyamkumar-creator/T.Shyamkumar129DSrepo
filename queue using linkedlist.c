#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
	struct node*nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=NULL;
	
	if(front==NULL)
		front=rear=nn;
	else{
		rear->next=nn;
		rear=nn;
	}
}
int dequeue()
{
	if(front==rear)
		printf("queue is underflow");
	else{
		struct node*temp=front;
		front=front->next;
		free(temp);
	}	
}
void display()
{
	if(front==rear)
		printf("queue is empty");
	else
	{
		struct node*temp=front;
		printf("queue content now!!!");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
				}		
	}
}
int main()
{
	int ch,x;
	do
	{
		printf("\n 1.enqueue 2.dequeue 3.display 4.Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("Enter x\n");
				   scanf("%d",&x);
				   enqueue(x);
				   break;
				   
			case 2:printf("Deleted element %d",dequeue());
				   break;
				   
			case 3:display();
				   break;
				   
			case 4:exit(0);			   	   
		}
	}while(ch!=4);
	return 0;
}