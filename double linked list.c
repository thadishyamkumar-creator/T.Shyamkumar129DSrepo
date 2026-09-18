#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *start = NULL;

void insert()
{
    struct node *t, *temp, *n;
    int pos, ch, c;

    n = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &n->data);

    n->next = NULL;
    n->prev = NULL;

    if (start == NULL)
    {
        start = n;
    }
    else
    {
        printf("\n1.Start 2.End 3.Position\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            n->next = start;
            start->prev = n;
            start = n;
            break;

        case 2:
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = n;
            n->prev = temp;
            break;

        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);

            if (pos == 1)
            {
                n->next = start;
                start->prev = n;
                start = n;
            }
            else
            {
                temp = start;
                c = 1;

                while (c < pos - 1 && temp != NULL)
                {
                    temp = temp->next;
                    c++;
                }

                if (temp != NULL)
                {
                    n->next = temp->next;
                    n->prev = temp;

                    if (temp->next != NULL)
                        temp->next->prev = n;

                    temp->next = n;
                }
                else
                    printf("Invalid Position\n");
            }
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
}

void deleteat()
{
    struct node *temp, *t;
    int ch, pos, c;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\n1.Start 2.End 3.Position\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:

        temp = start;

        if (start->next == NULL)
        {
            start = NULL;
        }
        else
        {
            start = start->next;
            start->prev = NULL;
        }

        free(temp);
        break;

    case 2:

        temp = start;

        if (start->next == NULL)
        {
            start = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
            {
                t = temp;
                temp = temp->next;
            }

            t->next = NULL;
            free(temp);
        }

        break;

    case 3:

        printf("Enter position: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            temp = start;

            if (start->next == NULL)
            {
                start = NULL;
            }
            else
            {
                start = start->next;
                start->prev = NULL;
            }

            free(temp);
        }
        else
        {
            temp = start;
            c = 1;

            while (c < pos && temp != NULL)
            {
                temp = temp->next;
                c++;
            }

            if (temp != NULL)
            {
                temp->prev->next = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                free(temp);
            }
            else
                printf("Invalid Position\n");
        }

        break;

    default:
        printf("Invalid Choice\n");
    }
}

void forward()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Forward: ");

        temp = start;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void backward()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;

        while (temp->next != NULL)
            temp = temp->next;

        printf("Backward: ");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }

        printf("\n");
    }
}

void display()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List: ");

        temp = start;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n------ Doubly Linked List ------\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Backward Traversal\n");
        printf("5.Forward Traversal\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            deleteat();
            break;

        case 3:
            display();
            break;

        case 4:
            backward();
            break;

        case 5:
            forward();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }

    } while (ch != 6);

    return 0;
}