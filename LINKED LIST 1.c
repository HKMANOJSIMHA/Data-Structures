#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*STRUCTURE DEFINITIONS*/
struct node
{
    int data;
    struct node* next;
};
/*FUNCTION PROTOTYPES*/
struct node* fnInsert(struct node*,int);
void fndisplay(struct node*);
struct node* getnode();
struct node* fndelete(struct node*); 
/*DRIVER FUNCTION*/
int main(void)
{
    struct node*first=NULL;
    int item,choice;
    for(;;)
    {
        /*CHOICE SELECTION*/
        printf("ENTER THE CHOICE\n");
        printf("1-INSERT\n2-DELETE\n3-DISPLAY\nEXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                  scanf("%d",&item);
                  first=fnInsert(first,item);
                  break;
            case 2:if(first==NULL)
                   printf("LIST IS EMPTY NOTHING TO DELETE\n");
                   else
                  first= fndelete(first);
                   break;
            case 3:fndisplay(first);
                   break;
            case 4:printf("THANK YOU!!!!!\n");
                   exit(0);
            default:printf("INVALID OPTION\n");
            break;
        }//END OF SWITCH
    }//FOR LOOP ENDS
}//END OF DRIVER FUNCTION
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:fnInsert
RETURN TYPE:struct node*
PARAMETERS : struct node*,int
*/
struct node* fnInsert(struct node*f,int x)
{
    struct node*temp;
    temp=getnode();
    temp->data=x;        //INSERTING DATA FIELD INTO NEW NODE
    temp->next=f;        //STORING THE ADDRESS OF FIRST INTO THE ADDRESS FIELD OF NEW NODE i.e INSERTION AT BEGINING
    return temp;
}
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:getnode
RETURN TYPE:struct node*
PARAMETERS :void
*/
struct node* getnode()
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));        //ALLOCATING NEW NODE USING MALLOC
    if(new==0)
    printf("RAM IS FULL\n");
    return new;
}
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:fnDisplay
RETURN TYPE:void
PARAMETERS : struct node*
*/
void fndisplay(struct node*f)
{
    struct node*temp;
    if(f==0)
    {
        printf("LIST IS EMPTY\n");
    }
    temp=f;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);     //WHILE LOOP USED FOR TREVERSAL
        temp=temp->next;
    }
    
}
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:fnDelete
RETURN TYPE:struct node*
PARAMETERS : struct node*
*/
struct node* fndelete(struct node*f)
{
    struct node*temp;
    int x;
    temp=f;  //TAKE A COPY OF NODE TO BE DELETED TO FREE THE SPACE
    f=f->next;  //PONTING f TO THE NEXT ELEMENT
    x=temp->data;
    free(temp); //FREE UP THE MEMORY SPACE
    printf("%d IS DELETED SUCCESSFULLY\n",x);
    return f;
}