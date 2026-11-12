#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
void print(SLL *ptr)
{
printf("\033[34m**********\n");
if(ptr==0)
{
printf("NO record found\n");
printf("**********\033[0m\n");
return;
}
while(ptr)
{
printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
printf("**********\033[0m\n");
}