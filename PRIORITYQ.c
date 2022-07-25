/*Program to implement priority queue
 * Author:RGY
 * Date:14-12-2020
 */
/*Preprocessor directives*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
/*Structure specification for the priority queue*/
 struct queue
{
        int Elements[MAXSIZE];
        int front;
        int rear;
};
typedef struct queue PQUEUE;
/*Function prototypes*/
void fnInsertRear(PQUEUE*,int);
void fnDeleteFront(PQUEUE*);
void fnDisplay(PQUEUE);
int fnIsFull(PQUEUE);
int fnIsEmpty(PQUEUE);
/*Driver program*/
/*Function name:main
* arguments:void
* return type:int
* Author:RGY
* Date:15-12-2020
*/
int main(void)
{

       /*Create the priority queue*/
       PQUEUE Q;
       int iItem,iChoice;
       Q.front=0;
       Q.rear=-1;
       /*Infinite loop to display the menu of operations*/
       while(TRUE)
       {
               printf("1:Insert\n2:Delete\n3:Display\n4:Exit\n");
               printf("Please choose from the above list\n");
               scanf("%d",&iChoice);
               switch(iChoice)
               {
                       case 1:
                               printf("Enter the item to be inserted\n");
                               scanf("%d",&iItem);
                               fnInsertRear(&Q,iItem);
                               break;
                        case 2:
                                fnDeleteFront(&Q);
                                       break;
                        case 3:
                                fnDisplay(Q);
                                break;
                        case 4:
                                printf("Thanks for using our App\n");
                                exit(0);
                        default:
                                printf("Invalid choice\n");
                                break;
                }/*switch ends here*/
        }/*Infinite loop ends here*/
        /*Return to Operating system on success*/
        return 0;
}/*End of driver program(module)*/
/*Function definitions*/
/*Function name:fnInsertRear
 * arguments:PQUEUE*,int
 * return type:void
 * Author:RGY
 * Date:15-12-2020
 */
void fnInsertRear(PQUEUE* q,int x)
{
        int j;
        if(fnIsFull(*q))
        {
                printf("Queue overflow\n");
                /*return without inserting*/
                return;
        }
        /*Start comparing item to be inserted with existing
          members of the queue from rear end hence j holds rear value*/
        j=q->rear;
        while(j>=0&&x<q->Elements[j])
        {
                /*Shift elements by one location each time above
                  conditions hold good to make the room for new element*/
                q->Elements[j+1]=q->Elements[j];
                j--;
        }
        /*Insertion of item*/
        q->Elements[j+1]=x;
        q->rear++;
        /*Return after inserting item as per its priority*/
        return;
}/*End of fnInsertRear*/
/*Function name:fnDeleteFront
 * arguments:PQUEUE*
 * return type:void
 * Author:RGY
 * Date:15-12-2020
 */
void fnDeleteFront(PQUEUE* q)
{
        int x;
        if(fnIsEmpty(*q))
        {
                printf("Queue Underflow\n");
                /*return without deleting*/
                return;
        }
        /*Take the backup of item to be deleted*/
        x=q->Elements[q->front];
        /*By incrementing front we are losing access to the current
          element in the front of the queue, bringing the effect of
          deletion*/
        q->front++;

        printf("Deleted item is:%d\n",x);
        /*Return after successful deletion*/
        return;
}/*End of fnDeleteFront*/
/*Function name:fnDisplay
 * arguments:PQUEUE
 * return type:void
 * Author:RGY
 * Date:15-12-2020
 */
void fnDisplay(PQUEUE q)
{
        int i;
        if(fnIsEmpty(q))
        {
                printf("Queue is empty\n");
                return;
        }
        printf("Elements of queue are:\n");
        for(i=q.front;i<=q.rear;i++)
        {
                printf("%d\n",q.Elements[i]);
        }
        return;
}/*End of fnDisplay*/

/*Function name:fnIsFull
 * arguments: PQUEUE
 * return type: int(bool)
 * Author:RGY
 * Date:15-12-2020
 */
int fnIsFull(PQUEUE q)
{
        return ((q.rear==MAXSIZE-1)?1:0);
}/*End of fnIsFull*/
/*Function name:fnIsEmpty
 * arguments: PQUEUE
 * return type: int(bool)
 * Author:RGY
 * Date:15-12-2020
 */
int fnIsEmpty(PQUEUE q)
{
        return ((q.front>q.rear)?1:0);
}/*End of fnIsEmpty*/
