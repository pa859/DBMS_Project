#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DbmsPro.h"

/* storage allocated here */
STD hdr;

/* ADT interface functions */
/* THink of hdr as if it is on top 
of all member nodes of deque.
Left and right of header is not symmetric to
those of member nodes */

void init()
{
	// unused
	hdr.Branch = NULL;
    hdr.ID = NULL;
    hdr.Name = NULL;
	hdr.DBMS = 0;
	hdr.DS = 0;
	hdr.C = 0;
	hdr.nextL = hdr.nextR = NULL;
}

void joinL()
{
	STD *new = (STD *)malloc(sizeof(STD));
	assert(new != NULL); // Stop if problem
    printf("Enter ID : ");
    new->ID = (char *)malloc(100*sizeof(char));
    scanf("%s",new->ID);

    printf("Enter Name : ");
    new->Name = (char *)malloc(100*sizeof(char));
    scanf("%s",new->Name);

    printf("Enter Branch : ");
    new->Branch = (char *)malloc(100*sizeof(char));
    scanf("%s",new->Branch);

	new->DBMS = -1;
	new->DS = -1;
	new->C = -1;
	new->Total = -1;
    new->Percent = -1;

	if (hdr.nextL == NULL)
	{
		assert(hdr.nextR == NULL);
		hdr.nextL = hdr.nextR = new;
		new->nextL = new->nextR = NULL;
		return;
	}

	assert(hdr.nextR != NULL);
	assert(hdr.nextL->nextL == NULL);
	hdr.nextL->nextL = new;
	new->nextR = hdr.nextL;
	new->nextL = NULL;
	hdr.nextL = new;
}

void joinR()
{
	STD *new = (STD *)malloc(sizeof(STD));
	assert(new != NULL); // Stop if problem

	printf("Enter ID : ");
    new->ID = (char *)malloc(100*sizeof(char));
    scanf("%[^\n]",new->ID);  

    printf("Enter Name : ");
    new->Name = (char *)malloc(100*sizeof(char));
    scanf("%[^\n]",new->Name);

    printf("Enter Branch : ");
    new->Branch = (char *)malloc(100*sizeof(char));
    scanf("%[^\n]",new->Name);

	if (hdr.nextL == NULL)
	{
		assert(hdr.nextR == NULL);
		hdr.nextL = hdr.nextR = new;
		new->nextL = new->nextR = NULL;
		return;
	}

	assert(hdr.nextR != NULL);
	assert(hdr.nextL->nextL == NULL);
	new->nextR = NULL;
	new->nextL = hdr.nextR;
	hdr.nextR->nextR = new;
	hdr.nextR = new;
}

void leave(char *ID)
{
    STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
        if(strcmp(ID,ptr->ID) == 0)
        {
			if((hdr.nextL == hdr.nextR) && size() == 1)
			{
				hdr.nextL = hdr.nextR = NULL;
				free(ptr);
				break;
			}
            if(ptr->nextL != NULL){
				if(hdr.nextR == ptr){
                    hdr.nextR = ptr->nextL;
                }
                ptr->nextL->nextR = ptr->nextR;
            }
            if(ptr->nextR != NULL){    
				if(hdr.nextL == ptr){
                    hdr.nextL = ptr->nextR;
                }
                ptr->nextR->nextL = ptr->nextL;
            }    
            free(ptr);
            break;
        }
		ptr = ptr->nextR;
	}    
}

STD* leaveL()
{
	STD *tmp;
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	tmp = hdr.nextL;
	assert(tmp->nextL == NULL);
	if (tmp->nextR == NULL)
	{
		hdr.nextL = hdr.nextR = NULL;
		free(tmp);
		return NULL;
	}

	tmp->nextR->nextL = NULL;
	hdr.nextL = tmp->nextR;
	free(tmp);
	return NULL;
}

STD* leaveR()
{
	STD *tmp;
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	tmp = hdr.nextR->nextL;
	if (tmp != NULL)
		tmp->nextR = NULL;
	free(hdr.nextR);
	hdr.nextR = tmp;
	if (tmp == NULL)
		hdr.nextL = NULL;
	assert(tmp != NULL || hdr.nextL == NULL);
	return NULL;
}


int size()
{
	int i = 0;
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		i++;
		ptr = ptr->nextR;
	}
	return i;
}

STD* searchById(char * ID)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(ID,ptr->ID) == 0)
		{
			return ptr;
		}
		ptr = ptr->nextR;
	}
	return NULL;
}

void modSTD(char *ID)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(ID,ptr->ID) == 0){
			printf("Enter Name : ");
			strcpy(ptr->Name," ");
			scanf("%s",ptr->Name);
			printf("Enter Branch : ");
			strcpy(ptr->Branch," ");
			scanf("%s",ptr->Branch);
			break;
		}
		ptr = ptr->nextR;
	}
}

void list()
{
	STD *ptr = hdr.nextR;

	while (ptr != NULL)
	{
		printf("ID : ");
		printf(ptr->ID);
		printf("          ");
		printf("Name : ");
		printf(ptr->Name);
		printf("          ");
		printf("Branch : ");
		printf(ptr->Branch);
		printf("\n");
		ptr = ptr->nextL;
	}
}

void listMarksById(char *ID)
{
	STD *ptr = hdr.nextR;

	while (ptr != NULL)
	{
		if(strcmp(ID,ptr->ID) == 0)
		{
			printf("ID : ");
			printf(ptr->ID);
			printf("          ");
			printf("DBMS : ");
			printf("%d",ptr->DBMS);
			printf("          ");
			printf("DS : ");
			printf("%d",ptr->DS);
			printf("          ");
			printf("C : ");
			printf("%d",ptr->C);
			printf("          ");
			printf("Total : ");
			printf("%d",ptr->Total);
			printf("/300");
			printf("          ");
			printf("Percent : ");
			printf("%d",ptr->Percent);
			printf(" %");
			printf("\n");
			break;
		}
		ptr = ptr->nextL;
	}
}

