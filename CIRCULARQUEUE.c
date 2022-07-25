#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct cqueue 
{
    int element[100];
    int front;
    int rear;
    int count;
};
typedef struct cqueue CQ;
void fnInsert(CQ*);
void fnDelete(CQ*);
void fnDisplay(CQ*);
int main()
{
    CQ q;
    int choice,n;
    q.front=0;
    q.rear=-1;
    q.count=0;
    for(;;)
    {
        printf("ENTER YOUR CHOICE\n1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(q.count==MAX)
                 {
                   printf("QUEUE OVERFLOW\n");
                   break;
                 }
                 else
                 {
                   fnInsert(&q);
                   break;
                 }
            case 2:if(q.count==0)
                {
                   printf("QUEUE UNDERFLOW\n");
                   break;
                }
                else
                {
                    
                    fnDelete(&q);
                    break;
                }
            case 3:if(q.count==0)
                   {
                       printf("QUEUE IS EMPTY\n");
                       break;
                   }
                   else
                   {
                       fnDisplay(&q);
                       break;
                   }
            case 4:printf("THANK YOU!!!!\n");
                   exit(0);
        }
    }
}/*end of main*/
void fnInsert(CQ*q)
{
    int item;
    printf("ENTER THE ITEM TO BE INSERTED:");
    scanf("%d",&item);
    q->rear=(q->rear+1)%MAX;
    q->count++;
    q->element[q->rear]=item;
}
void fnDelete(CQ*q)
{
    int x;
    x=q->element[q->front];
    q->front=(q->front+1)%MAX;
    q->count--;
    printf("%d IS DELETED SUCCESSFULLY\n",x);
}
void fnDisplay(CQ*q)
{
    int i;
    if(q->front==q->rear)
    printf("%d <- REAR AND FRONT\n",q->element[q->front]);
    else
    {
        for(i=q->front;i<=q->rear;i++)
      {
        if(i==q->front)
        printf("%d <-FRONT END\n",q->element[i]);
        else if(i==q->rear)
        printf("%d <-REAR END\n",q->element[i]);
        else
        printf("%d\n",q->element[i]);
      }
    }
}