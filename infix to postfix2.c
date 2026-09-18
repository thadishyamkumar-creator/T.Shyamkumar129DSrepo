#include <stdio.h>
#include <ctype.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char x)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
        st[++top] = x;
}

char pop()
{
    if(top == -1)
        return '\0';
    return st[top--];
}

int pre(char ch)
{
    switch(ch)
    {
        case '*':
        case '/':
        case '%':
            return 3;

        case '+':
        case '-':
            return 2;

        case '(':
            return 1;

        default:
            return 0;
    }
}

int main()
{
    char ch;
    char infix[MAX], post[MAX];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            post[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && st[top] != '(')
            {
                post[j++] = pop();
            }
            pop();
        }
        else
        {
            while(top != -1 && pre(st[top]) >= pre(ch))
            {
                post[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    while(top != -1)
    {
        post[j++] = pop();
    }

    post[j] = '\0';

    printf("Postfix Expression: %s\n", post);

    return 0;
}