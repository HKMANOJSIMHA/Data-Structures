#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct stack
{
    char expr[50];
    int top;
};
typedef struct stack STACK;
struct eval
{
    double evaluate[50];
    int top;
};
typedef struct eval EVAL;
void fnPush(STACK*,char);
char fnPop(STACK*);
void fnPushEval(EVAL*,double);
double fnPopEval(EVAL*);
void fnPostfixConversion(char*,char*);
double fnPostfixEvaluation(char*);
int StackPrecedence(char);
int InputPrecedence(char);
double Operation(double,double,char);
int main()
{
    char Infix[50],Postfix[50];
    int i,operand=0,Operator=0,flag=0;
    double PostfixResult;
    printf("ENTER AN INFIX EXPRESSION:");
    scanf("%s",Infix);
    for(i=0;Infix[i]!='\0';i++)
    {
        if(Infix[i]=='('||Infix[i]==')')
        flag=0;
        else if(isalpha(Infix[i])||isdigit(Infix[i]))
        operand++;
        else
        Operator++;
    }
    if(operand!=Operator+1)
    {
    printf("INVALID EXPRESSION\n");
    exit(0);
    }
    fnPostfixConversion(Infix,Postfix);
    printf("THE CONVERTED POSTFIX EXPRESSION OF INFIX EXPRESSION %s IS:%s\n",Infix,Postfix);
    PostfixResult=fnPostfixEvaluation(Postfix);
    printf("THE VALUE OF POSTFIX EXPRESSION IS %lf\n",PostfixResult);
    return 0;

}
void fnPush(STACK*s,char symbol)
{
    s->top++;
    s->expr[s->top]=symbol;
}
char fnPop(STACK*s)
{
    char x;
    x=s->expr[s->top];
    s->top--;
    return x;
}
void fnPushEval(EVAL*s,double symbol)
{
    s->top++;
    s->evaluate[s->top]=symbol;
}
double fnPopEval(EVAL*s)
{
    double x;
    x=s->evaluate[s->top];
    s->top--;
    return x;
}
void fnPostfixConversion(char*infix,char*postfix)
{
    STACK s;
    int i,j=0;
    s.top=-1;
    char symbol;
    fnPush(&s,'#');
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        while(StackPrecedence(s.expr[s.top])>InputPrecedence(symbol))
        {
            postfix[j++]=fnPop(&s);
        }
        if(StackPrecedence(s.expr[s.top])!=InputPrecedence(symbol))
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
int StackPrecedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$':
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default:  return 8;
    }
}
int InputPrecedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '$':
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default:  return 7;
    }
}
double fnPostfixEvaluation(char*postfix)
{
    EVAL s;
    int i;
    char symbol;
    double InterimResult,FinalResult,dValue,op1,op2;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        {
            fnPushEval(&s,symbol-'0');
        }
        else if(isalpha(symbol))
        {
            printf("ENTER THE VALUE OF %c:",symbol);
            scanf("%lf",&dValue);
            fnPushEval(&s,dValue);
        }
        else
        {
               op2=fnPopEval(&s);
               op1=fnPopEval(&s);
               InterimResult=Operation(op2,op1,symbol);
               fnPushEval(&s,InterimResult);
        }
    }
    FinalResult=fnPopEval(&s);
    return FinalResult;
}
double Operation(double op2,double op1,char symbol)
{
    switch(symbol)
    {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '$':
        case '^': return pow(op1,op2);
    }
}