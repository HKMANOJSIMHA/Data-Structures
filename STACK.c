#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int element[MAX];
    int top;
};
typedef struct stack STACK;
void fnPush(STACK*,int);
void fnPop(STACK*);
void fndisplay(STACK*);
int main()
{
    STACK s;
     s.top=-1;
    int choice,item;
    for(;;)
    {
        printf("ENTER YOUR CHOICE:\n1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(s.top==MAX-1)
                  {
                    printf("STACK OVERFLOW\n");
                    break;
                  }
                  printf("ENTER THE ELEMENT TO BE INSERTED\n");
                  scanf("%d",&item);
                  fnPush(&s,item);
                  break;
            case 2:if(s.top==-1)
                   {
                       printf("STACK UNDERFLOW\n");
                       break;
                   }
                   fnPop(&s);
                   break;
            case 3:if(s.top==-1)
                   {
                       printf("STACK IS EMPTY\n");
                       break;
                   }
                   fndisplay(&s);
                   break;
            case 4:printf("THANK YOU\n");
                   exit(0);
            default:printf("INVALID CHOICE\n");
               
        }
    }
}//end of main
void fnPush(STACK*s,int x)
{
    s->top++;
    s->element[s->top]=x;
}
void fnPop(STACK*s)
{
    int x;
    x=s->element[s->top];
    s->top--;
    printf("ITEM DELETED IS %d\n",x);
}
void fndisplay(STACK*s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {
        if(i==s->top)
        printf("%d <- TOP\n",s->element[i]);
        else
        printf("%d\n",s->element[i]);
    }
}