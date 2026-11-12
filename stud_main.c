#include<stdio.h>
#include"student.h"
int main()
{
        SLL *headptr=0;
        char op;
        loadFile(&headptr);
        while(1)
        {
                printf("\033[32m********** STUDENT RECORD MENU **********\n\033[0m");
                printf("a/A : Add new record\nd/D : Delete a record\ns/S : show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\n");
                printf("Enter your choice:\n");
                scanf(" %c",&op);
                switch(op)
                {
                        case 'a':
                        case 'A':add(&headptr);break;
                        case 'd':
                        case 'D':delNode(&headptr);break;
                        case 's':
                        case 'S':print(headptr);break;
                        case 'm':
                        case 'M':modifyNode(headptr);break;
                        case 'v':
                        case 'V':saveFile(headptr);break;
                        case 'e':
                        case 'E':{
                                        char ch ;
                                        printf("S/s.Save and Exit\n");
                                        printf("e/E.Exit without Saving\n");
                                        printf("enter your choice\n");
                                        scanf(" %c",&ch);
                                        switch(ch)
                                        {
                                                case 's':
                                                case 'S':{
                                                                 saveFile(headptr);
                                                                 deleteall(&headptr);
                                                                 return 0;
                                                         }
                                                         break;
                                                case 'e':
                                                case 'E':
                                                         {
                                                                 printf("exited without saving\n");
                                                                 deleteall(&headptr);
                                                                 return 0;
                                                         }
                                                         break;
                                                default:printf("invalid option\n");
                                                        break;
                                        }
                                }break;
                        case 't':
                        case 'T':sort(headptr);break;
                        case 'l':
                        case 'L':deleteall(&headptr);break;
                        case 'r':
                        case 'R':reverseLink(&headptr);break;
                        default:printf("unknown choice\n");
                }
        }
}
 