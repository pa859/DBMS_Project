#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "DbmsPro.h"

/*void joinLoad(char *ID,char *Name,char *Branch)
{
	STD *new = (STD *)malloc(sizeof(STD));
	assert(new != NULL); // Stop if problem
    new->ID = (char *)malloc(100*sizeof(char));
    strcpy(new->ID,ID);
    new->Name = (char *)malloc(100*sizeof(char));
    strcpy(new->Name,Name);

    new->Branch = (char *)malloc(100*sizeof(char));
    strcpy(new->Branch,Branch);

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

void load()
{
    FILE *fl = fopen("students.txt","r");

    char ID[100];
    char Name[100];
    char Branch[100];
    char temp[100];

    while (!feof(fl))
    {
        //count++;
        strcpy(ID," ");
        strcpy(Name," ");
        strcpy(Branch," ");
        strcpy(temp," ");
        fscanf(fl, "%s", temp);
        strcpy(temp," ");
        fscanf(fl, "%s", temp);
        strcpy(temp," ");
        fscanf(fl, "%s", ID);
        fscanf(fl, "%s", temp);
        strcpy(temp," ");
        fscanf(fl, "%s", temp);
        strcpy(temp," ");
        fscanf(fl, "%s", Name);
        fscanf(fl, "%s", temp);
        strcpy(temp," ");
        fscanf(fl, "%s", temp);
        fscanf(fl, "%s", Branch);
        joinLoad(ID,Name,Branch);
    }

    fclose(fl);
}
*/
void main(){
    load();
    //leaveR();
    STD *temp;
    STD *ptr = hdr.nextR;
    printf("%d",size());
	while (ptr->nextL != NULL)
	{
        ptr = ptr->nextL;
	}	
    hdr.nextL = ptr->nextR;
    hdr.nextL = NULL;
    ptr->nextR = NULL;
    free(ptr);
    list();
}