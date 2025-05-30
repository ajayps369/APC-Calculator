#include "dll.h"

int character_to_int(Dlist**head,Dlist**tail,char *str)
{
    if(str==NULL)
    {
        return FAILURE;
    }
    int i=0,digit;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
        {
            printf("\nInvalid number\n");
            return FAILURE;
        }
        else
        {
            digit=str[i]-48;
            insert_at_last(head,tail,digit);
        }
        i++;
    }
    return SUCCESS;
}

int insert_at_last(Dlist **head, Dlist **tail, int value)
{
	Dlist *new=malloc(sizeof(Dlist));
	if(new==NULL)
	{
		return FAILURE;
	}
	new->data=value;
	new->prev=NULL;
	new->next=NULL;
	if(*head==NULL)
	{	
		*head=new;
        *tail=new;
		return SUCCESS;
	}
	new->prev=*tail;
	(*tail)->next=new;
	*tail=new;
    return SUCCESS;
}

int insert_at_first(Dlist **head, Dlist **tail, int value)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data=value;
    new->prev=NULL;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    new->next=*head;
    (*head)->prev=new;
    *head=new;
}

int print_list(Dlist *head)
{
	if(head==NULL)
	{
		printf("INFO:List is empty\n");
	}
	else
	{
	    while(head)		
	    {
		    printf("%d",head->data);
		    head=head->next;
	    }
    }
}

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist*temp=*head;
    while(temp!=NULL)
    {
        Dlist*temp2=temp->next;
        free(temp);
        temp=temp2;   
    }
    *head=NULL;
    *tail=NULL;
    return SUCCESS;
}

int delete_zero(Dlist** head,Dlist**tail)
 {

    while ((*head)!=NULL && (*head)->data==0)
    {
        dl_delete_first(head,tail);
        *head = (*head)->next;
    }
    return SUCCESS;
}

void output(Dlist**head1,Dlist**tail1,Dlist**head2,Dlist**tail2,Dlist**head3,Dlist**tail3,char oper)
{
    printf("\033[32m════════════════════════════════════════════════\n");
    printf("\033[36m||       ARITHMETIC PRECISION CALCULATOR      ||\n");
    printf("\033[32m════════════════════════════════════════════════\n");
    printf("\033[33m");
    print_list(*head1);
    printf(" %c ",oper);
    print_list(*head2);
    printf("\nAnswer = ");
    print_list(*head3);
    printf("\n\033[32m════════════════════════════════════════════════\n");
    printf("\033[31m[1][2][3][4][5][6][7][8][9][0][+][-][*][/][%%][=]\n");
    printf("\033[32m════════════════════════════════════════════════\n");
}

int dl_delete_first(Dlist **head, Dlist **tail)
{
    if(*head==NULL)
    {
        return FAILURE;
    }
    if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return SUCCESS;
    }
    else
    {
        Dlist *temp;
        temp=*head;
        *head=(*head)->next;
        free(temp);
        (*head)->prev=NULL;
        return SUCCESS;
    }
}