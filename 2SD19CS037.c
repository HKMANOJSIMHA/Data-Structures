/*C PROGRAM TO CONVERT INFIX EXPRESSION TO POSTFIX AND THEN THE POSTFIX EXPRESSION 
TO RESULTING VALUE USING LINKED LIST*/
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>
/*STRUCTURE SPECIFICATION FOR INFIX TO POSTFIX CONVERSION*/
struct node
{
char data;
struct node*next;
};
/*STRUCTURE SPECIFICATION FOR POSTFIX EVALUATION*/
struct nodeeval
{
    double data;
    struct nodeeval*next;
};
/*FUNCTION PROTOTYPES*/
void converter(char*,char*);
double fnEvaluate(char *);
double fnOperation(double ,char,double);
struct node* fnPush(struct node*,char);
struct node* fnPop(struct node*,char*);
struct nodeeval* fnPushEval(struct nodeeval*,double);
struct nodeeval* fnPopEval(struct nodeeval*,double*);
int stack_pred(char);
int input_pred(char);
/*DRIVER FUNCTION BEGINS*/
int main()
{
char infix[20],postfix[20],sym=0,letter=0,i,flag;
double dResult;
printf("Enter the infix expression\n");
scanf("%s",infix);
for(i=0;i<strlen(infix);i++)  //for loop to check whether the given expression is valid or not
{
    if(infix[i]=='('||infix[i]==')')
    flag=0;
    else if (isalnum(infix[i])) //if the element is letter or numerical value
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
dResult=fnEvaluate(postfix);
printf("%s=%lf\n",postfix,dResult);
}
return 0;
}
/*Name:H.K.Manoj
*Function Name:convertor
*Return type:void
*Arguments:char*,char*
*date:11-02-2021
*/
void converter(char *infix,char *postfix)
{
struct node* first; 
int i,j=0;
char symbol,rvalue;
first=fnPush(first,'#');
for(i=0;i<strlen(infix);i++)
{
symbol=infix[i];
while(stack_pred(first->data)>input_pred(symbol))
{
first=fnPop(first,&rvalue);
postfix[j++]=rvalue;
}
if(stack_pred(first->data)!=input_pred(symbol))
{
first=fnPush(first,symbol);
}
else
first=fnPop(first,&rvalue);
}
while(first->data!='#')
{
first=fnPop(first,&rvalue);
postfix[j++]=rvalue;
}
postfix[j++]='\0';
}
/*Name:H.K.Manoj
*Function Name:stack_pred
*Return type:int
*Arguments:char
*date:11-02-2021
*/
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
/*Name:H.K.Manoj
*Function Name:input_pred
*Return type:int
*Arguments:char
*date:11-02-2021
*/
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
/*Name:H.K.Manoj
*Function Name:fnPush
*Return type:struct node*
*Arguments:struct node*,char
*date:11-02-2021
*/
struct node* fnPush(struct node*f,char op)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=op;
    new->next=f;
    return new;
}
/*Name:H.K.Manoj
*Function Name:fnPop
*Return type:struct node*
*Arguments:struct node*,char*
*date:11-02-2021
*/
struct node* fnPop(struct node*f,char*op)
{
    struct node*temp;
    temp=f;
    temp=temp->next;
    *op=f->data;
    free(f);
    return temp;
}
/*Name:H.K.Manoj
*Function Name:fnPushEval
*Return type:struct nodeeval*
*Arguments:struct node*,double
*date:11-02-2021
*/
struct nodeeval* fnPushEval(struct nodeeval*f,double op)
{
    struct nodeeval*new;
    new=(struct nodeeval*)malloc(sizeof(struct nodeeval));
    new->data=op;
    new->next=f;
    return new;
}
/*Name:H.K.Manoj
*Function Name:fnPopEval
*Return type:struct nodeeval*
*Arguments:struct node*,double*
*date:11-02-2021
*/
struct nodeeval* fnPopEval(struct nodeeval*f,double*op)
{
    struct nodeeval*temp;
    temp=f;
    temp=temp->next;
    *op=f->data;
    free(f);
    return temp;
}
/*Name:H.K.Manoj
*Function Name:fnEvaluate
*Return type:double
*Arguments:char*
*date:11-02-2021
*/
double fnEvaluate(char *postfix)
{
        /*Loop controlling variable*/
int i;
char symbol;
double rvalue,value;
double op1,op2,dFinalResult,interim;
struct nodeeval*first;/*Create the dynamic stack needed for evaluation*/
for(i=0;postfix[i]!='\0';i++)
{
        symbol=postfix[i];
        /*If symbol is an operand then push it in the dynamic stack*/
        if(isdigit(symbol))
        {
               first=fnPushEval(first,symbol-'0');
        }
        else if(isalpha(symbol))
        {
            printf("ENTER %c VALUE:",symbol);
            scanf("%lf",&value);
            first=fnPushEval(first,value);
        }
        /*If symbol is not an operand pop into dynamic stack twice 
        compute the intermidiate result, eventually final result*/
        else
        {
                first=fnPopEval(first,&rvalue);
                op2=rvalue;
                first=fnPopEval(first,&rvalue);
                op1=rvalue;
                interim=fnOperation(op1,symbol,op2);
                /*Intermidiate reult of sub expressions within
                  postfix exp is pushed back on to the stack*/
                first=fnPushEval(first,interim);
        }
}/*End of for loop(end of scanning postfix expression)*/
        first=fnPopEval(first,&rvalue);
        dFinalResult=rvalue;
        return dFinalResult;
}/*End of fnEvaluate*/
/*Name:H.K.Manoj
*Function Name:fnOperation
*Return type:double
*Arguments:double,char,double
*date:11-02-2021
*/
double fnOperation(double operand1,char operator,double operand2)
{
        switch(operator)
        {
                case '+':
                                return (operand1+operand2);
                case '-':
                                return (operand1-operand2);
                case '*':
                   return (operand1*operand2);
                case '/':
                  return (operand1/operand2);
                case '$':
                case '^':
                                return pow(operand1,operand2);
        }
}/*End of fnOperation*/
