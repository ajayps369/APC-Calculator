#include"dll.h"

int addition(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3)
{
    Dlist*temp1=*tail1;
    Dlist*temp2=*tail2;
    int sum=0,carry=0,rem=0;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL && temp2!=NULL)
        {
            sum=temp1->data+temp2->data+carry;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if(temp1!=NULL && temp2==NULL)
        {
            sum=temp1->data+carry;
            temp1=temp1->prev;
        }
        else if(temp1==NULL && temp2!=NULL)
        {
            sum=temp2->data+carry;
            temp2=temp2->prev;
        }
        if(sum>9)
        {
            rem=sum%10;
            carry=0;
            carry=sum/10;
            insert_at_first(head3,tail3,rem);
        }
        else
        {
            insert_at_first(head3,tail3,sum);
            carry=0;
        }
    }
    if(carry!=0)
    {
        insert_at_first(head3,tail3,carry);
    }
    return SUCCESS;
}