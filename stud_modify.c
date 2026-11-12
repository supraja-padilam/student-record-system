#include<stdio.h>
#include<string.h>
#include"student.h"

void modifyNode(SLL *ptr)
{
    int num,count=0;
    char str[50],op;
    float per;
    SLL *t,*target=NULL;

    printf("\033[34m**********\n");
    if(ptr==NULL)
    {
        printf("No student records available\n");
        printf("**********\033[0m\n");
        return;
    }

    printf("Enter which record to search for modification\n\n");
    printf("R/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\n");
    scanf(" %c",&op);

    switch(op)
    {
        case 'r':
        case 'R':
            printf("enter rollno:\n");
            scanf("%d",&num);
            for(t=ptr;t;t=t->next)
            {
                if(t->rollno==num)
                {
                    target=t;
                    break;
                }
            }
            break;

        case 'n':
        case 'N':
            printf("enter name:\n");
            scanf("%s",str);
            for(t=ptr;t;t=t->next)
            {
                if(strcmp(t->name,str)==0)
                {
                    printf("%d %s %.2f\n",t->rollno,t->name,t->percentage);
                    target=t;
                    count++;
                }
            }
            if(count>1)
            {
                printf("enter rollno of the record to modify:\n");
                scanf("%d",&num);
                target=NULL;
                for(t=ptr;t;t=t->next)
                {
                    if(t->rollno==num && strcmp(t->name,str)==0)
                    {
                        target=t;
                        break;
                    }
                }
            }
            break;

        case 'p':
        case 'P':
            printf("enter percentage:\n");
            scanf("%f",&per);
            for(t=ptr;t;t=t->next)
            {
                if(t->percentage==per)
                {
                    printf("%d %s %.2f\n",t->rollno,t->name,t->percentage);
                    target=t;
                    count++;
                }
            }
            if(count>1)
            {
                printf("enter rollno of the record to modify:\n");
                scanf("%d",&num);
                target=NULL;
                for(t=ptr;t;t=t->next)
                {
                    if(t->rollno==num && t->percentage==per)
                    {
                        target=t;
                        break;
                    }
                }
            }
            break;

        default:
            printf("invalid option\n");
            printf("**********\033[0m\n");
            return;
    }

    if(target==NULL)
    {
        printf("record not found\n");
        printf("**********\033[0m\n");
        return;
    }

    printf("current details: %d %s %.2f\n",target->rollno,target->name,target->percentage);
    printf("enter new name:\n");
    scanf("%s",target->name);
    do
    {
        printf("enter new percentage (0 to 100):\n");
        scanf("%f",&target->percentage);
    }while(target->percentage<0 || target->percentage>100);
    printf("record modified successfully\n");
    printf("**********\033[0m\n");
}