//Jacob Davie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //random numbers for ID nums 
#include <unistd.h> //sleep functuion
#include "dip3.h"

struct lData{ //lData (light data) stuct holds all vars for EACH light
    int id;
    char name[50];
    int mode;
    int dmxA;
    int qty;
};
typedef struct lData lData; 

struct node{ //Node struct used for Linked Lists, the data part of it (normally singe int) is now the lData struct
    struct lData lData;
	struct node *next;
	struct node *prev;
};
typedef struct node node;


//function prototypes
void editDatabaseMenu2(node* head, node* tail, int argc, char* argv[]);
void addLight(node* head, node* tail, int argc, char* argv[]);
void changeName(node* head, node* tail, int argc, char* argv[]);
void changeMode(node* head, node* tail, int argc, char* argv[]);
void changeDmxA(node* head, node* tail, int argc, char* argv[]);
void changeQty(node* head, node* tail, int argc, char* argv[]);
void printDatabaseMenu2(node* head, node* tail, int argc, char* argv[]);
void writeFile(node* head, node* tail, int argc, char* argv[]);

int main(int argc, char* argv[]){
    int opt, database[100][4], lines, i, tmpLData[4], slen;
    char tmpLName[50];
    node* head = NULL;
	node* tail = NULL;
    node* end;
    node* tmp = head;
    FILE* inDatabase;

    if(argc == 1){
        printf("No database file supplied\nUse the format ./a.out FILE\n\n");
        sleep(2);
        exit(0);
    } if(argc == 2){
        printf("Database file found!\n\n");
    }

    inDatabase = fopen(argv[1], "r"); //opens file

    fscanf(inDatabase, "%d", &lines);

//scans in all info from input file and puts it in tmp array
    for(i = 0; i < lines - 1; i++){
        fscanf(inDatabase, "%d", &tmpLData[0]);
        fscanf(inDatabase, "%s", &tmpLName[0]);
        fscanf(inDatabase, "%d", &tmpLData[1]);
        fscanf(inDatabase, "%d", &tmpLData[2]);
        fscanf(inDatabase, "%d", &tmpLData[3]);
        slen = strlen(tmpLName);
        tmp = malloc(sizeof(node));
        if(head == NULL){
            tmp -> lData.id = tmpLData[0];
            for(i = 0; i < slen; i++){
                tmp -> lData.name[i] = tmpLData[i];
            }
            tmp -> lData.mode = tmpLData[1];
            tmp -> lData.dmxA = tmpLData[2];
            tmp -> lData.qty = tmpLData[3];
            tmp -> next = head;
            tmp -> prev = NULL;
            head = tmp;
        } else{
            while(tmp -> next != NULL){
                tmp = tmp -> next;
            }
            end = tmp;
                    tmp -> lData.id = tmpLData[0];
            for(i = 0; i < slen; i++){
                tmp -> lData.name[i] = tmpLData[i];
            }
            tmp -> lData.mode = tmpLData[1];
            tmp -> lData.dmxA = tmpLData[2];
            tmp -> lData.qty = tmpLData[3];
            tmp -> next = NULL;
            tmp -> prev = end;
            end -> next = tmp;
        }
    }
//root menu
    printf("1- Edit Database\n");
    printf("2- Print Database\n");
    printf("3- Write database to file\n");
    printf("4- Run Dip Switch Calculator for Troubleshooting\n");
    printf("5- Quit\n\n");
    printf("What do you want to do, please select a number: \n");
    scanf("%d", &opt);
    printf("\n");

    if(opt == 1){
        editDatabaseMenu2(head, tail, argc, argv);
    } else if(opt == 2){
        printDatabaseMenu2(head, tail, argc, argv);
    } else if(opt == 3){
       writeFile(head, tail, argc, argv);
    } else if(opt == 4){
        calc(); //runs calc function (whole program) from header file
    } else if(opt == 5){
        fclose(inDatabase);
        exit(0);
    } else{
    printf("Thats not an option\nReloading to main menu\n\n");
    sleep(2);
    main(argc, argv);
    }

}// end of main

