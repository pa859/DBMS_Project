#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "DbmsPro.h"

void load()
{
    FILE *fl = fopen("students.txt","r");

    char line[100];

    while(!feof(fl))
    {
        fscanf(fl, "%s", line);
        printf("%s",line);
    }

    fclose(fl);
}