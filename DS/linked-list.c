#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;               //will store value of datatype int
    struct node *next;      //will store address of node of struct node datatype
};
struct node *head = NULL;

//Display
int display(){
    struct node *t=head;
    if(head==NULL){
        printf("\n LIST IS EMPTY");
    }
    else{
        while(t!=NULL){
            printf("%d --> ",t->info);
            t=t->next;
        }
    }
}

//Insert Start
void insertStart(int no){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    // will create a instance of n having address at *n in memory during execution. Datatype of *n struct node
    // eg: n = [info|address]   =>   n = [22|0203H] where 22 is info and 0203H is address of next n declared.
    n->info = no;           //eg: n = [ 11 | Address]
    if(head==NULL){         // at first time head is always NULL
        n->next = NULL;     // n->next = NULL 
        head = n;           // head --> [11|NULL]
    }
    else{
        n->next = head;     // head --> n --> [11|NULL]
        head = n;
    }                       // head --> [ 10 | Address]  --> [ 11 | NULL]
    display();
}
//Insert End
void insertEnd(int no)
{   struct node *t=head;
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->info = no;
    n->next=NULL;
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
    }   
    display();
}
//Remove Start
void removeStart(){
    int no;
    struct node *t = head;
    if(head==NULL)
    {
        printf("\n List is empty");
    }
    else{
        no=head->info;
       if(head->next==NULL){
           head->next=NULL;
       }
       else{
           head=head->next;
       }
       free(t);
    }
    printf("\n%d is value and new list is :",no);
    display();
}
//Remove End
void removeEnd(){
    int no;
    struct node * t = head,*p;
    if(head==NULL){
        printf("\n List is empty");
    }
    else{
        while(t->next!=NULL){
            p=t;
            t=t->next;
        }
        no = t->info;
        p->next=NULL;
        free(t);
    }
    printf("\n%d is value and new list is :",no);
    display();
}
//Search
void search(){
    int no,i=1;
    printf("\nEnter number to be searched:\t");
    scanf("%d", &no);
    struct node *t = head;
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        while (t!=NULL)
        {
            if(t->info==no){
                printf("\n%d is no and is found at node number %d ",no,i);
                break;
            }
            else{
                t=t->next;
                i++;
            }
        }
        if(t==NULL){
            printf("\nElement Not Found !");
        }
    }
}
//Main
int main()
{
    printf("\n LINKED LIST IMPLEMENTED USING C\n---------------------------------\n");
    int c, no;
    do
    {
        printf("\n\nChoose operations\n1.Insert start\t2.Remove start\t3.Insert End\t4.Remove End\t5.Search\t6.EXIT\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nEnter number to be inserted at start:\t");
            scanf("%d", &no);
            insertStart(no);
            break;
        case 2:
            removeStart();
            break;
        case 3:
            printf("\nEnter number to be inserted at end:\t");
            scanf("%d", &no);
            insertEnd(no);
            break;
        case 4:
            removeEnd();
            break;
        case 5:
            search();
        default:
            break;
        }
    } while (c <= 4);
}