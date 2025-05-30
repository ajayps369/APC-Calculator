#include"dll.h"

int division(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3,char oper)
{
    Dlist *temp = *head1;

    Dlist*res1_h=NULL;
    Dlist*res1_t=NULL;
    Dlist*Q_h=NULL;
    Dlist*Q_t=NULL;

    insert_at_last(&res1_h,&res1_t,temp->data);
    while(compare_list(*head2,*tail2,res1_h,res1_t,temp)==FAILURE && temp->next!=NULL)
    {
        temp=temp->next;
        insert_at_last(&res1_h,&res1_t,temp->data);
    }
    if(temp->next!=NULL)
        temp=temp->next;
    if(do_division(head2,tail2,res1_h,res1_t,head3,tail3,&Q_h,&Q_t,temp)==SUCCESS)
        if(oper=='/')
        {
            *head3=NULL;
            *tail3=NULL;
            *head3=Q_h;
            *tail3=Q_t;
            return SUCCESS;
        }
        else if(oper=='%')
        {
            *head3=NULL;
            *tail3=NULL;
            *head3=res1_h;
            *tail3=res1_t;
            return SUCCESS;
        }     
}

int do_division(Dlist**head2,Dlist**tail2,Dlist*res1_h,Dlist*res1_t,Dlist**head3,Dlist**tail3,Dlist**Q_h,Dlist**Q_t,Dlist*temp)
{
    int quotient=0;
    while(compare_list(*head2,*tail2,res1_h,res1_t,temp)==SUCCESS)
    {
        quotient++;
        substraction(&res1_h,&res1_t,head2,tail2,head3,tail3);
        delete_list(&res1_h,&res1_t);
        res1_h=*head3;
        res1_t=*tail3;
        *head3=NULL;
        *tail3=NULL;
    }
    printf("Divident\n");
    print_list(res1_h);
    insert_at_last(Q_h,Q_t,quotient);
    printf("Quotient");
    print_list(*Q_h);
    quotient=0;
    if(recursive_division(res1_h,res1_t,head2,tail2,head3,tail3,Q_h,Q_t,temp)==SUCCESS && temp!=NULL)
        return SUCCESS;
}

int compare_list(Dlist*op2_h,Dlist*op2_t,Dlist*op1_h,Dlist*op1_t,Dlist*temp)
{
    Dlist*temp1=op2_h;
    int len1=0;
    while(temp1!=NULL)
    {
        len1++;
        temp1=temp1->next;
    }
    Dlist*temp2=op1_h;
    int len2=0;
    while(temp2!=NULL)
    {
        len2++;
        temp2=temp2->next;
    }
    if(len2<len1)
        return FAILURE;
    else if(len2>len1)
        return SUCCESS;
    else if(len2==len1)
    {
        temp1=op2_h;
        temp2=op1_h;
        while(temp1!=NULL || temp2!=NULL)
        {
            if((temp1->data)<(temp2->data))
            {
                return SUCCESS;
            }
            else if((temp1->data)==(temp2->data))
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if((temp1->data)>(temp2->data))
            {
                return FAILURE;
            }
        }
    }
}

int recursive_division(Dlist* res1_h, Dlist* res1_t, Dlist** head2, Dlist** tail2,Dlist**head3,Dlist**tail3,Dlist**Q_h,Dlist**Q_t,Dlist*temp)
{
        if(compare_list(*head2,*tail2,res1_h,res1_t,temp)==FAILURE && temp!=NULL)
        {
            insert_at_last(&res1_h,&res1_t,temp->data);
            // printf("\ndivident");
            // print_list(res1_h);
            if(temp->next!=NULL)
                temp=temp->next;
        }
        while(compare_list(*head2,*tail2,res1_h,res1_t,temp)==FAILURE && temp!=NULL)
        {
            insert_at_last(&res1_h,&res1_t,temp->data);
            // printf("\nDivident");
            // print_list(res1_h);
            // printf("\nqotient");
            // print_list(*Q_h);
            insert_at_last(Q_h,Q_t,0);
            temp=temp->next;
        }
        do_division(head2,tail2,res1_h,res1_t,head3,tail3,Q_h,Q_t,temp);
        return SUCCESS;
}