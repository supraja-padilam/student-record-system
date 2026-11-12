#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

void reverseLink(SLL **ptr)
{
    printf("\033[34m**********\n");
    if(*ptr==NULL)                 /* empty list, not ptr==0 */
    {
        printf("NO record found\n");
        printf("**********\033[0m\n");
        return;
    }

    SLL *t=*ptr;                   /* local walker; head is untouched */
    printf("before:\n");
    while(t)
    {
        printf("%d %s %f\n",t->rollno,t->name,t->percentage);
        t=t->next;
    }

    SLL *prev=NULL,*cur=*ptr,*next;
    while(cur)
    {
        next=cur->next;            /* 1. remember the rest */
        cur->next=prev;            /* 2. flip this link    */
        prev=cur;                  /* 3. move prev forward */
        cur=next;                  /* 4. move cur forward  */
    }
    *ptr=prev;                     /* new head = old last node */

    printf("After:\n");
    t=*ptr;
    while(t)
    {
        printf("%d %s %f\n",t->rollno,t->name,t->percentage);
        t=t->next;
    }
    printf("**********\033[0m\n");
}