#include "apc.h"

int main(int argc,char *argv[])
{
if(argc!=4)
{
    printf("insufficient arguments\nEnter like this->./a.out operand1 operator operand2\n");
    return 0;
}
List *head1,*tail1;
head1=tail1=NULL;
List *head2,*tail2;
head2=tail2=NULL;
List *headr,*tailr;
headr=tailr=NULL;

if(validate(argv[1])==FAILURE || validate(argv[3])==FAILURE)
{
    printf("Enter valid arguments\nEnter like this->./a.out operand1(valid integer) operator operand2(valid integer)\n");
    return 0;
}
if(strlen(argv[2])!=1 || (argv[2][0]!='+'&&argv[2][0]!='-'&&argv[2][0]!='x'&&argv[2][0]!='/'))
{
    printf("Enter valid arguments\nEnter like this->./a.out operand1(valid integer) operator operand2(valid integer)\n");
    return 0;
}
char operator=argv[2][0];
int sign=0;
char *str1=argv[1];
char *str2=argv[3];
if(operator=='+')
{
    if(str1[0]=='-'&&str2[0]=='-')
    sign=1;
    else if(str1[0]=='-')
    {
        str1=argv[3];
        str2=argv[1];
        operator='-';
    }
    else if(str2[0]=='-')
    operator='-';
}
else if(operator=='-')
{
    if(str1[0]=='-'&&str2[0]=='-')
    {
        str1=argv[3];
        str2=argv[1];
    }
    else if(str1[0]=='+'&&str2[0]=='-')
    operator='+';
    else if(str1[0]=='-'&&str2[0]=='+')
    {
        operator='+';
        sign=1;
    }
    else if(str1[0]=='-')
    {
        operator='+';
        sign=1;
    }
    else if(str2[0]=='-')
    operator='+';
}
else if(operator=='x'&&((str1[0]=='-'&&str2[0]!='-')||(str1[0]!='-'&&str2[0]=='-')))
sign=1;
else if(operator=='/'&&((str1[0]=='-'&&str2[0]!='-')||(str1[0]!='-'&&str2[0]=='-')))
sign=1;
if(str1[0]=='+'||str1[0]=='-')str1++;
if(str2[0]=='+'||str2[0]=='-')str2++;
if(operator=='/'&& str2[0]=='0')
{
    printf("Division by zero not possible\n");
    return 0;
}
for(int i=0;str1[i]!=0;i++)
{
    int data=str1[i]-48;
    insert_last(&head1,&tail1,data);
}
for(int i=0;str2[i]!=0;i++)
{
    int data=str2[i]-48;
    insert_last(&head2,&tail2,data);
}
/*printf("operand1\n");
print_list(&head1);
printf("operand2\n");
print_list(&head2);*/

if(operator=='+')
{
addition(&tail1,&tail2,&headr,&tailr,sign);
}
else if(operator=='-')
{
    if(compare_lists(&head1,&head2)==SMALL)
    subraction(&tail2,&tail1,&headr,&tailr,1);
    else
    subraction(&tail1,&tail2,&headr,&tailr,0);
}
else if(operator=='x')
{
    multiply(&tail1,&tail2,&headr,&tailr,sign); 
}
else if(operator=='/')
{
    divide(&head1,&head2,&tail2,&headr,&tailr,sign); 
}
str1=argv[1];
for(int i=0;str1[i]!=0;i++)
printf("%c",str1[i]);
printf(" %c ",argv[2][0]);
str1=argv[3];
for(int i=0;str1[i]!=0;i++)
printf("%c",str1[i]);
printf(" = ");
print_list(&headr);
}