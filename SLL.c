#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node* NODE;
NODE fnInsertFront(NODE,int);
NODE fnDeleteFront(NODE);
NODE fnInsertRear(NODE,int);
NODE fnDeleteRear(NODE);
void fnDisplayList(NODE);
NODE fnDeleteSpecific(NODE);
NODE fnInsertSpecific(NODE,int);
void fnsearch(NODE,int);
int main()
{
    NODE first=NULL;
    int choice ,item,key;
    for(;;)
    {
        printf("ENTER YOUR CHOICE:\n");
        printf("1-Insert at front end\n2-Insert at rear end\n3-Delete at front end\n4-Delete at rear end\n5-Display list\n6-Delete specific\n7-Insert after specific\n8-SEARCH AN ELEMENT\n9-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   first=fnInsertFront(first,item);
                   break;
            case 2:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   first=fnInsertRear(first,item);
                   break;
            case 3:first=fnDeleteFront(first);
                   break;
            case 4:first=fnDeleteRear(first);
                   break;
            case 5:fnDisplayList(first);
                   break;
            case 6:first=fnDeleteSpecific(first);
                   break;
            case 7:if(first==NULL)
                   {
                       printf("EMPTY LIST\n");
                       break;
                   }
                   printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO INSERT:");
                   scanf("%d",&key);
                   first=fnInsertSpecific(first,key);
                   break;
            case 8:if(first==NULL)
                   {
                       printf("LIST EMPTY\n");
                       break;
                   }
                   printf("ENTER THE SEARCH ELEMENT\n");
                   scanf("%d",&key);
                   fnsearch(first,key);
                   break;
            case 9:printf("THANK YOU!!!!");
                   exit(0);
            default:printf("INVALID CHOICE\n");
        }
    }
}
NODE fnInsertFront(NODE f,int item)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=f;
    return temp;
}
NODE fnInsertRear(NODE f,int item)
{
    NODE new,temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if(f==NULL)
    return temp;
    new=f;
    while(new->next!=NULL)
    {
        new=new->next;
    }
    new->next=temp;
    return f;
}
NODE fnDeleteFront(NODE f)
{
    NODE temp;
    if(f==NULL)
    {
        printf("LIST EMPTY NOTHING TO DELETE\n");
        return f;
    }
    temp=f;
    temp=temp->next;
    printf("ITEM DELETED IS %d\n",f->data);
    free(f);
    return temp;
}
NODE fnDeleteRear(NODE f)
{
    NODE temp,prev;
    if(f==NULL)
    {
        printf("LIST EMPTY NOTHING TO DELETE\n");
        return f;
    }
    temp=f;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("ITEM DELETED IS %d\n",temp->data);
    if(temp==f)
    f=NULL;
    else
    prev->next=NULL;
    free(temp);
    return f;
}
void fnDisplayList(NODE f)
{
    NODE temp;
    if(f==NULL)
    {
        printf("LIST IS EMPTY NOTHING TO DISPLAY\n");
        return;
    }
    temp=f;
    printf("ELEMENTS IN THE LIST ARE\n");
    while(temp!=NULL)
    {
       if(temp==f&&temp->next!=NULL)
       printf("%d <-FRONT END\n",temp->data);
       else if(temp!=f&&temp->next==NULL)
       printf("%d <-REAR END\n",temp->data);
       else if(temp==f&&temp->next==NULL)
       printf("%d <-FRONT AND REAR END\n",temp->data);
       else
       printf("%d\n",temp->data);
       temp=temp->next;
    }
}
NODE fnDeleteSpecific(NODE f)
{
    NODE temp,prev;
    int key;
    if(f==NULL)
    {
        printf("LIST EMPTY NOTHING TO DELETE\n");
        return NULL;
    }
    printf("ENTER THE ELEMENT TO BE DELETED:");
    scanf("%d",&key);
    if(f->data==key&&f->next==NULL)
    {
        free(f);
        printf("%d DELETED SUCCESSFULLY\n",key);
        return NULL;
    }
    if(f->data==key&&f->next!=NULL)
    {
        temp=f;
        f=f->next;
        printf("%d DELETED SUCCESSFULLY\n",key);
        free(temp);
        return f;
    }
    temp=f;
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("%d ITEM NOT PRESENT IN THE LIST\n",key);
        return f;
    }
    if(temp->next==NULL)
    {
        prev->next=NULL;
        free(temp);
        printf("%d DELETED SUCCESSFULLY\n",key);
        return f;
    }
    prev->next=temp->next;
    free(temp);
    printf("%d DELETED SUCCESSFULLY\n",key);
    return f;
}
NODE fnInsertSpecific(NODE f,int key)
{
      NODE temp,new;
      int item;
      printf("ENTER THE ELEMENT TO BE INSERTED:");
      scanf("%d",&item);
      new=(NODE)malloc(sizeof(struct node));
      new->data=item;
      if(f->data==key&&f->next==NULL)
      {
          f->next=new;
          new->next=NULL;
          return f;
      }
      temp=f;
      while(temp!=NULL&&temp->data!=key)
      {
          temp=temp->next;
      }
      if(temp==NULL)
      {
          printf("ELEMENT NOT FOUND\n");
          return f;
      }
      new->next=temp->next;
      temp->next=new;
      return f;
}
void fnsearch(NODE f,int key)
{
    NODE temp;
    temp=f;
    while(temp!=NULL&&temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    printf("SEARCH UNSUCCESSFULL ELEMENT NOT PRESENT\n");
    else
    printf("SEARCH SUCCESSFULL ELEMENT PRESENT\n");
}