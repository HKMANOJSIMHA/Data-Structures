#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{char usn[10];
 char name[20];
 char branch[20];
 int sem;
 long int phno;
};
typedef struct student std;
struct NODE
{char usn[10];
 char name[20];
 char branch[20];
 int sem;
 long int phno;
 struct NODE* next;
};
typedef struct NODE* node;
/*function prototypes*/
node insert_front(node,std);
node getnode();
void display(node);
/*function name:main
  return type:int
  parameters:void
  author:Sunidhi J
  date:23 jan 2021
*/
int main()
{ node first=NULL;
  std s;
  int choice;
  for(;;)
 {
  printf("enter the following number to perforrm respective operation\n");
  printf("1:insert front\n2:display\n3:exit\n");
  scanf("%d",&choice);
  switch(choice)
 {case 1:printf("enter the usn no\n");
         scanf("%s",s.usn);
         printf("enter the name\n");
         scanf("%s",s.name);
         printf("enter branch\n");
         scanf("%s",s.branch);
         printf("enter semester in number\n");
         scanf("%d",&s.sem);
         printf("enter phone no\n");
         scanf("%ld",&s.phno);
         first=insert_front(first,s);
         break;
   case 2:display(first);
           break;
   case 3:printf("thanks for using our app\n");
          exit(0);
   default: printf("invalid choice\n");
            break;
}
}
}
node insert_front(node f,std s)
{node temp;
 temp=getnode();
 strcpy(temp->usn,s.usn);
 strcpy(temp->name,s.name);
 strcpy(temp->branch,s.branch);
 temp->sem=s.sem;
 temp->phno=s.phno;
 temp->next=f;
 return temp;
}

node getnode()
{node new;
 new=(struct NODE *) malloc(sizeof(struct NODE));
 if(new==NULL)
  { printf("ram is full\n");
    exit(1);
   }
 return new;
}
void display(node f)
{node curr=f;
 if(f==NULL)
   { printf("no enougf data to display\n");
    return;
   }
 while(curr!=NULL)
 {printf("USN:%s\nNAME:%s\nBRANCH:%s\nSEMESTER:%d\nPHONE NO:%ld\n",curr->usn,curr->name,curr->branch,curr->sem,curr->phno);
  curr=curr->next;
 }
  return;
}