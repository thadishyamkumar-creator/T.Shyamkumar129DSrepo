#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int f=-1,r=-1;

int isfull()
{
	return(f==(r+1)%MAX);
}
int isempty()
{
	return(f==-1);
}
void enqueue(int x) {
    	if (isfull()) {
        		printf("Queue Overflow\n");
        		return;
    	}
 	printf("Enter element:");   
	scanf("%d",&x);
    	if (f== -1)
        		f = 0;

    		r = (r + 1) % MAX;
    		queue[r] = x;
}
void dequeue() {
    	if (isempty()) {
        		printf("Queue Underflow\n");
        		return;
    }

	if (f == r) {
        		f = r = -1; 
        }
    	else {
        		f = (f + 1) %MAX;
        		printf("Deleted element:%d",queue[f]);
    }
}
void display()
{
	if(isempty())
		printf("Queue Empty\n");
	else{
              if(f<=r)
		for(int i=f;i<=r;i++)
			printf("%d ",queue[i]);
		else{
			for(int i=f;i<MAX;i++)	
				printf("%d ",queue[i]);
			for(int i=0;i<=r;i++)
				printf("%d ",queue[i]);
		}
	}	
}
int main()
{
	int ch,x;
	do{
	printf("\n 1.enqueue 2.dequeue 3.display 4.exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:enqueue(x);
			break;
		case 2:dequeue();
			break;
		case 3:display();
			break;
		case 4:exit(0);
		}
	}while(ch!=4);
	return 0;
}
