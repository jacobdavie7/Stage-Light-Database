//Davie, Jacob
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //random numbers for ID nums 
#include <unistd.h> //sleep functuion
#include "dip3.h"

struct lData{
    char name[51];
    int data[6]; //0=id  1=mode  2=Universe  3=DMX Address Start  4=DMX Address End  5=qty
};

//function prototypes
void rootMenu(int size, struct lData database[size]);
void editDatabaseMenu(int size, struct lData database[size]);
void addLight(int size, struct lData database[size]);
void editLight(int size, struct lData database[size]);
//void sortingMenu(int size, struct lData database[size]);
//void sortInsertion(int size, struct lData database[size]);
//void sortBubble(int size, struct lData database[size]);
//void sortBogo(int size, struct lData database[size]);
void print(int size, struct lData database[size]);
void export(int size, struct lData database[size]);


int main(int argc, char* argv[]){
    int i, j, lines, size;
    FILE* input;

    if(argc == 1){
        printf("No database file supplied\nUse the format ./a.out FILE\n\n");
        sleep(2);
        exit(1);
    } if(argc == 2){
        printf("Database file found!\n\n");
    }
    input = fopen(argv[1], "r"); //opens file
    fscanf(input, "%d", &lines); //finds number of lines to scan
    size = lines + 50;

    struct lData database[size]; //creates array with each spot the lData struct

//scans in data from file
    for(i = 0; i < lines; i++){
    fscanf(input, "%d", &database[i].data[0]);
    fscanf(input, "%s", &database[i].name[0]);
    fscanf(input, "%d", &database[i].data[1]);
    fscanf(input, "%d", &database[i].data[2]);
    fscanf(input, "%d", &database[i].data[3]);
    fscanf(input, "%d", &database[i].data[4]);
    fscanf(input, "%d", &database[i].data[5]);
    }

//sets all other id numbers to 0, used later to see what slots are
    while(i < size){
        database[i].data[0] = 0;
        i++;
    }
    rootMenu(size, database);
    fclose(input);
} //end of main

void rootMenu(int size, struct lData database[size]){
    int opt;
    while(opt != 1 || 2 || 3 || 4 || 5){
        printf("1- Edit Database\n");
        printf("2- Print Database\n");
        printf("3- Write database to file\n");
        printf("4- Run Dip Switch Calculator for Troubleshooting\n");
        printf("5- Quit\n\n");
        printf("What do you want to do, please select a number: \n");
        scanf("%d", &opt);
        printf("\n");

        if(opt == 1){
            editDatabaseMenu(size, database);
        } else if(opt == 2){
            print(size, database);
        } else if(opt == 3){
            export(size, database);
        } else if(opt == 4){
            calc(); //runs calc function (whole program) from header file
        } else if(opt == 5){
            exit(1);
        } else{
            printf("Thats not an option\nReloading Menu\n\n");
            sleep(1);
        }
    }
}
void editDatabaseMenu(int size, struct lData database[size]){
    int opt = 0;
    while(opt != 1 || 2){
        printf("1- Add Light\n");
        printf("2- Edit Light\n");
        printf("What do you want to do, please select a number: \n");
        scanf("%d", &opt);
        printf("\n");
        if(opt == 1){
            addLight(size, database);
        } else if(opt == 2){
            editLight(size, database);
        } else{
            printf("Thats not an option\nReloading Menu\n\n");
            sleep(1);
        }
    }
}

void addLight(int size, struct lData database[size]){
    int i, up= 10000;
    for(i = 0; i <= size; i++){
        if(database[i].data[0] == 0){
            database[i].data[0] = rand() % up;
            printf("What is the name?\n");
            scanf("%s", &database[i].name[0]);
            printf("\nWhat is the mode?\nMode 1: W\nMode 2: RGB\nMode 3: RGBA\nMode 4: RGBW\nMode 5: RGBAW\nMode 6: Mover\n");
            scanf("%d", &database[i].data[1]);
            printf("\nWhat is the universe?\n");
            scanf("%d", &database[i].data[2]);
            printf("\nWhat is the starting DMX Address?\n");
            scanf("%d", &database[i].data[3]);
            printf("\nWhat is the ending DMX Address?\n");
            scanf("%d", &database[i].data[4]);
            printf("\nWhat is the quantity ?\n");
            scanf("%d", &database[i].data[5]);
            printf("\n");
            rootMenu(size, database);
        }
    }
}

