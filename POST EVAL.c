/*Evaluation of postfix expression
 * Author:RGY
 * Date:4-12-20202
 */
/*Preprocessor directives*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
/*Structure specification for stack*/
struct stack
{
        double elements[MAX];
        int top;
};
typedef struct stack STACK;
/*Function prototypes*/
double fnEvaluate(char []);
double fnOperation(double,char,double);
void fnPush(STACK*,double);
double fnPop(STACK*);
/*Client program
 * function name:main
 * arguments:void
 * return type:int
 * Author:RGY
 * Date:4-12-2020
 */
int main(void)
{
        char caPostfix[MAX];
        double dResult;
        printf("Enter a valid postfix expression\n");
        scanf("%s",caPostfix);
        dResult=fnEvaluate(caPostfix);
        printf("%s=%lf\n",caPostfix,dResult);

        /*Return on success*/
        return 0;
}
/*Function name:fnEvaluate
 * arguments:char*(postfix expression)
 * return type:double(Result of evaluation)
 * Author:RGY
 * Date:4-12-2020
 */
double fnEvaluate(char *postfix)
{
        /*Loop controlling variable*/
int i;
char symbol;
double op1,op2,dFinalResult,interim;
STACK s;/*Create the stack needed for evaluation*/
s.top=-1;
for(i=0;postfix[i]!='\0';i++)
{
        symbol=postfix[i];
        /*If symbol is an operand then push it on stack*/
        if(isdigit(symbol))
        {
                fnPush(&s,symbol-'0');
        }
        /*If symbol is not an operand pop the stack twice                  compute the intermidiate result, eventually final           result*/
        else
        {
                op2=fnPop(&s);
                op1=fnPop(&s);
                interim=fnOperation(op1,symbol,op2);
                /*Intermidiate reult of sub expressions within
                  postfix exp is pushed back on to the stack*/
                fnPush(&s,interim);
        }
}/*End of for loop(end of scanning postfix expression)*/
        dFinalResult=fnPop(&s);
        return dFinalResult;
}/*End of fnEvaluate*/

/*Function name: fnOperation
 * arguments:double,char,double
 * return type:double
 * Author:RGY
 * Date:4-12-2020
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

/*Function name:fnPush
 * arguments:STACK*,double
 * return type:void
 * Author:RGY
 * Date:4-12-2020
 */
void fnPush(STACK *p,double item)
{
        p->top++;/*Making room for new element*/
        p->elements[p->top]=item;/*Pushing item in to the stack*/
        return;
}/*End of fnPush
/*Function name:fnPop
 * arguments:STACK*
 * return type:double
 * Author:RGY
 * Date:4-12-2020
 */
double fnPop(STACK *p)
{
        double x;
        x=p->elements[p->top];
        p->top--;
        return x;
}/*End of fnPOp*/