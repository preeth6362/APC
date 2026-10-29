#include "apc.h"

int multiply(List **tail1,List **tail2,List **headr,List **tailr)
{
    List *temp1,*temp2,*headr2,*tailr2,*headb,*tailb;
    headr2=tailr2=headb=tailb=NULL;
    int count=0,carry,data;
    temp2=*tail2;
    while(temp2!=NULL)
    {
        temp1=*tail1;
        carry=0;
        for(int i=0;i<count;i++)
        insert_first(&headr2,&tailr2,0);
        while(temp1!=NULL)
        {
            data=temp1->data*temp2->data+carry;
            if(count==0)
                insert_first(headr,tailr,data%10);
            else
                insert_first(&headr2,&tailr2,data%10);
            carry=data/10;
            temp1=temp1->prev;
        }
        if(carry)
        {
            if(count==0)
            insert_first(headr,tailr,carry);
            else
            insert_first(&headr2,&tailr2,carry);
        }
        if(count!=0)
        {
            addition(tailr,&tailr2,&headb,&tailb);
            delete_list(headr,tailr);
            delete_list(&headr2,&tailr2);
            *headr=headb;
            *tailr=tailb;
            headb=tailb=NULL;
        }
        count++;
        temp2=temp2->prev;
    }
    return SUCCESS;
}