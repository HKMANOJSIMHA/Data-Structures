#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    struct node*Llink;
    int data;
    struct node*Rlink;
};
struct node* fnInsert(struct node*,int);
void fnpreorder(struct node*);
void fnInorder(struct node*);
void fnPostorder(struct node*);
struct node* fnFindMax(struct node*);
struct node* fnFindMin(struct node*);
struct node* fnSearch(struct node*,int);
int main()
{
    struct node*root=NULL,*max,*min,*searchres;
    int item,choice,key;
    for(;;)
    {
        printf("ENTER THE CHOICE\n");
        printf("1-INSERT\n2-PRE ORDER TRAVERSAL\n3-IN ORDER TRAVERSAL\n4-POST ORDER TRAVERSAL\n5-FIND MAXIMUM\n");
        printf("6-FIND MIN\n7-SEARCH AN ELEMENT\n8-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("ENTER THE ELEMENT TO BE INSERTED:");
                   scanf("%d",&item);
                   root=fnInsert(root,item);
                   break;
            case 2:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   fnpreorder(root);
                   break;
            case 3:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   fnInorder(root);
                   break;
            case 4:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   fnPostorder(root);
                   break;
            case 5:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   max=fnFindMax(root);
                   printf("MAXIMUM ELEMENT IS %d\n",max->data);
                   break;
            case 6:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   min=fnFindMin(root);
                   printf("MINIMUM ELEMENT IS %d\n",min->data);
                   break;
            case 7:if(root==NULL)
                   {
                       printf("TREE IS EMPTY\n");
                       break;
                   }
                   printf("ENTER THE ELEMENT TO BE SEARCHED:");
                   scanf("%d",&key);
                   searchres=fnSearch(root,key);
                   if(searchres==NULL)
                   printf("ELEMENT NOT FOUND\n");
                   else
                   printf("SEARCH SUCCESSFULL\n");
                   break;
            case 8:printf("THANK YOU!!\n");
                   exit(0);
            default :printf("INVALID CHOICE\n");
                     break;
        }
    }
}
struct node* fnInsert(struct node*root,int item)
{
    struct node*new,*curr,*prev;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->Llink=NULL;
    new->Rlink=NULL;
    if(root==NULL)
    return new;
    prev=NULL;
    curr=root;
    while(curr!=NULL)
    {
        prev=curr;
        if(item<curr->data)
        curr=curr->Llink;
        else
        curr=curr->Rlink;
    }
    if(item<prev->data)
    prev->Llink=new;
    else
    prev->Rlink=new;
    return root;
}
void fnpreorder(struct node*root)
{
    if(root==NULL)
    return;
    printf("%d  ",root->data);
    fnpreorder(root->Llink);
    fnpreorder(root->Rlink);
    return;
}
void fnInorder(struct node*root)
{
    if(root==NULL)
    return;
    fnInorder(root->Llink);
    printf("%d  ",root->data);
    fnInorder(root->Rlink);
    return;
}
void fnPostorder(struct node*root)
{
    if(root==NULL)
    return;
    fnPostorder(root->Llink);
    fnPostorder(root->Rlink);
    printf("%d  ",root->data);
    return;
}
struct node* fnFindMax(struct node*root)
{
    struct node*curr;
    curr=root;
    while(curr->Rlink!=NULL)
    {
        curr=curr->Rlink;
    }
    return curr;
}
struct node* fnFindMin(struct node*root)
{
    struct node*curr;
    curr=root;
    while(curr->Llink!=NULL)
    {
        curr=curr->Llink;
    }
    return curr;
}
struct node* fnSearch(struct node*root,int key)
{
    if(root==NULL)
    return root;
    if(key==root->data)
    return root;
    if(key<root->data)
    return fnSearch(root->Llink,key);
    if(key>root->data)
    return fnSearch(root->Rlink,key);
}