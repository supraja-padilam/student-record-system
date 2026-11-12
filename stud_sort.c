#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int countNode(SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}

void sort(SLL *ptr)
{
    printf("\033[34m**********\n");
    if(ptr==NULL)
    {
        printf("NO records found\n");
        printf("**********\033[0m\n");
        return;
    }
    SLL *p1=ptr,*p2,t;
    int i,j,c=countNode(ptr);
    char op;
    printf("enter your op:\nn/N sort with name\np/P sort with percentage\n");
    scanf(" %c",&op);
    switch(op)
    {
        case 'n':
        case 'N':
            for(i=0;i<c-1;i++)
            {
                p2=p1->next;
                for(j=0;j<c-1-i;j++)
                {
                    if(strcmp(p1->name,p2->name)>0)
                    {
                        t.rollno=p1->rollno;
                        strcpy(t.name,p1->name);
                        t.percentage=p1->percentage;

                        p1->rollno=p2->rollno;
                        strcpy(p1->name,p2->name);
                        p1->percentage=p2->percentage;

                        p2->rollno=t.rollno;
                        strcpy(p2->name,t.name);
                        p2->percentage=t.percentage;
                    }
                    p2=p2->next;
                }
                p1=p1->next;
            }
            break;

        case 'p':
        case 'P':
            for(i=0;i<c-1;i++)
            {
                p2=p1->next;
                for(j=0;j<c-1-i;j++)
                {
                    if(p1->percentage < p2->percentage)
                    {
                        t.rollno=p1->rollno;
                        strcpy(t.name,p1->name);
                        t.percentage=p1->percentage;

                        p1->rollno=p2->rollno;
                        strcpy(p1->name,p2->name);
                        p1->percentage=p2->percentage;

                        p2->rollno=t.rollno;
                        strcpy(p2->name,t.name);
                        p2->percentage=t.percentage;
                    }
                    p2=p2->next;
                }
                p1=p1->next;
            }
            break;

        default:
            printf("invalid option\n");
    }
    printf("**********\033[0m\n");
}