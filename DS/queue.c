#include<stdio.h>
# define size 10
int queue[size];
int front=-1, rear=-1;

//Display
int display(){
     int i;
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\n Elements in Queue are:\t");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
//Insert
int insertq(int value){
    if(rear == size-1){
        printf("Queue is full");
    }
    else{
        if(front==-1 && rear==-1){
            front = rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = value;
    }
    display();
}
//Remove
int removeq(){
    int value;
    if(front==-1 && rear==-1){
        printf("");
    }
    else{
        value = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else{
            front++;
        }
    }
    display();
}
//Main
int main()
{
    printf("\n QUEUE IMPLEMENTED USING C\n---------------------------------\n");
    int c, no;
    do
    {
        printf("\n\nChoose operations\n1.Insert\t2.Remove\t3.EXIT\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nEnter number to be inserted:\t");
            scanf("%d", &no);
            insertq(no);
            break;
        case 2:
            removeq();
            break;
        default:
            break;
        }
    } while (c <= 2);
}