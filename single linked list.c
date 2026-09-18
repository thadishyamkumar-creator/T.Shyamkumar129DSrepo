#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next,*prev;
}*start=NULL;
void insert()
{
	struct node *t,*temp,*n;
	int pos,ch,c;
	n=(struct node*)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d",&n->data);
	n->next=NULL;
	n->prev=NULL;
	if(start==NULL)
		start=n;
	else
	{
		printf("\n1.start 2.end 3.pos\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1:
            n->next=start;
            start->prev=n;
            start=n;
            break;
	case 2:
            temp=start;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=n;
            n->prev=temp;
            break;
	case 3:
            printf("enter the pos:");
            scanf("%d",&pos);
          	if(pos==1)
            	{
             	   n->next=start;
                       start->prev=n;
                       start=n;
         		}
          	else
          	{
          	   temp=start;	
          	   c=1;
          	   while(c!=pos&&temp!=NULL)
                    {
                       t=temp;
                       temp=temp->next;
                       c++;
          	}
               		if(c==pos)
                		{
                		   n->next=temp;
                		   n->prev=t;
                		   temp->prev=n;
                    	   t->next=n;
                		}
                		else
                    	   printf(" invalid pos");
                	}
        
    	}
     }
}
void delete()
{
    if(start==NULL)
    printf("list is empty!");
    else
    {
        struct node *temp,*t,*n;
        int ch,c=1,pos;
        printf("\n1.start 2.end 3.pos\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                temp=start;
                start=start->next;
                if(start!=NULL);
                   start->prev=NULL;
                   free(temp);
                break;
            case 2:
                temp=start;
                while(temp->next!=NULL)
                {
                    t=temp;
                    temp=temp->next;
       	      }
                    t->next=NULL;
                    free(temp);
                    break;
            case 3:
                printf("enter pos:");
                scanf("%d",&pos);
                if(pos==1)
                {
                    temp=start;
                    start=start->next;
                    start->prev=NULL;
                    free(temp);
                }
                else
                {
                    temp=start;
                    while(c!=pos&&temp!=NULL)
                    {
                       temp=temp->next;
                        c++;
                    }
                    if(c==pos)
                    {
                        temp->prev->next=temp->next;
                        temp->next-> prev=temp->prev;
                        free(temp);
                    }
                    else
                    printf("invalid pos");
                }
        }
    }
}
void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("list is empty");
    else
    {
        printf("\n the list is:");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n 1.insert 2.delete 3.display 4.exit\n");
        scanf("%d",&ch);
        switch(ch)
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
                exit(0);
        }
    }while(ch!=4);
}