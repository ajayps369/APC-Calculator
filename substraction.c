#include"dll.h"

int check_greater(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3,char *argv[])
{
    if(strlen(argv[1])==strlen(argv[3]))
    {
        if(strcmp(argv[1],argv[3])<0)
        {
            swap_list(head1, tail1, head2, tail2, head3, tail3);
        }
    }
    else if(strlen(argv[1])<strlen(argv[3]))
    {
        swap_list(head1, tail1, head2, tail2, head3, tail3);
    }
    substraction(head1,tail1,head2,tail2,head3,tail3);
    return SUCCESS;
}

void swap_list(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3)
{
    Dlist*temp=*head1;
    *head1=*head2;
    *head2=temp;
    temp=*tail1;
    *tail1=*tail2;
    *tail2=temp;
    substraction(head1,tail1,head2,tail2,head3,tail3);
}

int substraction(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3)
{
    Dlist*temp1=*tail1;
    Dlist*temp2=*tail2;
    int num1,num2,borrow=0;
    while(temp1!=NULL)
    {
        if(temp2!=NULL)
        {
            num1=borrow==1 ?  ((temp1->data)-1) : ((temp1->data));
            num2=temp2->data;
            if(update(num1,num2,head3,tail3,&borrow)==FAILURE)
                return FAILURE;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else{
            num1=borrow==1 ? ((temp1->data)-1) : ((temp1->data));
            num2=0;
            if(update(num1,num2,head3,tail3,&borrow)==FAILURE)
                return FAILURE;
            temp1=temp1->prev;
        }
    }
    delete_zero(head3,tail3);
    return SUCCESS;
}

int update(int num1,int num2,Dlist**head3,Dlist**tail3,int *borrow)
{
    int res;
    if(num1<num2)
    {
        *borrow=1;
        num1+=10;
        int res=num1-num2;
        insert_at_first(head3,tail3,res);
    }
    else
    {
        *borrow=0;
        res=num1-num2;
        insert_at_first(head3,tail3,res);
    }
    return SUCCESS;
}
