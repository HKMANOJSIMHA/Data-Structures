#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    struct node* left;
    int data;
    struct node* right;
};
struct node* fnInsertFront(struct node*,int);
struct node* fnInsertRear(struct node*,int);
void fndisplay(struct node*);
struct node* fnDeleteFront(struct node*);
struct node* fnInsertAfter(struct node*,int,int);
struct node* fnDeleteRear(struct node*);
struct node* fnDeleteSpecific(struct node*,int);
int main()
{
    struct node*first;
    int choice,item,key;
    for(;;)
    {
        printf("ENTER YOUR CHOICE\n1-INSERT FRONT\n2-INSERT REAR\n3-INSERT AFTER GIVEN ELEMENT\n4-DELETE FRONT\n5-DELETE REAR\n6-DELETE A SPECIFIC ELEMENT\n7-DISPLAY\n8-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   first=fnInsertFront(first,item);
                   break;
            case 7:if(first==NULL)
                  {
                   printf("LIST IS EMPTY\n");
                   break;
                  }
                  fndisplay(first);
                  break;
            case 2:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   first=fnInsertRear(first,item);
                   break;
            case 4:if(first==NULL)
                   {
                       printf("LIST EMPTY NOTHING TO DELETE\n");
                       break;
                   }
                   first=fnDeleteFront(first);
                    break;
            case 3:if(first==NULL)
                   {
                   printf("LIST EMPTY\n");
                   break;
                   }
                      printf("ENTER THE ELEMENT TO BE INSERTED:");
                      scanf("%d",&item);
                      printf("ENTER THE KEY ELEMENT AFTER WHICH YOU WANT TO INSERT:");
                      scanf("%d",&key);
                      first=fnInsertAfter(first,item,key);
                      break;
            case 5: if(first==NULL)
                    {
                        printf("LIST EMPTY NOTHING TO DELETE\n");
                        break;
                    }
                    first=fnDeleteRear(first);
                    break;
            case 6:if(first==NULL)
                    {
                        printf("LIST EMPTY\n");
                        break;
                    }
                    printf("ENTER THE ELEMENT TO BE DELETED:");
                    scanf("%d",&key);
                    first=fnDeleteSpecific(first,key);
                    break;
            case 8:printf("THANK YOU!!!\n");
                   exit(0);
            default:printf("INVALID CHOICE\n");
        }
    }
}
struct node* fnInsertFront(struct node*f,int x)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(f==NULL)
    {
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    temp->left=NULL;
    temp->right=f;
    f->left=temp;
    return temp;
}
void fndisplay(struct node*f)
{
    struct node*temp;
    temp=f;
    while(temp!=NULL)
    {
        if(temp->left==NULL&&temp->right!=NULL)
        printf("%d <-FRONT END\n",temp->data);
        else if(temp->left!=NULL&&temp->right==NULL)
        printf("%d <-REAR END\n",temp->data);
        else if(temp->left==NULL&&temp->right==NULL)
        printf("%d <-FRONT AND REAR END\n",temp->data);
        else
        printf("%d\n",temp->data);
        temp=temp->right;
    }
}
struct node* fnInsertRear(struct node*f,int x)
{
    struct node*temp,*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->right=NULL;
    if(f==NULL)
    {
        new->left=NULL;
        new->right=f;
        return new;
    }
    temp=f;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->right=new;
    new->left=temp;
    return f;
}
struct node*fnDeleteFront(struct node*f)
{
    struct node*temp;
    temp=f;
    f=f->right;
    if(f==NULL)
    {
    printf("ITEM DELETED IS %d\n",temp->data);
    return NULL;
    }
    else
    f->left=NULL;
    printf("ITEM DELETED IS %d\n",temp->data);
    free(temp);
    return f;
}
struct node* fnInsertAfter(struct node*f,int item,int key)
{
    struct node*new,*temp;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    if(f->data==key&&f->right==NULL)
    {
        f->right=new;
        new->left=f;
        new->right=NULL;
        return f;
    }
    temp=f;
    while(temp!=NULL&&temp->data!=key)
    {
        temp=temp->right;
    }
    if(temp==NULL)
    {
    printf("KEY %d NOT PRESENT IN THE LIST\n",key);
    return f;
    }
    new->right=temp->right;
    new->left=temp;
    temp->right=new;
    return f;
}
struct node* fnDeleteRear(struct node*f)
{
    struct node*temp,*prev;
    if(f->right==NULL)
    {
        printf("ITEM DELETED IS %d\n",f->data);
        free(f);
        return NULL;
    }
    temp=f;
    while(temp->right!=NULL)
    {
        prev=temp;
        temp=temp->right;
    }
    printf("ITEM DELETED IS %d\n",temp->data);
    free(temp);
    prev->right=NULL;
    return f;
}
struct node*fnDeleteSpecific(struct node*f,int key)
{
    struct node*temp,*prev;
    if(f->data==key&&f->right==NULL)
    {
        printf("%d IS DELETED SUCCESSFULLY\n",key);
        free(f);
        return NULL;
    }
    if(f->data==key&&f->right!= NULL)
    {
        temp=f;
        f=temp->right;
        f->left=NULL;
        printf("%d IS DELETED SUCCESSFULLY\n",key);
        free(temp);
        return f;
    }
    temp=f;
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->right;
    }
    if(temp==NULL)
    {
        printf("KEY ELEMENT %d IS NOT PRESENT\n",key);
        return f;
    }
    if(temp->right==NULL)
    {
        prev->right=NULL;
        printf("%d IS DELETED SUCCESSFULLY\n",key);
        free(temp);
        return f;
    }
    prev->right=temp->right;
    (temp->right)->left=prev;
    printf("%d IS DELETED SUCCESSFULLY\n",key);
    free(temp);
    return f;
}