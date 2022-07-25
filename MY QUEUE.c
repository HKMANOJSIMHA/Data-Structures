#include<stdio.h>
#include<stdlib.h>
/*structure definition*/
struct queue 
{
    int elements[1000];
    int front;
    int rear;
};
typedef struct queue QUE;
void fnInsert(QUE*,int);     //function to insert an element at the rear end
int fnDelete(QUE*);         //function to delete an element from the front end
void fnDisplay(QUE*);      //function to display the items present in the queue
int main()
{
    QUE q;
    int item,choice,Ditem,i,n;
     q.front=0;       //initial condition for front
     q.rear=-1;      //initial condition for rear
     printf("ENTER THE MAX SIZE OF QUEUE U WANT TO DESIGN:");
     scanf("%d",&n);
     for(;;)
    {
        /*THIS IF CONDITION INITIALIZES REAR AND FRONT BACK TO -1 AND 0 RESPECTIVELY WHICH ARE THE INITIAL CONDITIONS 
        WHEN THE ALL THE INSERTED ELEMENTS ARE DELETED  AND WE CAN AGAIN ADD MAXSIZE ELEMENTS INTO THE QUEUE*/
         if(q.front>q.rear)
               {
                   q.front=0;
                   q.rear=-1;
               }
    printf("ENTER YOUR CHOICE\n:");
    printf("1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        /*CHOICE 1 PERFORMS THE INSERT OPERATION AS BELOW */
        case 1:if(q.rear==n-1)
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
         /*CHOICE 2 DELETE AN ELEMENT FROM FRONT END AS BELOW */     
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
               /* DISPLAY FUNCTION DISPLAY THE ELEMENTS PRESENT IN THE QUEUE AT THAT INSTANT */
        case 3:fnDisplay(&q);
               break;
               /* TO VOLUNTAIRLY EXIT THE PROGRAM */
        case 4:printf("THANK YOU!!!!\n");
               exit(0);
    }
    }
    return 0;
}
/*
NAME OF FUNCTION:fnInsert
AUTHOR:H K MANOJ
DATE:08-12-2020
ARGUMENTS:QUE*,int
RETURN TYPE:void
*/
void fnInsert(QUE*q,int item)
{
    q->rear++;
    q->elements[q->rear]=item;  //logic for insertion 
}
/*
NAME OF FUNCTION:fnDelete
AUTHOR:H K MANOJ
DATE:08-12-2020
ARGUMENTS:QUE*
RETURN TYPE:int
*/
int fnDelete(QUE*q)
{
    int x,i;
    x=q->elements[q->front]; //logic for deletion
    q->front++;
    for(i=0;i<q->rear;i++)    /*this for loop is used to shift each element one position back so that we can create an empty space*/
    {
        q->elements[i]=q->elements[q->front]; //logic to move elements backwards by on position
        q->front=q->front+1;
    }
    q->rear=q->rear-1; /*soon after shifting we have to make rear pointing the same element 
                        which it was pointing previously, by decrimenting rear by 1*/
   
    q->front=0; //logic to set front to its original position which it was pointing after deletion

    return x;
}
/*
NAME OF FUNCTION:fnDisplay
AUTHOR:H K MANOJ
DATE:08-12-2020
ARGUMENTS:QUE*
RETURN TYPE:void
*/
void fnDisplay(QUE*q)
{
    int i;
    if(q->front>q->rear)          //if condition to display the emptyness of queue
        printf("QUEUE IS EMPTY\n");   
    else if(q->front!=q->rear)       //if condition to check whether front and rear are pointing to same element or not
    {
    for(i=q->front;i<=q->rear;i++)
    {
        if(i==q->front)                  //if i is holding the front index then mark that element as front end
        printf("%d <-FRONT END\n",q->elements[i]);  
        else if(i==q->rear)             //if i is holding the rear index the mark that element as rear end
        printf("%d <-REAR END\n",q->elements[i]);
        else                            //if i is between front and rear end just print the value present at ith index
        printf("%d\n",q->elements[i]);
    }
    }
    else
    printf("%d <-FRONT & REAR\n",q->elements[q->rear]);  //if front and rear are same then display both front and rear end to that element
}