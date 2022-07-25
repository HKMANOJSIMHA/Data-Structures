/*LIBRARIES REQUIRED*/
#include<stdio.h>
#include<string.h>
/*STRUCTURE DEFINITION*/
 struct stack 
{
    char string[100];
    int top;
};
typedef struct stack STACK;
/*DECLERATIONS OF USERDEFINED FUNCTIONS*/
void fnPush(STACK*,char []); 
void fnPop(STACK*,char []);
int fnCheckPalindrome(char [],char []);
/*MAIN FUNCTION BEGINS*/
int main()
{
    STACK s;//DECLERATION OF STACK VARIABLE
    s.top=-1;
    char inputstring[100];
    int flag;
    char reversedstring[100];
    printf("ENTER THE STRING:");
    scanf("%s",inputstring);                                //INPUT STRING
    fnPush(&s,inputstring);                                //CALL TO fnPush
    fnPop(&s,reversedstring);                             //CALL TO fnPop
    flag=fnCheckPalindrome(inputstring,reversedstring); //CALL TO fnCheckPalindrome
    if(flag==1)                                        /* fnCheckPalindrome RETURNS 1 
                                                        WHEN STRING IS PALINDROME*/
    printf("%s IS A PALINDROME\n",inputstring);
    else
    printf("%s IS NOT A PALINDROME\n",inputstring);
    
} //END OF MAIN
/*AUTHOR:MANOJ
NAME OF FUNCTION:fnPush
RETURNTYPE:void
ARGUMENTS:STACK*
DATE:16-12-2020
*/
void fnPush(STACK*s,char ipstr[])
{
    int i;
    for(i=0;ipstr[i]!='\0';i++)
    {
        s->top++;
        s->string[s->top]=ipstr[i]; //PUSHING EACH CHARACTER INTO STACK USING FOR LOOP
    }
}
/*AUTHOR:MANOJ
NAME OF FUNCTION:fnPop
RETURNTYPE:void
ARGUMENTS:STACK*,char []
DATE:16-12-2020
*/
void fnPop(STACK*s,char r[])
{
    int i=0,x;
    while(s->top>=0)
    {
    r[i]=s->string[s->top]; /*POPING EACH ELEMENT AND STORING IT IN THE NEW ARRAY
                               USING WHILE LOOP*/
    s->top--;
    i++;
    }
    
}
/*AUTHOR:MANOJ
NAME OF FUNCTION:fnCheckPalindrome
RETURNTYPE:int
ARGUMENTS:STACK*,char []
DATE:16-12-2020
*/
int fnCheckPalindrome(char ipstr[],char r[])
{
    int flag=0,i;
    for(i=0;ipstr[i]!='\0';i++)
    {
        if(ipstr[i]==r[i]) //CHECK THE CONDITION FOR PALINDROME
        {
            flag++;   //TRACING VARIABLE
        }
    }
    if(flag==strlen(ipstr)) /* IN THIS CONDITION IF ALL THE CHARACTERS THE ARE MATCHED WITH THE REVERSED STRING THEN
                                 TRACE VARIABLE MUST HAVE BECOME EQUAL TO STRING LENGTH OF ENTERED STRING AND HENCE IT 
                                 BECOMES A PALINDROME AND RETURNS TRUE*/
    return 1;
    else
    return 0;        //IF GIVEN STRING IS NOT PALINDROME
}