void listByBranch(char *Branch)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(Branch,ptr->Branch) == 0)
		{
			printf("ID : ");
			printf(ptr->ID);
			printf("          ");
			printf("Name : ");
			printf(ptr->Name);
			printf("          ");
			printf("Branch : ");
			printf(ptr->Branch);
			printf("\n");
		}
		ptr = ptr->nextR;
	}
}

void listByName(char *Name)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(Name,ptr->Name) == 0)
		{
		printf("ID : ");
		printf(ptr->ID);
		printf("          ");
		printf("Name : ");
		printf(ptr->Name);
		printf("          ");
		printf("Branch : ");
		printf(ptr->Branch);
		printf("\n");
		}
		ptr = ptr->nextR;
	}
}

void insertMarks(char *ID)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(ID,ptr->ID) == 0)
		{
		printf("Enter DBMS : ");
		scanf("%d",&ptr->DBMS);
		printf("Enter DS : ");
		scanf("%d",&ptr->DS);
		printf("Enter C : ");
		scanf("%d",&ptr->C);
		ptr->Total = ptr->DBMS + ptr->DS + ptr->C;
		ptr->Percent = (ptr->Total*100)/300;
		}
		ptr = ptr->nextR;
	}
}

void updateMarks(char *ID)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(strcmp(ID,ptr->ID) == 0)
		{
		printf("Enter DBMS : ");
		scanf("%d",&ptr->DBMS);
		printf("Enter DS : ");
		scanf("%d",&ptr->DS);
		printf("Enter C : ");
		scanf("%d",&ptr->C);
		ptr->Total = ptr->DBMS + ptr->DS + ptr->C;
		ptr->Percent = (ptr->Total*100)/300;
		}
		ptr = ptr->nextR;
	}
}

void searchAboveThreshold(int *percent)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if(ptr->Percent > *percent)
		{
			printf("ID : ");
			printf(ptr->ID);
			printf("          ");
			printf("DBMS : ");
			printf("%d",ptr->DBMS);
			printf("          ");
			printf("DS : ");
			printf("%d",ptr->DS);
			printf("          ");
			printf("C : ");
			printf("%d",ptr->C);
			printf("          ");
			printf("Total : ");
			printf("%d",ptr->Total);
			printf("/300");
			printf("          ");
			printf("Percent : ");
			printf("%d",ptr->Percent);
			printf(" %");
			printf("\n");
		}
		ptr = ptr->nextR;
	}
}

void searchAboveThresholdAndBranch(int *percent,char *Branch)
{
	STD *ptr = hdr.nextL;

	while (ptr != NULL)
	{
		if((ptr->Percent > *percent) && (strcmp(Branch,ptr->Branch) == 0))
		{
			printf("ID : ");
			printf(ptr->ID);
			printf("          ");
			printf("DBMS : ");
			printf("%d",ptr->DBMS);
			printf("          ");
			printf("DS : ");
			printf("%d",ptr->DS);
			printf("          ");
			printf("C : ");
			printf("%d",ptr->C);
			printf("          ");
			printf("Total : ");
			printf("%d",ptr->Total);
			printf("/300");
			printf("          ");
			printf("Percent : ");
			printf("%d",ptr->Percent);
			printf(" %");
			printf("\n");
		}
		ptr = ptr->nextR;
	}
}

void update()
{
	FILE *fl = fopen("students.txt","a");

	STD *ptr = hdr.nextL;

	char line[100];

	while (ptr != NULL)
	{
		strcpy(line," ");
		strcat(line,"ID : ");
		strcat(line,ptr->ID);
		strcat(line,"          ");
		strcat(line,"Name : ");
		strcat(line,ptr->Name);
		strcat(line,"          ");
		strcat(line,"Branch : ");
		strcat(line,ptr->Branch);
		strcat(line,"\n");
		fprintf(fl,line);
		ptr = ptr->nextR;
	}

	fclose(fl);
	
}

void updateMarksFile()
{
	FILE *fp = fopen("marks.txt","a");

	STD *ptr = hdr.nextL;

	char line[100];

	char DBMS[100];
	char DS[100];
	char C[100];
	char T[100];
	char P[100];

	while (ptr != NULL)
	{
		if(ptr->Total != -1)
		{
			strcpy(DBMS," ");
			strcpy(DS," ");
			strcpy(C," ");
			strcpy(T," ");
			strcpy(P," ");

			strcpy(line," ");
			strcat(line,"ID : ");
			strcat(line,ptr->ID);
			strcat(line,"          ");
			strcat(line,"DBMS : ");
			sprintf(DBMS, "%d", ptr->DBMS);
			strcat(line,DBMS);
			strcat(line,"          ");
			strcat(line,"DS : ");
			sprintf(DS, "%d", ptr->DS);
			strcat(line,DS);
			strcat(line,"          ");
			strcat(line,"C : ");
			sprintf(C, "%d", ptr->C);
			strcat(line,C);
			strcat(line,"          ");
			strcat(line,"Total : ");
			sprintf(T, "%d", ptr->Total);
			strcat(line,T);
			strcat(line,"/300");
			strcat(line,"          ");
			strcat(line,"Percent : ");
			sprintf(P, "%d", ptr->Percent);
			strcat(line,P);
			strcat(line," %");
			strcat(line,"\n");
			fprintf(fp,line);
		}
		ptr = ptr->nextR;
	}

	fclose(fp);
	
}