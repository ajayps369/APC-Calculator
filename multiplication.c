#include "dll.h"

int multiplication(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3)
{
    Dlist*temp1=*tail1;
    Dlist*temp2=*tail2;
    Dlist*res1_h=NULL;
    Dlist*res2_h=NULL;
    Dlist*res3_h=NULL;
    Dlist*res1_t=NULL;
    Dlist*res2_t=NULL;
    Dlist*res3_t=NULL;

    int mul=0,rem=0,count=0;
    while(temp2!=NULL)
    {
        rem=0;
        for(int i=0;i<count;i++)
        {
            insert_at_first(&res1_h,&res1_t,0);
        }
        while(temp1!=NULL)
        {
            mul=(temp1->data)*(temp2->data)+rem;
            if(mul>9)
            {
                int digit=mul%10;
                rem=mul/10;
                insert_at_first(&res1_h,&res1_t,digit);
            }
            else
            {
                insert_at_first(&res1_h,&res1_t,mul);
                rem=0;
            }
            temp1=temp1->prev;
        }
        if(rem!=0)
        {
            insert_at_first(&res1_h,&res1_t,rem);
        }
        addition(&res1_h,&res1_t,&res2_h,&res2_t,&res3_h,&res3_t);
        temp1=*tail1;
        temp2=temp2->prev;
        res2_h=res3_h;
        res2_t=res3_t;
        res3_h=NULL;
        res3_t=NULL;
        delete_list(&res1_h,&res1_t);
        res1_h=NULL;
        res1_t=NULL;
        count++;
        
    }
    *head3=res2_h;
    *tail3=res2_t;
    return SUCCESS;
}
