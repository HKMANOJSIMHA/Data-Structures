#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
struct node
{
    struct node* Llink;
    char data;
    struct node* Rlink;
};
struct node*fnCreateExprTree(char []);
float fnEvaluateExpression(struct node*);
int main()
{
    struct node*root;
    char postfix[50];
    float result;
    printf("ENTER THE VALID POSTFIX EXPRESSION\n");
    scanf("%s",postfix);
    root=fnCreateExprTree(postfix);
    result=fnEvaluateExpression(root);
    printf("THE RESULT OF EXPRESSION %s IS %f\n",postfix,result);
    return 0;
}
struct node* fnCreateExprTree(char postfix[])
{
    int i,j;
    struct node*new,*stack[50];
    char symbol;
    for(i=j=0;(symbol=postfix[i])!='\0';i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->data=symbol;
        new->Llink=new->Rlink=NULL;
        if(isalnum(symbol))
        {
            stack[j++]=new;
        }
        else
        {
            new->Rlink=stack[--j];
            new->Llink=stack[--j];
            stack[j++]=new;
        }
    }
    return stack[--j];
}
float fnEvaluateExpression(struct node*root)
{
    float number;
    switch(root->data)
    {
        case '+':return fnEvaluateExpression(root->Llink)+fnEvaluateExpression(root->Rlink);
        case '-':return fnEvaluateExpression(root->Llink)-fnEvaluateExpression(root->Rlink);
        case '*':return fnEvaluateExpression(root->Llink)*fnEvaluateExpression(root->Rlink);
        case '/':return fnEvaluateExpression(root->Llink)/fnEvaluateExpression(root->Rlink);
        case '$':return pow(fnEvaluateExpression(root->Llink),fnEvaluateExpression(root->Rlink));
        default: if(isalpha(root->data))
                 {
                     printf("ENTER VALUE OF %c:",root->data);
                     scanf("%f",&number);
                     return number;
                 }
                 return root->data-'0';
    }
}