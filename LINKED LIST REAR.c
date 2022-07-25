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
struct node* fnInsert(int);
void fndisplay(struct node*);
struct node* getnode();
struct node* fndelete(struct node*); 
/*DRIVER FUNCTION*/
int main(void)
{
    struct node*first=NULL,*new,*temp;
    int item,choice;
    for(;;)
    {
        /*CHOICE SELECTION*/
        printf("ENTER THE CHOICE\n");
        printf("1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                  scanf("%d",&item);
                  new=fnInsert(item);
                  if(first==NULL) //FOR INITIAL INSERTION
                  first=new;
                  else
                  {
                    while(temp->next!=NULL)  //WHILE LOOP TO TRAVERSE TO THE END NODE TO INSERT THE NEW TO THAT NODE
                     {
                      temp=temp->next;
                     }
                  }
                  temp->next=new;  //INSERTION OF NEW NODE AT THE END
                    printf("__________________________________________\n");
                  break;
            case 2:if(first==NULL)
                   printf("LIST IS EMPTY NOTHING TO DELETE\n");
                   else
                  first= fndelete(first);
                    printf("__________________________________________\n");
                   break;
            case 3:fndisplay(first);
                   break;
            case 4:printf("THANK YOU!!!!!\n");
                       printf("__________________________________________\n");
                   exit(0);
        }//END OF SWITCH
    }//FOR LOOP ENDS
}//END OF DRIVER FUNCTION
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:fnInsert
RETURN TYPE:struct node*
PARAMETERS :int
*/
struct node* fnInsert(int x)
{
    struct node*temp;
    temp=getnode();
    temp->data=x;  //ENTER THE DATA INTO DATA FIELD
    return temp;  //RETURN NEWLY ALLOCATED NODE
}
/*AUTHOR:H K MANOJ
NAME OF FUNCTION:getnode
RETURN TYPE:struct node*
PARAMETERS :void
*/
struct node* getnode()
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));  //ALLOCATING NEW NODE USING MALLOC
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
          printf("__________________________________________\n");
    }
    temp=f;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data); //WHILE LOOP USED FOR TREVERSAL
        temp=temp->next;
    }
      printf("__________________________________________\n");
    
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
    temp=f;//TAKE A COPY OF NODE TO BE DELETED TO FREE THE SPACE 
    f=f->next; //PONTING f TO THE NEXT ELEMENT
    x=temp->data;
    free(temp);//FREE UP THE MEMORY SPACE
    printf("%d IS DELETED SUCCESSFULLY\n",x);
    printf("__________________________________________\n");
    return f;
}