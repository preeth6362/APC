#include "apc.h"

int multiply(List **tail1,List **tail2,List **headr,List **tailr,int sign)
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
            addition(tailr,&tailr2,&headb,&tailb,0);
            delete_list(headr,tailr);
            delete_list(&headr2,&tailr2);
            *headr=headb;
            *tailr=tailb;
            headb=tailb=NULL;
        }
        count++;
        temp2=temp2->prev;
    }
    delete_zero(headr,tailr);
    if(sign)
(*headr)->data=-(*headr)->data;
    return SUCCESS;
}

int divide(List **head1,List **head2,List **tail2,List **headr,List **tailr,int sign)
{
    if(compare_lists(head1,head2)==SMALL)
    {
        insert_first(headr,tailr,0);
        return SUCCESS;
    }
    List *temp1,*head3,*tail3,*headb,*tailb;
    headb=tailb=head3=tail3=NULL;
    temp1=*head1;
    int count=0;
    while(temp1!=NULL)
    {
        insert_last(&head3,&tail3,temp1->data);
        delete_zero(&head3,&tail3);
        while(compare_lists(head2,&head3)==LARGE&&temp1->next!=NULL)
        {
        temp1=temp1->next;
        insert_last(&head3,&tail3,temp1->data);
        delete_zero(&head3,&tail3);
        if(headr!=NULL)
        insert_last(headr,tailr,0);
        }
        while(compare_lists(head2,&head3)!=LARGE)
        {
        subraction(&tail3,tail2,&headb,&tailb,0);
        count++;
        delete_list(&head3,&tail3);
        head3=headb;
        tail3=tailb;
        headb=tailb=NULL;
        }
        insert_last(headr,tailr,count);
        count=0;
        temp1=temp1->next;
    }
    delete_zero(headr,tailr);
    if(sign)
(*headr)->data=-(*headr)->data;
    return SUCCESS;
}