#include <stdio.h>

int calc(){
/*
printf("\n\n\n");
printf("DDDDDDDDDDDDD       MMMMMMMM               MMMMMMMXXXXXXX       XXXXXXX     DDDDDDDDDDDDD     IIIIIIIIIPPPPPPPPPPPPPPPPP                CCCCCCCCCCCCC                lllllll\n");
printf("D::::::::::::DDD    M:::::::M             M:::::::X:::::X       X:::::X     D::::::::::::DDD  I::::::::P::::::::::::::::P            CCC::::::::::::C                l:::::l\n");
printf("D:::::::::::::::DD  M::::::::M           M::::::::X:::::X       X:::::X     D:::::::::::::::DDI::::::::P::::::PPPPPP:::::P         CC:::::::::::::::C                l:::::l\n");
printf("DDD:::::DDDDD:::::D M:::::::::M         M:::::::::X::::::X     X::::::X     DDD:::::DDDDD:::::II::::::IPP:::::P     P:::::P       C:::::CCCCCCCC::::C                l:::::l\n");
printf(" D:::::D    D:::::DM::::::::::M       M::::::::::XXX:::::X   X:::::XXX       D:::::D    D:::::DI::::I   P::::P     P:::::P      C:::::C       CCCCCC aaaaaaaaaaaaa   l::::l    cccccccccccccccc\n");
printf(" D:::::D     D:::::M:::::::::::M     M:::::::::::M  X:::::X X:::::X          D:::::D     D:::::I::::I   P::::P     P:::::P     C:::::C               a::::::::::::a  l::::l  cc:::::::::::::::c\n");
printf(" D:::::D     D:::::M:::::::M::::M   M::::M:::::::M   X:::::X:::::X           D:::::D     D:::::I::::I   P::::PPPPPP:::::P      C:::::C               aaaaaaaaa:::::a l::::l c:::::::::::::::::c\n");
printf(" D:::::D     D:::::M::::::M M::::M M::::M M::::::M    X:::::::::X            D:::::D     D:::::I::::I   P:::::::::::::PP       C:::::C                        a::::a l::::lc:::::::cccccc:::::c\n");
printf(" D:::::D     D:::::M::::::M  M::::M::::M  M::::::M    X:::::::::X            D:::::D     D:::::I::::I   P::::PPPPPPPPP         C:::::C                 aaaaaaa:::::a l::::lc::::::c     ccccccc\n");
printf(" D:::::D     D:::::M::::::M   M:::::::M   M::::::M   X:::::X:::::X           D:::::D     D:::::I::::I   P::::P                 C:::::C               aa::::::::::::a l::::lc:::::c\n");
printf(" D:::::D     D:::::M::::::M    M:::::M    M::::::M  X:::::X X:::::X          D:::::D     D:::::I::::I   P::::P                 C:::::C              a::::aaaa::::::a l::::lc:::::c\n");
printf(" D:::::D    D:::::DM::::::M     MMMMM     M::::::XXX:::::X   X:::::XXX       D:::::D    D:::::DI::::I   P::::P                  C:::::C       CCCCCa::::a    a:::::a l::::lc::::::c     ccccccc\n");
printf("DDD:::::DDDDD:::::D M::::::M               M::::::X::::::X     X::::::X     DDD:::::DDDDD:::::II::::::IPP::::::PP                 C:::::CCCCCCCC::::a::::a    a:::::al::::::c:::::::cccccc:::::c\n");
printf("D:::::::::::::::DD  M::::::M               M::::::X:::::X       X:::::X     D:::::::::::::::DDI::::::::P::::::::P                  CC:::::::::::::::a:::::aaaa::::::al::::::lc:::::::::::::::::c\n");
printf("D::::::::::::DDD    M::::::M               M::::::X:::::X       X:::::X     D::::::::::::DDD  I::::::::P::::::::P                    CCC::::::::::::Ca::::::::::aa:::l::::::l cc:::::::::::::::c\n");
printf("DDDDDDDDDDDDD       MMMMMMMM               MMMMMMMXXXXXXX       XXXXXXX     DDDDDDDDDDDDD     IIIIIIIIIPPPPPPPPPP                       CCCCCCCCCCCCC aaaaaaaaaa  aaallllllll   cccccccccccccccc\n");
printf("\n\n\n");

*/

        int address; //tells you you the DMX adress is
        int index;  //used in lu.edu    oop to print array
        int j;  // used in loop to print array

// the 8 switches that start off that the user enters 1 or 0 into
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        int s4 = 0;
        int s5 = 0;
        int s6 = 0;
        int s7 = 0;
        int s8 = 0;

//the number in binary, s1 goes with n1 the n is the value that switch has in binary. if off (0) adds nothing, if on (1) then adds the n binary value to the dmx adress
        int n1 = 1;
        int n2 = 2;
        int n3 = 4;
        int n4 = 8;
        int n5 = 16;
        int n6 = 32;
        int n7 = 64;
        int n8 = 128;

        char drawswitches[5][17] =
                {
                        {'|',' ','|',' ','|',' ','|',' ', '|',' ','|',' ', '|',' ','|',' ', '|',},
                        {'|',' ','|',' ','|',' ','|',' ', '|',' ','|',' ', '|',' ','|',' ', '|',},
                        {'|',' ','|',' ','|',' ','|',' ', '|',' ','|',' ', '|',' ','|',' ', '|',},
                        {'|',' ','|',' ','|',' ','|',' ', '|',' ','|',' ', '|',' ','|',' ', '|',},
                        {'|',' ','|',' ','|',' ','|',' ', '|',' ','|',' ', '|',' ','|',' ', '|',},
                };

//print the switch number to toggel and scan in answer, store in the s varibale
        printf("Enter 0 or 1 for switch #1\n");
        scanf("%d", &s1);

        printf("Enter 0 or 1 for switch #2\n");
        scanf("%d", &s2);

        printf("Enter 0 or 1 for switch #3\n");
        scanf("%d", &s3);

        printf("Enter 0 or 1 for switch #4\n");
        scanf("%d", &s4);

        printf("Enter 0 or 1 for switch #5\n");
        scanf("%d", &s5);

        printf("Enter 0 or 1 for switch #6\n");
        scanf("%d", &s6);

        printf("Enter 0 or 1 for switch #7\n");
        scanf("%d", &s7);

        printf("Enter 0 or 1 for switch #8\n");
        scanf("%d", &s8);
        printf("\n\n");

//if else statment for each switch. If you user enterd 0 (off) it sets n to 0 so it will not add value to the DMX address. Then draws the #'s in vertical spots 2,3,4 in array in the collum of that switch
//Else-if it is else, then it keep the n value of the binary by doing nothing, else just print the #'s in spots 0,1,2 in the switch collum in the array.
        if (s1 == 0) {
                n1 = 0;
                drawswitches[0][1] = ' ';
                drawswitches[1][1] = ' ';
                drawswitches[2][1] = '#';
                drawswitches[3][1] = '#';
                drawswitches[4][1] = '#';
        } else {
                drawswitches[0][1] = '#';
                drawswitches[1][1] = '#';
                drawswitches[2][1] = '#';
                drawswitches[3][1] = ' ';
                drawswitches[4][1] = ' ';
        }
        if (s2 == 0) {
                n2 = 0;
                drawswitches[0][3] = ' ';
                drawswitches[1][3] = ' ';
                drawswitches[2][3] = '#';
                drawswitches[3][3] = '#';
                drawswitches[4][3] = '#';
        } else {
                drawswitches[0][3] = '#';
                drawswitches[1][3] = '#';
                drawswitches[2][3] = '#';
                drawswitches[3][3] = ' ';
                drawswitches[4][3] = ' ';
        }
        if (s3 == 0) {
                n3 = 0;
                drawswitches[0][5] = ' ';
                drawswitches[1][5] = ' ';
                drawswitches[2][5] = '#';
                drawswitches[3][5] = '#';
                drawswitches[4][5] = '#';
        } else {
                drawswitches[0][5] = '#';
                drawswitches[1][5] = '#';
                drawswitches[2][5] = '#';
                drawswitches[3][5] = ' ';
                drawswitches[4][5] = ' ';
        }
        if (s4 == 0) {
                n4 = 0;
                drawswitches[0][7] = ' ';
                drawswitches[1][7] = ' ';
                drawswitches[2][7] = '#';
                drawswitches[3][7] = '#';
                drawswitches[4][7] = '#';
        } else {
                drawswitches[0][7] = '#';
                drawswitches[1][7] = '#';
                drawswitches[2][7] = '#';
                drawswitches[3][7] = ' ';
                drawswitches[4][7] = ' ';
        }
        if (s5 == 0) {
                n5 = 0;
                drawswitches[0][9] = ' ';
                drawswitches[1][9] = ' ';
                drawswitches[2][9] = '#';
                drawswitches[3][9] = '#';
                drawswitches[4][9] = '#';
        } else {
                drawswitches[0][9] = '#';
                drawswitches[1][9] = '#';
                drawswitches[2][9] = '#';
                drawswitches[3][9] = ' ';
                drawswitches[4][9] = ' ';
        }
        if (s6 == 0) {
                n6 = 0;
                drawswitches[0][11] = ' ';
                drawswitches[1][11] = ' ';
                drawswitches[2][11] = '#';
                drawswitches[3][11] = '#';
                drawswitches[4][11] = '#';
        } else {
                drawswitches[0][11] = '#';
                drawswitches[1][11] = '#';
                drawswitches[2][11] = '#';
                drawswitches[3][11] = ' ';
                drawswitches[4][11] = ' ';
        }
        if (s7 == 0) {
                n7 = 0;
                drawswitches[0][13] = ' ';
                drawswitches[1][13] = ' ';
                drawswitches[2][13] = '#';
                drawswitches[3][13] = '#';
                drawswitches[4][13] = '#';
        } else {
                drawswitches[0][13] = '#';
                drawswitches[1][13] = '#';
                drawswitches[2][13] = '#';
                drawswitches[3][13] = ' ';
                drawswitches[4][13] = ' ';
        }
        if (s8 == 0) {
                n8 = 0;
                drawswitches[0][15] = ' ';
                drawswitches[1][15] = ' ';
                drawswitches[2][15] = '#';
                drawswitches[3][15] = '#';
                drawswitches[4][15] = '#';
        } else {
                drawswitches[0][15] = '#';
                drawswitches[1][15] = '#';
                drawswitches[2][15] = '#';
                drawswitches[3][15] = ' ';
                drawswitches[4][15] = ' ';
        }

//adds all the DMX binary values together, if all on, then 255, if any off, then the corresponding value is 0
        address = n1 + n2 + n3 + n4 +n5 + n6 + n7 + n8;

//print the DMX Address to screen
        printf("DMX Address = %d\n\n\n", address);

//loop that goes across array, then down a collum and prints out next row.
        for (j = 0; j<5; j++){  //vertical movment
                for (index = 0; index<17; index++){     //horizontal movment
                        printf("%c", drawswitches[j][index]);  //printing

                }
                        printf("\n");  //add a new line after each go in array
        }

        return 0;
}
