#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct STD
{
    char *ID;
    char *Name;
    char *Branch;
    struct STD *nextL;
    struct STD *nextR;

}STD;

/* Defiend in some othert file */
extern STD hdr;

/* ADT interface functions */
void init();

void joinL();
void joinR();

void leave(char * );

STD* leaveL();
STD* leaveR();

int size();
