#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
        int rollno;
        char name[50];
        float percentage;
        struct student *next;
}SLL;
void add(SLL **);
void delNode(SLL **);
void print(SLL *);
void modifyNode(SLL *);
void saveFile(SLL *);
void sort(SLL *);
void deleteall(SLL **);
void reverseLink(SLL **);
int countNode(SLL *);
void loadFile(SLL **ptr);