#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student.h"

void delNode(SLL **ptr)
{
    int num,found=0;
    char str[50],op;
    SLL *del,*prev;

    printf("\033[34m*********\n");
    if(*ptr==NULL)
    {
        printf("NO records found\n");
        printf("**********\033[0m\n");
        return;
    }

    printf("enter option\nR/r : Enter roll number to delete\nN/n : Enter name to delete\n");
    scanf(" %c",&op);

    switch(op)
    {
        case 'r':
        case 'R':
            printf("enter rollno:\n");
            scanf("%d",&num);
            break;

        case 'n':
        case 'N':
            printf("enter name:\n");
            scanf("%s",str);
            for(del=*ptr;del;del=del->next)
            {
                if(strcmp(del->name,str)==0)
                {
                    printf("%d %s %.2f\n",del->rollno,del->name,del->percentage);
                    found=1;
                }
            }
            if(!found)
            {
                printf("name not found\n");
                printf("**********\033[0m\n");
                return;
            }
            printf("enter rollno to delete:\n");
            scanf("%d",&num);
            break;

        default:
            printf("invalid option\n");
            printf("**********\033[0m\n");
            return;
    }

    del=*ptr;
    prev=NULL;
    while(del)
    {
        if(del->rollno==num)
        {
            if(prev==NULL)
                *ptr=del->next;
            else
                prev->next=del->next;
            free(del);
            printf("record deleted successfully\n");
            printf("**********\033[0m\n");
            return;
        }
        prev=del;
        del=del->next;
    }
    printf("rollno not found\n");
    printf("**********\033[0m\n");
}