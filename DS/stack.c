#include <stdio.h>
#include <stdlib.h>

int top = -1;
int stack[10];

int push(int no)
{
    if (top == 9)
    {
        printf("\nStack is full");
    }
    else
    {
        top++;
        stack[top] = no;
    }
}
int pop(int no){
    if (top==-1)
    {
        printf("\nStack is empty");
    }
    else{
        printf("\nValue popped from stack is:\t%d",stack[top]);
        stack[top] = 0;
        top--;
    }
    
}
int peek(){
    printf("%d is top most element of stack",stack[top]);
}
int display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("\n Elements of stack are:\t");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
int main()
{
    printf("\n STACK IMPLEMENTED USING C\n---------------------------------\n");
    int c, no;
    do
    {
        printf("\n\nChoose operations\n1.PUSH\t2.POP\t3.PEEK\t4.DISPLAY\t5.EXIT\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nEnter number to be pushed:\t");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop(no);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    } while (c <= 4);
}