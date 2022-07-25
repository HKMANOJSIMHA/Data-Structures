#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
struct node* fnInsert(struct node*,int);
struct node* fnDelete(struct node*);
void fnDisplay(struct node*);
int main()
{
    struct node*first=NULL;
    int item,choice;
    for(;;)
    {
        printf("ENTER YOUR CHOICE:\n");
        printf("1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   first=fnInsert(first,item);
                   break;
            case 2:if(first==NULL)
                {
                   printf("LIST IS EMPTY NOTHING TO DELETE\n");
                   break;
                }  
                first=fnDelete(first);
                break;
            case 3:if(first==NULL)
                {
                   printf("LIST IS EMPTY NOTHING TO DISPLAY\n");
                   break;
                }
                fnDisplay(first);
                break;
            case 4:printf("THANK YOU!!!!\n");
                   exit(0);
            default:printf("INVALID CHOICE\n");
        }
    }
}
struct node* fnInsert(struct node*f,int x)
{
    struct node*temp,*curr,*prev;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(f==NULL)
    {
        return temp;
    }
    if(f->data>x)
    {
        temp->next=f;
        return temp;
    }
    prev=NULL;
    curr=f;
    while(curr!=NULL&&x>curr->data)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=temp;
    temp->next=curr;
    return f;
}
struct node* fnDelete(struct node*f)
{
    struct node*curr;
    curr=f;
    f=f->next;
    printf("ITEM DELETED IS %d\n",curr->data);
    free(curr);
    return f;
}
void fnDisplay(struct node*f)
{
    struct node*temp;
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