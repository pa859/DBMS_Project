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
    scanf("%s",new->ID);  

    printf("Enter Name : ");
    new->Name = (char *)malloc(100*sizeof(char));
    scanf("%s",new->Name);

    printf("Enter Branch : ");
    new->Branch = (char *)malloc(100*sizeof(char));
    scanf("%s",new->Name);

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
            if(ptr->nextL != NULL){
                ptr->nextL->nextR = ptr->nextR;
                if(hdr.nextL == ptr){
                    hdr.nextL = ptr->nextR;
                }
            }
            if(ptr->nextR != NULL){    
                ptr->nextR->nextL = ptr->nextL;
                if(hdr.nextR == ptr){
                    hdr.nextR = ptr->nextL;
                }
            }    
            if(hdr.nextL == hdr.nextR )
                hdr.nextL = hdr.nextR = NULL;
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