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
void fnpriority(CQ*);
int main()
{
    CQ q;
    int choice;
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
                   printf("---------------------------------------------\n");
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
                   printf("---------------------------------------------\n");
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
                       printf("---------------------------------------------\n");
                       break;
                   }
                   else
                   {
                       fnDisplay(&q);
                       break;
                   }
            case 4:printf("THANK YOU!!!!\n");
                printf("---------------------------------------------\n");
                   exit(0);
            default:printf("INVALID CHOICE\n");
                     printf("---------------------------------------------\n");
                    break;
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
    fnpriority(q);
    printf("%d IS INSERTED SUCCESSFULLY\n",item);
   printf("---------------------------------------------\n");

}
void fnDelete(CQ*q)
{
    int x;
    x=q->element[q->front];
    q->front=(q->front+1)%MAX;
    q->count--;
    printf("%d IS DELETED SUCCESSFULLY\n",x);
   printf("---------------------------------------------\n");

}
void fnDisplay(CQ*q)
{
    int i,f;
    f=q->front;
    if(q->front==q->rear)
    printf("%d <- REAR AND FRONT\n",q->element[q->front]);
    else
    {
        for(i=0;i<q->count;i++)
      {
        if(f==q->front)
        printf("%d <-FRONT END\n",q->element[f]);
        else if(f==q->rear)
        printf("%d <-REAR END\n",q->element[f]);
        else
        printf("%d\n",q->element[f]);
        f=(f+1)%MAX;
      }
    }
    printf("---------------------------------------------\n");
}
void fnpriority(CQ*q)
{
    int i,j,swap;
    int f=q->front;
        for(i = 0 ; i < q->count - 1; i++)
         {
             f=q->front;
          for(j = 0 ; j < q->count-i-1; j++)
             {
                 if(q->element[f] > q->element[(f+1)%MAX]) 
                   {
                       swap=q->element[f];
                       q->element[f]=q->element[(f+1)%MAX];
                       q->element[(f+1)%MAX]=swap;
                   }
                   f=(f+1)%MAX;
             }
         }

}