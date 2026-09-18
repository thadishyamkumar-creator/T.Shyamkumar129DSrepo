#include <stdio.h>
#define MAX 5

int queue[MAX],priority[MAX],n = 0;

void insert()
{
	int data, p;

    	if(n == MAX)
    	{
        		printf("Queue is full\n");
        		return;
    	}
	printf("Enter data: ");
    	scanf("%d", &data);

    	printf("Enter priority: ");
    	scanf("%d", &p);

    	queue[n] = data;
    	priority[n] = p;
	n++;
	printf("Element inserted\n");
}

void delete()
{
   	int i, pos = 0;

    	if(n == 0)
	{
        		printf("Queue is empty\n");
        		return;
    	}

    	for(i = 1; i < n; i++)
    	{
        		if (priority[i] < priority[pos])
        		{
        			pos=i;
		        }
    	}	

    	printf("Deleted element: %d\n", queue[pos]);
	for (i = pos; i < n - 1; i++)
    	{
        		queue[i] = queue[i + 1];
        		priority[i] = priority[i + 1];
    	}
	n--;
}
void display()
{
    	int i;
	if (n == 0)
    	{
        		printf("Queue is empty\n");
        		return;
    	}
	printf("\nElement\tPriority\n");
	for (i = 0; i < n; i++)
    	{
        		printf("%d\t%d\n", queue[i], priority[i]);
    	}
}
int main()
{
  	int ch;
	while (1)
    	{
        		printf("\n 1.Insert 2.Delete 3.Display 4.Exit \n");
		printf("Enter choice: ");
        		scanf("%d", &ch);
		switch (ch)
        		{
            	case 1:
                	   insert();
                	   break;
            	case 2:
                   	   delete();
                	   break;
            	case 3:
                   	   display();
                	   break;
            	case 4:
                	   return 0;
            	default:
                	   printf("Invalid choice\n");
        		}	
    	}
	return 0;
}