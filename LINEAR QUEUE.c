#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int elements[5];
    int front;
    int rear;
};
typedef struct queue QUE;
void fnInsert(QUE*,int);
int fnDelete(QUE*);
void fnDisplay(QUE*);
int main()
{
    QUE q;
    int item,choice,Ditem,flag1,flag2,i;
     q.front=0;
     q.rear=-1;
     for(;;)
    {
    printf("ENTER YOUR CHOICE\n:");
    printf("1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:if(q.rear==4)
               {
               printf("QUEUE OVERFLOW\n");
               break;
               }
               else
               {
               printf("ENTER THE ELEMENT TO BE INSERTED:");
               scanf("%d",&item);
               fnInsert(&q,item);
               break;
               }
        case 2:if(q.front>q.rear)
               { 
               printf("QUEUE UNDERFLOW\n");
               break;
               }
               else 
               {
               Ditem=fnDelete(&q);
               printf("%d IS DELETED SUCCESSFULLY\n",Ditem);
               break;
               }
        case 3:fnDisplay(&q);
               break;
        case 4:printf("THANK YOU!!!!\n");
               exit(0);
    }
    }
    return 0;
}
void fnInsert(QUE*q,int item)
{
    q->rear++;
    q->elements[q->rear]=item;
}
int fnDelete(QUE*q)
{
    int x;
    x=q->elements[q->front];
    q->front++;
    return x;
}
void fnDisplay(QUE*q)
{
    int i;
    if(q->front>q->rear)
        printf("QUEUE IS EMPTY\n");
    else if(q->front!=q->rear)
    {
    for(i=q->rear;i>=0;i--)
    {
        if(i!=q->front-1)
        {
        if(i==q->front)
        printf("%d <-FRONT END\n",q->elements[i]);
        else if(i==q->rear)
        printf("%d <-REAR END\n",q->elements[i]);
        else
        printf("%d\n",q->elements[i]);
        }
    }
    }
    else
    printf("%d <-FRONT & REAR\n",q->elements[q->rear]);
}