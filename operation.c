#include "apc.h"

int addition(List **tail1,List **tail2,List **headr,List **tailr)
{
List *temp1=*tail1;
List *temp2=*tail2;
int operand1,operand2;
int carry=0,data;
while(temp1||temp2)
{
    if(temp1!=NULL)
    {
        operand1=temp1->data;
        temp1=temp1->prev;
    }
    else
    operand1=0;
    if(temp2!=NULL)
    {
        operand2=temp2->data;
        temp2=temp2->prev;
    }
    else
    operand2=0;
    data=operand1+operand2+carry;
    insert_first(headr,tailr,data%10);
    carry=data/10;
}
if(carry)
{
    insert_first(headr,tailr,carry);
    return SUCCESS;
}
else 
return SUCCESS;
}