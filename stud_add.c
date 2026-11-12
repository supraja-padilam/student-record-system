#include"student.h"
void add(SLL **ptr)
{
SLL *new;
new=malloc(sizeof(SLL));
if(new==NULL)
{
printf("memory not allocated\n");
return;
}
int roll=1,found;
SLL *temp;
while(1)
{
found=0;
temp=*ptr;
while(temp!=NULL)
{
if(temp->rollno==roll)
{
found=1;
break;
}
temp=temp->next;
}
if(found==0)
break;
roll++;
}
new->rollno=roll;
printf("enter name and percentage\n");
scanf("%s %f\n",new->name,&new->percentage);
new->next=0;
if(*ptr==0)
*ptr=new;
else{
SLL* last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}