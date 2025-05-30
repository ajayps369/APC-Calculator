#include"dll.h"

int main(int argc,char *argv[])
{
    Dlist*head1=NULL;
    Dlist*tail1=NULL;
    Dlist*head2=NULL;
    Dlist*tail2=NULL;
    Dlist*head3=NULL;
    Dlist*tail3=NULL;
    char oper=argv[2][0];

    if(argc==4)
    {
        character_to_int(&head1,&tail1,argv[1]);
        character_to_int(&head2,&tail2,argv[3]);
    }
    else
    {
        printf("Invalid arguiments\n");
        return FAILURE;
    }
    switch(oper)
    {
        case '+':
        if(addition(&head1,&tail1,&head2,&tail2,&head3,&tail3)==SUCCESS)
        {
            output(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper);
            /*printf("\nAddition Result=");
            print_list(head3);
            printf("\n");*/
            break;
        }
        case '-':
        if(check_greater(&head1,&tail1,&head2,&tail2,&head3,&tail3,argv)==SUCCESS)
        {
            output(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper);
            /*printf("\nSubstraction Result=");
            print_list(head3);
            printf("\n");*/
            break;
        }
        case 'x':
        if(multiplication(&head1,&tail1,&head2,&tail2,&head3,&tail3)==SUCCESS)
        {
            output(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper);
            /*printf("\nMultiplication Result=");
            print_list(head3);
            printf("\n");*/
            break;
        }
        case '/':
        if(division(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper)==SUCCESS)
        {
            output(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper);
            /*printf("\nDivision Result=");
            print_list(head3);
            printf("\n");*/
            break;
        }
        case '%':
        if(division(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper)==SUCCESS)
        {
            output(&head1,&tail1,&head2,&tail2,&head3,&tail3,oper);
            /*printf("\nModulus Result=");
            print_list(head3);
            printf("\n");*/
            break;
        }
        default:printf("Invalid operator\n");
        break;
    }
    return SUCCESS;
}
