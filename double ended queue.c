#include <stdio.h>
#define MAX 5

int deque[MAX],f=-1,r=-1;

void insertFront()
{
    int x;
    if(f==0)
    {
        printf("Deque is full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if(f == -1)
    {
        f = r = 0;
    }
    else
    {
    deque[f--] = x;
    }
}
void insertRear()
{
    int x;
    if (r == MAX - 1)
    {
        printf("Deque is full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (f == -1)
    {
        f = r = 0;
    }
    else
    {  
    	 deque[++r] = x;
    }   
}

void deleteFront()
{
    if (f == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element: %d\n", deque[f]);
    if (f == r)
    {
        f = r = -1;
    }
    else
    {
        f++;
    }
}
void deleteRear()
{
    if (r == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted element: %d\n", deque[r]);

    if (f == r)
    {
        f = r = -1;
    }
    else
    {
        r--;
    }
}

void display()
{
    int i;

    if (f == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");

    for (i = f; i <= r; i++)
    {
        printf("%d ", deque[i]);
    }

    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n");
        printf("1.Insert Front 2.Insert Rear 3. Delete Front 4.Delete rear 5.Display 6.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}