#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
	printf("Stack is Overflow\n");
    else
    {
	printf("Enter the data: ");
    	scanf("%d", &n->data);

    	n->next = top;
    	top = n;

   	printf("Element pushed successfully.\n");
    }
}

void pop()
{
    struct node *temp;

    if (top == NULL)
        	printf("Stack is Underflow\n");
    else
    {
    	temp = top;
    	printf("Deleted element: %d\n", temp->data);

    	top = top->next;
    	free(temp);
    }
}

void display()
{
    struct node *temp;

    if (top == NULL)
    {
       	 printf("Stack is Empty\n");
       	 return;
    }

	printf("Stack elements are:\n");

    	temp = top;
    while (temp != NULL)
    {
        	printf("%d\n", temp->data);
        	temp = temp->next;
    }
}

int main()
{
    int ch;

    do
    {
       	 printf("\n 1.Push 2.Pop 3.Diplay 4.Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (ch != 4);
}