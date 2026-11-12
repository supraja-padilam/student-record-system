#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

void saveFile(SLL *ptr)
{
    FILE *fp=fopen("student.dat","w");
    if(fp==NULL)
    {
        printf("unable to open student.dat\n");
        return;
    }
    while(ptr)
    {
        fprintf(fp,"%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    fclose(fp);
    printf("records saved to student.dat\n");
}

void loadFile(SLL **ptr)
{
    FILE *fp=fopen("student.dat","r");
    SLL *new,*last=NULL;
    int roll;
    char name[50];
    float per;

    if(fp==NULL)
        return;

    while(fscanf(fp,"%d %49s %f",&roll,name,&per)==3)
    {
        new=malloc(sizeof(SLL));
        if(new==NULL)
        {
            printf("memory allocation failed\n");
            break;
        }
        new->rollno=roll;
        strcpy(new->name,name);
        new->percentage=per;
        new->next=NULL;
        if(last==NULL)
            *ptr=new;
        else
            last->next=new;
        last=new;
    }
    fclose(fp);
}