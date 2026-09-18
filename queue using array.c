#include <stdio.h>
#include <stdlib.h>
#define Max 20

int que[Max],r=-1,f=-1,i;
void enqueue(int x)
{
	if(r==Max-1)
		printf("queue is overflow");
	else
		que[++r]=x;	
}

int dequeue()
{
	if(r==f)
	{
		printf("queue is underflow");
		return -1;
	}
	else
		return(que[++f]);	
}

void display()
{
	if(f==r)
		printf("queue is empty");
	else
	{
		printf("queue content now\n");
		for(i=f+1;i<=r;i++){
			printf("%d ",que[i]);
		}
		printf(" \n");
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