void editDatabaseMenu2(node* head,node* tail, int argc, char* argv[]){
        int opt;

        printf("1- Add Light\n");
        printf("2- Change Name of Existing Light\n");
        printf("3- Change Mode of Existing Light\n");
        printf("4- Change DMX Address of Existing Light\n");
        printf("5- Edit Quantity of Exising Light\n");
        printf("6- Return to Main Menu\n");
        printf("7- Quit\n\n");

        printf("What do you want to do, please select a number: \n");
        scanf("%d", &opt);
        printf("\n");

        if(opt == 1){
            addLight(head, tail, argc, argv);
        } else if(opt == 2){
            changeName(head, tail, argc, argv);
        } else if(opt == 3){
            changeMode(head, tail, argc, argv);
        } else if(opt == 4){
            changeDmxA(head, tail, argc, argv);
        } else if(opt == 5){
            changeQty(head, tail, argc, argv);
        } else if(opt == 6){
            main(argc, argv);
        } else if(opt == 7){
            exit(0);
        } else{
            printf("Thats not an option\nReturning to main menu\n\n");
            sleep(2);
            main(argc, argv);
        }
}

void addLight(node* head, node* tail, int argc, char* argv[]){
    
    char tmpName[50];
    int tmpData[4], slen, i, tmpId, up = 10000;

    tmpData[0] = rand() % up; //makes random ID number for each light
    printf("What is the name of the light?\n");
    scanf("%s", &tmpName[0]); //gets just would not work
    slen = strlen(tmpName);
    printf("What is the mode?\nMode 1: W\nMode 2: RGB\nMode 3: RGBA\nMode 4: RGBW\nMode 5: RGBAW\nMode 6: Mover\n");
    scanf("%d", &tmpData[1]);
    printf("What is the DMX Address\n");
    scanf("%d", &tmpData[2]);
    printf("How many do you have?\n");
    scanf("%d", &tmpData[3]);

    node* tmp; //making tmp pointer from the node struct
	node* end; //making end pointer from the node struct


//Fill Linked List with Data (collected from above)
	if(head == NULL){ //empty
		tmp = malloc(sizeof(node));
        tmp -> lData.id = tmpData[0];
        for(i = 0; i <= slen; i++){ //for loop copies name string
            tmp -> lData.name[i] = tmpName[i];
        }
		tmp -> lData.mode = tmpData[1];
        tmp -> lData.dmxA = tmpData[2];
        tmp -> lData.qty = tmpData[3];
		tmp -> next = head;
		tmp -> prev = NULL;
		head = tmp;
	} else{
  		while(tmp -> next != NULL){
 		tmp = tmp -> next;
    	}
		end = tmp;
		tmp = malloc(sizeof(node));
        tmp -> lData.id = tmpData[0];
        for(i = 0; i <= slen; i++){//for loop copies name string
            tmp -> lData.name[i] = tmpName[i];
        }
		tmp -> lData.mode = tmpData[1];
        tmp -> lData.dmxA = tmpData[2];
        tmp -> lData.qty = tmpData[3];
    	tmp -> next = NULL;
		tmp -> prev = end;
		end -> next = tmp;
		tmp = head;
   	}
main(argc, argv);
}

void changeName(node* head, node* tail, int argc, char* argv[]){
    char opt, TrashcanofDOOOOOOOOOOOOOM, newName[50];
    int id, i, slen;
    node* tmp;
    tmp = malloc(sizeof(node));
    if(tmp -> next != NULL){
        printf("The database is empty\nGoing to where you can add a light\n");
        sleep(2);
        addLight(head, tail, argc, argv);
    }
    printf("Would you first like to print out the Database to see the ID numbers?\nEnter (y)es or press any other letter to continue.\n");
    scanf("%c", &TrashcanofDOOOOOOOOOOOOOM);
    scanf("%c", &opt);

    if(opt == 'y'){
        printDatabaseMenu2(head, tail, argc, argv);
    }
        printf("Enter the ID number of the light you want to change the name of\n");
        scanf("%d", &id);
        printf("What do you want the new name to be?\n");
        scanf("%s", &newName[0]);
        slen = strlen(newName);
        while(tmp -> lData.id != id){
            tmp = tmp -> next;
        }
        for(i = 0; i <= slen; i++){
            tmp -> lData.name[i] = newName[i];
        }

}

