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
    int DBMS;
    int DS;
    int C;
    int Total;
    int Percent;

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

STD* searchById(char * );

void modSTD(char *);

int size();

void list();

void listByBranch(char *);
void listByName(char *);

void listMarksById(char *);

void insertMarks(char *);
void updateMarks(char *);

void searchAboveThreshold(int* percent);
void searchAboveThresholdAndBranch(int *,char *);

void update();

void updateMarksFile();