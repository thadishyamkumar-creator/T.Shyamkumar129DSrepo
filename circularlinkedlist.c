#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void insert()
{
    struct node *temp, *n;
    int pos, ch, c;

    n = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &n->data);

    if (start == NULL)
    {
        start = n;
        n->next = start;
    }
    else
    {
        printf("\n1.Start 2.End 3.Position\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            temp = start;

            while (temp->next != start)
                temp = temp->next;

            n->next = start;
            temp->next = n;
            start = n;
            break;
        case 2:
            temp = start;

            while (temp->next != start)
                temp = temp->next;

            temp->next = n;
            n->next = start;
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);

            if (pos == 1)
            {
                temp = start;

                while (temp->next != start)
                    temp = temp->next;

                n->next = start;
                temp->next = n;
                start = n;
            }
            else
            {
                temp = start;
                c = 1;

                while (c < pos - 1 && temp->next != start)
                {
                    temp = temp->next;
                    c++;
                }

                n->next = temp->next;
                temp->next = n;
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
        if (start->next == start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            temp = start;

            while (temp->next != start)
                temp = temp->next;

            t = start;
            start = start->next;
            temp->next = start;

            free(t);
        }
        break;
    case 2:
        if (start->next == start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            temp = start;

            while (temp->next != start)
            {
                t = temp;
                temp = temp->next;
            }

            t->next = start;
            free(temp);
        }
        break;
    case 3:
        printf("Enter position: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            if (start->next == start)
            {
                free(start);
                start = NULL;
            }
            else
            {
                temp = start;

                while (temp->next != start)
                    temp = temp->next;

                t = start;
                start = start->next;
                temp->next = start;

                free(t);
            }
        }
        else
        {
            temp = start;
            c = 1;
            while (c < pos - 1 && temp->next != start)
            {
                temp = temp->next;
                c++;
            }
            if (temp->next != start)
            {
                t = temp->next;
                temp->next = t->next;
                free(t);
            }
            else
            {
                printf("Invalid Position\n");
            }
        }
        break;
    default:
        printf("Invalid Choice\n");
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

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != start);
        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n 1.insert 2.delete 3.display 4.exit\n");
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
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    } while (ch != 4);
    return 0;
}