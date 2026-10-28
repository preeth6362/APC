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
char *str1=argv[1];
char *str2=argv[3];
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
print_list(&head1);
print_list(&head2);
}