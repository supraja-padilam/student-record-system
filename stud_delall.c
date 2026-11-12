#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
void deleteall(SLL **ptr)
{
if(ptr==0)
{
printf("no records found\n");
printf("**********\033[0m\n");
return;
}
SLL *del=*ptr;
int c=1;
while(del)
{
*ptr=del->next;
printf("Node pos:%d deleted\n",c++);
sleep(1);
free(del);
del=*ptr;
}
printf("ALL record deleted\n");
}