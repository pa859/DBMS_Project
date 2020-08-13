#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *randstring(int length) {    
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;        
    }
    else {
        printf("No memory");
        exit(1);
    }
}

int insert(){
    char *name,*branch;

    printf("NAME : ");
    scanf("%s",name);
    printf("%s",name);

    return 0;
}

int insertStudent(){
    int n;
    printf("\nEnter the number of Students to be inserted\n-->");
    scanf("%d",&n);

    while(n--){
        insert();
    }

    return 0;
}

int main(){

    int input;

    printf("=======================================\n\n");

    while(1){
        printf("1. Insert Students \n2. Insert Marks of a registered Student \n3. Delete a Student \n4. Show Marks \n5. Search Students \n6. Exit\n");

        scanf("%d",&input);

        switch (input)
        {
        case 1:
            insertStudent();
            break;
        
        case 2:
            
            break;
        
        case 3:
            
            break;
        
        case 4:
            
            break;

        case 5:
            
            break;
        
        default:
            exit(1);
        }

        printf("\n=======================================\n\n");

    }

    return 0;
}