#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node*next;
};
struct node*fnInsertFirst(struct node*);
struct node*fnInsertSecond(struct node*);
struct node*fnconcatenate(struct node*,struct node*);
void fnDisplay(struct node*);
int main()
{
    struct node*L1=NULL,*L2=NULL;
    printf("ENTER THE ELEMENTS INTO LIST 1\n");
    L1=fnInsertFirst(L1);
    printf("ENTER THE ELEMENTS INTO LIST-2\n");
    L2=fnInsertSecond(L2);
    L1=fnconcatenate(L1,L2);
    if(L1==NULL&&L2==NULL)
    printf("LIST EMPTY\n");
    else
    {
    printf("CONCATENATED LIST IS\n");
    fnDisplay(L1);
    }
    return 0;
}
struct node*fnInsertFirst(struct node*f)
{
    struct node*temp,*curr;int choice,item;
    for(;;)
    {
       printf("ENTER YOUR CHOICE\n1-INSERT-FRONT\n2-INSERT-REAR\n3-DISPLAY\n4-STOP INSERTING\n");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
               scanf("%d",&item);
               temp=(struct node*)malloc(sizeof(struct node));
               temp->data=item;
               temp->next=NULL;
               {
                   temp->next=f;
                   f=temp;
               }
               break;
        case 2:printf("ENTER THE ELEMENT TO BE INSERTED:");
               scanf("%d",&item);
               temp=(struct node*)malloc(sizeof(struct node));
               temp->data=item;
               temp->next=NULL;
               if(f==NULL)
               f=temp;
               else
               {
                   curr=f;
                   while(curr->next!=NULL)
                   {
                       curr=curr->next;
                   }
                   curr->next=temp;
               }
               break;
        case 3:fnDisplay(f);
               break;
        case 4:return f;
        default:printf("INVALID CHOICE\n");
               
       }
    }
}
struct node*fnInsertSecond(struct node*s)
{
    struct node*temp,*curr;int choice,item;
    for(;;)
    {
       printf("ENTER YOUR CHOICE\n1-INSERT-FRONT\n2-INSERT-REAR\n3-DISPLAY\n4-STOP INSERTING\n");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
               scanf("%d",&item);
               temp=(struct node*)malloc(sizeof(struct node));
               temp->data=item;
               temp->next=NULL;
               {
                   temp->next=s;
                   s=temp;
               }
               break;
        case 2:printf("ENTER THE ELEMENT TO BE INSERTED:");
               scanf("%d",&item);
               temp=(struct node*)malloc(sizeof(struct node));
               temp->data=item;
               temp->next=NULL;
               if(s==NULL)
               s=temp;
               else
               {
                   curr=s;
                   while(curr->next!=NULL)
                   {
                       curr=curr->next;
                   }
                   curr->next=temp;
               }
               break;
        case 3:fnDisplay(s);
               break;
        case 4:return s;
        default:printf("INVALID OPTION\n");
               
       }
    }
}
struct node* fnconcatenate(struct node*f,struct node*s)
{
    struct node*temp;
    if(f==NULL)
    return s;
    if(s==NULL)
    return f;
    temp=f;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=s;
    return f;
}
void fnDisplay(struct node*f)
{
     struct node*temp;
     if(f==NULL)
     printf("LIST EMPTY\n");
else
{
    temp=f;
    while(temp!=NULL)
    {
        if(temp==f&&temp->next!=NULL)
        printf("%d <-FRONT END\n",temp->data);
        else if(temp!=f&&temp->next==NULL)
        printf("%d <-REAR END\n",temp->data);
        else if(f->next==NULL)
        printf("%d <-FRONT AND REAR END\n",temp->data);
        else
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
}