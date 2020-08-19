#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DbmsPro.h"

//To create a new student

int main()
{
    int index;
    char temp;
    char ID[100];
    char Branch[100];
    char Name[100];
    int Threshold;
    init();
    while(1)
    {
        scanf("%d",&index);
        //scanf("%c",&temp);
        
        if(index == 1)
        {
            joinL();
            update();
        }
        else if(index == 2)
        {   strcpy(ID," ");
            printf("Enter ID : ");
            scanf("%s",ID);
            modSTD(ID);
            update();
        }
        else if(index == 3)
        {
            strcpy(ID," ");
            printf("Enter ID : ");
            scanf("%s",ID);
            leave(ID);
            update();
        }
        else if(index == 4)
        {
            list();
            printf("\n");

        }
        else if(index == 5)
        {
            strcpy(Branch," ");
            printf("Enter Branch : ");
            scanf("%s",Branch);
            listByBranch(Branch);
            printf("\n");

        }
        else if(index == 6)
        {
            strcpy(Name," ");
            printf("Enter Name : ");
            scanf("%s",Name);
            listByName(Name);
            printf("\n");

        }
        else if(index == 7)
        {
            strcpy(ID," ");
            printf("Enter ID : ");
            scanf("%s",ID);
            insertMarks(ID);
            updateMarksFile();

        }
        else if(index == 8)
        {
            strcpy(ID," ");
            printf("Enter ID : ");
            scanf("%s",ID);
            updateMarks(ID);
            updateMarksFile();

        }
        else if(index == 9)
        {
            strcpy(ID," ");
            printf("Enter ID : ");
            scanf("%s",ID);
            listMarksById(ID);
            printf("\n");

        }
        else if(index == 10)
        {
            Threshold = 0;
            printf("Enter Threshold Percentage : ");
            scanf("%d",&Threshold);
            searchAboveThreshold(&Threshold);
            printf("\n");

        }
        else if(index == 11)
        {
            Threshold = 0;
            printf("Enter Threshold Percentage : ");
            scanf("%d",&Threshold);
            printf("\n");
            strcpy(Branch," ");
            printf("Enter Branch : ");
            scanf("%s",Branch);            
            searchAboveThresholdAndBranch(&Threshold,Branch);
            printf("\n");

        }
        else
        {
            break;
        }

    }
    return 0;
}