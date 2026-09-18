#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int k)
{
    	int index, i;
	index = k % SIZE;
	for (i = 0;i<SIZE;i++)
    	{
        		if (hashTable[index] == -1)
        		{
          		hashTable[index] = k;
         			 return;
        		}
		index = (index + 1) % SIZE;
   	}

   	printf("Hash table is full\n");
}
void display()
{
	int i;
	printf("\nHash Table:\n");
	for(i = 0;i<SIZE;i++)
    	{
        		printf("%d : %d\n",i,hashTable[i]);
    	}
}

int main()
{
    	int n,i,key;
	for(i = 0;i<SIZE;i++)
   	{
        		hashTable[i] = -1;
    	}
	printf("Enter number of elements: ");
    	scanf("%d", &n);
	for (i = 0; i < n; i++)
    	{
        		printf("Enter key: ");
        		scanf("%d", &key);
		insert(key);
    	}
	display();
	return 0;
}