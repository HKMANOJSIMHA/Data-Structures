#include <stdio.h>
#include<string.h>
#include<ctype.h>
struct stack
{
char expr[20];
int top;
};
typedef struct stack STACK;
void converter(char*,char*);
void fnPush(STACK*,char);
char fnPop(STACK*);
int stack_pred(char);
int input_pred(char);
int main()
{
char infix[20],postfix[20],sym=0,letter=0,i,flag;
printf("Enter the infix expression\n");
scanf("%s",infix);
for(i=0;i<strlen(infix);i++)  //for loop to check whether the given expression is valid or not
{
    if(infix[i]=='('||infix[i]==')')
    flag=0;
    else if (isalpha(infix[i])||isdigit(infix[i])) //if the element is letter or numerical value
    letter++; //make letter count incriment by 1 for each condition
    else
    sym++; //else make the symbol count incriment by 1
}
if(letter!=sym+1)  //to be a valid expression letter count must be 1 greater than symbol count
printf("INVALID EXPRESSION\n");
else
{
converter(infix,postfix);
printf("The postfix expression is:%s\n",postfix);
}
return 0;
}
void converter(char *infix,char *postfix)
{
STACK s; 
int i,j=0;
char symbol;
s.top=-1;
fnPush(&s,'#');

for(i=0;i<strlen(infix);i++)
{
symbol=infix[i];
while(stack_pred(s.expr[s.top])>input_pred(symbol))
{
postfix[j++]=fnPop(&s);
}
if(stack_pred(s.expr[s.top])!=input_pred(symbol))
{
fnPush(&s,symbol);
}
else
fnPop(&s);
}
while(s.expr[s.top]!='#')
{
postfix[j++]=fnPop(&s);
}
postfix[j++]='\0';
}
int stack_pred(char symb)
{
switch(symb)
{
case '+':
case '-':return 2;
case '*':
case '/':return 4;
case '$':
case '^': return 5;
case '(': return 0;
case '#': return -1;
default : return 8;
}
}
int input_pred(char symb)
{
switch(symb)
{
case '+':
case '-': return 1;
case '*':
case '/': return 3;
case '$':
case '^': return 6;
case '(': return 9;
case ')': return 0;
default : return 7;
}
}
void fnPush(STACK *p,char op)
{
p->top++;
p->expr[p->top]=op;
}
char fnPop(STACK *p)
{
return p->expr[p->top--];
}