void editLight(int size, struct lData database[size]){
    int i, newval, id, opt = 0;
    char cOpt, TrashcanofDOOOOOOOOOOOOOM;
    printf("Would you like to print out the database to see the ID numbers?\nEnter (y)es or any other letter to continue\n");
    scanf("%c", &TrashcanofDOOOOOOOOOOOOOM);
    scanf("%c", &cOpt);
    if(cOpt == 'y'){
        print(size, database);
    } else{
        printf("Enter the ID number of the light you want to edit:\n");
        scanf("%d", &id);
        printf("\n");
        for(i = 0; i <= size; i++){ //for loop that moves up i each time, i used to go to each spot in database array for each light
            if(database[i].data[0] == id){ //if light stuct spot (i) has an id in the id spot of the data arry being == to the id you entered
                while(opt != 1 || 2 || 3 || 4 || 5 || 6){
                    printf("1- Change Name\n");
                    printf("2- Change Mode\n");
                    printf("3- Change Universe\n");
                    printf("4- Change starting DMX Address\n");
                    printf("5- Ending DMX Address\n");
                    printf("6- Edit Quantity\n\n");
                    printf("What do you want to do, please select a number: \n");
                    scanf("%d", &opt);
                    printf("\n");
                    if(opt != 1){ //asks new value for everything, puts new value into whatever spot you chose. Can't for chaning the name, string
                        if(opt == 2){ //prints out what the modes are
                            printf("Mode 1: W\nMode 2: RGB\nMode 3: RGBA\nMode 4: RGBW\nMode 5: RGBAW\nMode 6: Mover\n");
                        }
                        printf("What do you want the new value to be?\n");
                        scanf("%d", &newval);
                    }
                    if(opt == 1){
                        printf("What do you want the new name to be?\n");
                        scanf("%s", &database[i].name[0]);
                        printf("Name Changed\n");
                        rootMenu(size, database);
                    } else if(opt == 2){
                        database[i].data[1] = newval;
                        printf("Mode Changed\n");
                        rootMenu(size, database);
                    }else if(opt == 3){
                        database[i].data[2] = newval;
                        printf("Universe Changed\n");
                        rootMenu(size, database);
                    } else if(opt == 4){
                        database[i].data[4] = newval;
                        printf("Starting DMX Address Changed\n");
                        rootMenu(size, database);
                    } else if(opt == 5){
                        database[i].data[4] = newval;
                        printf("Ending DMX Address Changed\n");
                        rootMenu(size, database);
                    } else if(opt == 6){
                        database[i].data[5] = newval;
                        printf("Quantity Changed\n");
                        rootMenu(size, database);
                    } else {
                        printf("Thats not an option\nRealoading Menu\n\n");
                        sleep(1);
                    }
                }
            }
        }
    }

}

void print(int size, struct lData database[size]){
    int i, j, slen;
    for(i = 0; i < size; i++){
        if(database[i].data[0] != 0){
            slen = strlen(database[i].name);
            printf("ID: %d\n", database[i].data[0]);
            printf("Name: ");
            for(j = 0; j < slen; j++){
                printf("%c", database[i].name[j]);
            }
            printf("\n");
            printf("Mode: %d\n", database[i].data[1]);
            printf("Universe: %d\n", database[i].data[2]);
            printf("Dmx Starting Address: %d\n", database[i].data[3]);
            printf("Dmx Ending Address: %d\n", database[i].data[4]);
            printf("Quantity: %d\n\n", database[i].data[5]);
        }
    }
    printf("\n\n");
}

void export(int size, struct lData database[size]){
    int i, j, slen;
    FILE* outputForHuman;
    FILE* outputForProgram;
    outputForHuman = fopen("outputForHuman.txt", "w");
    outputForProgram = fopen("outputProgram.txt", "w");
    //Output For HUMAN Export to File
    for(i = 0; i < size; i++){
        if(database[i].data[0] != 0){
            slen = strlen(database[i].name);
            fprintf(outputForHuman, "ID: %d\n", database[i].data[0]);
            fprintf(outputForHuman, "Name: ");
            for(j = 0; j < slen; j++){
                fprintf(outputForHuman, "%c", database[i].name[j]);
            }
            fprintf(outputForHuman, "\n");
            fprintf(outputForHuman, "Mode: %d\n", database[i].data[1]);
            fprintf(outputForHuman, "Universe: %d\n", database[i].data[2]);
            fprintf(outputForHuman, "Dmx Starting Address: %d\n", database[i].data[3]);
            fprintf(outputForHuman, "Dmx Ending Address: %d\n", database[i].data[4]);
            fprintf(outputForHuman, "Quantity: %d\n\n", database[i].data[5]);
        }
    }
    //Output For PROGRAM Export to File
    fprintf(outputForProgram, "%d\n", size - 50);
    for(i = 0; i < size; i++){
        if(database[i].data[0] != 0){
            slen = strlen(database[i].name);
            fprintf(outputForProgram, "%d ", database[i].data[0]);
            for(j = 0; j < slen; j++){
                fprintf(outputForProgram, "%c", database[i].name[j]);
            }
            fprintf(outputForProgram, " %d %d %d %d %d\n", database[i].data[1], database[i].data[2], database[i].data[3], database[i].data[4], database[i].data[5]);
        }
    }
    fclose(outputForHuman);
    fclose(outputForProgram);
    printf("Success!\n\n");
}