void changeMode(node* head, node* tail, int argc, char* argv[]){
    char opt, TrashcanofDOOOOOOOOOOOOOM;
    int id, newMode;
    node* tmp;
    tmp = malloc(sizeof(node));
    if(tmp -> next != NULL){
        printf("The database is empty\nGoing to where you can add a light\n");
        sleep(2);
        addLight(head, tail, argc, argv);
    }
    printf("Would you first like to print out the Database to see the ID numbers?\nEnter (y)es or press any other letter to continue.\n");
    scanf("%c", &TrashcanofDOOOOOOOOOOOOOM);
    scanf("%c", &opt);

    if(opt == 'y'){
        printDatabaseMenu2(head, tail, argc, argv);
    }
        printf("Enter the ID number of the light you want to change the mode of\n");
        scanf("%d", &id);
        printf("What do you want the new mode to be?\n");
        scanf("%d", &newMode);
        while(tmp -> lData.id != id){
            tmp = tmp -> next;
        }
        tmp -> lData.mode = newMode;
}

void changeDmxA(node* head, node* tail, int argc, char* argv[]){
    char opt, TrashcanofDOOOOOOOOOOOOOM;
    int id, newDmxA;
    node* tmp;
    tmp = malloc(sizeof(node));
    if(tmp -> next != NULL){
        printf("The database is empty\nGoing to where you can add a light\n");
        sleep(2);
        addLight(head, tail, argc, argv);
    }
    printf("Would you first like to print out the Database to see the ID numbers?\nEnter (y)es or press any other letter to continue.\n");
    scanf("%c", &TrashcanofDOOOOOOOOOOOOOM);
    scanf("%c", &opt);

    if(opt == 'y'){
        printDatabaseMenu2(head, tail, argc, argv);
    }
        printf("Enter the ID number of the light you want to change the DMX Address of\n");
        scanf("%d", &id);
        printf("What do you want the new DMX Address to be?\n");
        scanf("%d", &newDmxA);
        while(tmp -> lData.id != id){
            tmp = tmp -> next;
        }
        tmp -> lData.dmxA = newDmxA;
}

void changeQty(node* head, node* tail, int argc, char* argv[]){
    char opt, TrashcanofDOOOOOOOOOOOOOM;
    int id, newQty;
    node* tmp;
    tmp = malloc(sizeof(node));
    if(tmp -> next != NULL){
        printf("The database is empty\nGoing to where you can add a light\n");
        sleep(2);
        addLight(head, tail, argc, argv);
    }
    printf("Would you first like to print out the Database to see the ID numbers?\nEnter (y)es or press any other letter to continue.\n");
    scanf("%c", &TrashcanofDOOOOOOOOOOOOOM);
    scanf("%c", &opt);

    if(opt == 'y'){
        printDatabaseMenu2(head, tail, argc, argv);
    }
        printf("Enter the ID number of the light you want to change the quantity of\n");
        scanf("%d", &id);
        printf("What do you want the new quantity to be?\n");
        scanf("%d", &newQty);
        while(tmp -> lData.id != id){
            tmp = tmp -> next;
        }
        tmp -> lData.qty = newQty;
}

void printDatabaseMenu2(node* head, node* tail, int argc, char* argv[]){
    int i, slen;
    node* tmp = head;
    tmp = malloc(sizeof(node));
//	while(tmp != NULL){
        printf("ID- %d\n", tmp -> lData.id);
       // slen = strlen(tmp -> lData.name); 
       // for(i = 0; i < slen; i++){
           printf("Name- %d\n", tmp -> lData.name[1]); //[i] 
       // }
        printf("Mode- %d\n", tmp -> lData.mode);
        printf("DMX Address- %d\n", tmp -> lData.dmxA);
        printf("Quantity- %d\n", tmp -> lData.qty);
        tmp = tmp -> next;
  //  }
	printf("\n*****\n\n");

}

void sort(node* head, node* tail, int argc, char* argv[]){ //bubble sort

}

void writeFile(node* head, node* tail, int argc, char* argv[]){
    int lines = 0;
    node* tmp = head;
    FILE* output;
    
    while(tmp -> next != NULL){
        tmp = tmp -> next;
        lines++;
    }
    output = fopen("output.txt", "w");
    tmp = malloc(sizeof(node));

    while(tmp -> next != NULL){
        fprintf(output,"%d\n", lines);
        fprintf(output,"%d %s %d %d %d\n", tmp -> lData.id, tmp -> lData.name[0], tmp -> lData.mode, tmp -> lData.dmxA, tmp -> lData.qty);
        tmp = tmp -> next;
    }
    fclose(output);
    exit(0);
}
