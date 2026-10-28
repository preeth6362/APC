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

int subraction(List **tail1,List **tail2,List **headr,List **tailr,char sign)
{
List *temp1=*tail1;
List *temp2=*tail2;
List *del;
int operand1,operand2;
int data,borrow=0;
while(temp1||temp2)
{
    if(borrow==1)
    {
    if(temp1->data==0)
    temp1->data=9;
    else 
    {
    temp1->data--;
    borrow=0;
    }
    }
    if(temp1&&temp2)
    {
        if(temp1->data<temp2->data)
        {
            operand1=temp1->data+10;
            operand2=temp2->data;
            borrow=1;
        }
        else
        {
            operand1=temp1->data;
            operand2=temp2->data;
        }
    }
    else if(temp2==NULL)
    {
        operand1=temp1->data;
        operand2=0;
    }
    temp1=temp1->prev;
    if(temp2!=NULL)temp2=temp2->prev;
    data=operand1-operand2;
    insert_first(headr,tailr,data);
}
temp1=*headr;
while(temp1!=*tailr&&temp1->data==0)
{
    temp1=temp1->next;
    free(temp1->prev);
    temp1->prev=NULL;
    *headr=temp1;
}
if(sign)
(*headr)->data=-(*headr)->data;
return SUCCESS;
}

/*int subraction(List **tail1,List **tail2,List **headr,List **tailr,char sign)
{
List *temp1=*tail1;
List *temp2=*tail2;
List *temp,*del;
int operand1,operand2;
int data;
while(temp1||temp2)
{
    if(temp1&&temp2)
    {
        if(temp1->data<temp2->data)
        {
            operand1=temp1->data+10;
            temp=temp1;
            while(temp->prev!=NULL&&temp->prev->data==0)
            {
            temp->prev->data=9;
            temp=temp->prev;
            }
            if(temp->prev!=NULL)
            temp->prev->data--;
            operand2=temp2->data;
        }
        else
        {
            operand1=temp1->data;
            operand2=temp2->data;
        }
    }
    else if(temp2==NULL)
    {
        operand1=temp1->data;
        operand2=0;
    }
    temp1=temp1->prev;
    if(temp2!=NULL)temp2=temp2->prev;
    data=operand1-operand2;
    insert_first(headr,tailr,data);
}
temp=*headr;
while(temp!=*tailr&&temp->data==0)
{
    temp=temp->next;
    free(temp->prev);
    temp->prev=NULL;
    *headr=temp;
}
if(sign)
(*headr)->data=-(*headr)->data;
return SUCCESS;
}
*/