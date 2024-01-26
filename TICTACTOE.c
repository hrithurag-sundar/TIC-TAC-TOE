#include <stdio.h>
#include <stdlib.h>// include for usleep and random
#include <unistd.h>// include for sleep functio for mac os
//#include <Windows.h>// include for sleep for windows


// defining functions
void display();// function to display grid
void ds();
void check();  // function to check win of x/o
void win_(int w);   // print the winnig statement of player 
int msleep(unsigned int tms); // convert the microseconds to milliseconds
int plce_chk(int m, char l, int n, int inp);// function to check whether there's any element placed in the grid in posistion the the next player is placing
void formatChar(char c, int m);
int flag;
int count;
int xoro;
int pvc;
char name1[10], name2[10];
int countc;
int countm;
int k;
int b[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7}; // array for color
char w = ' ';
char tic[3][3] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'}; // intializing the 2d array
int main()
{
    system("clear");
    ds();
    int restart = 1;
    int v;
    while (restart == 1)
    {
        // to check user what player vs player or vs computer
        printf("Enter '0' for 1V1 '1' for pVSc:\n"); // getting input for play type whether pv or 1v1
        do
        {
            scanf("%d", &pvc);
            if (pvc > 1)
            {
                printf("Enter valid input: ");
            }
        } while (pvc > 1); // EXIT THE LOOP WHEN USER ENTERS A VALUE < 2

        // getting user preference to play as X or to play as O ( for pvc)
        if (pvc == 1)
        {
            printf("Enter name of player-1 (X):\n");
            scanf("%s", name1);
            printf("Enter '0' to play as 'X' , '1' to play as 'O'\n");

            if (pvc == 1)
            {
                do
                {
                    scanf("%d", &xoro);
                    if (pvc > 1)
                    {
                        printf("Enter valid input: ");
                    }
                }

                while (xoro > 1);
            }
        }

        else
        {
            printf("Enter name of player-1 (X):\n");
            scanf("%s", name1);
            printf("Enter name of player-2 (O):\n");
            scanf("%s", name2);
        }

        system("clear");
        display();
        int input;
        count = 0;
        flag = -1;

        while (count < 9 && flag == -1)
        {
            k = 0;

            while (k == 0) // the condition to prevent placing the a x/o at the same place
            {
                countc = 0;
                if (countm == 0)
                {
                    if (count % 2 == 0)
                    {
                        printf(" \t\t\t\t\t\t\t\t     Enter your input(0-8) player-1 (X):\n\t\t\t\t\t\t\t\t\t\t  ---> ");
                    }
                    else
                    {
                        printf(" \t\t\t\t\t\t\t\t     Enter your input(0-8) player-2 (O):\n\t\t\t\t\t\t\t\t\t\t  ---> ");
                    }
                }
                else
                {
                    countm = 0;
                }
                int input;
                if (pvc == 1)
                {
                    if (xoro == 0)
                    {

                        if (count % 2 != 0)
                        {
                            input = (rand() % (8-0+1)+0);// randomly place a x/o in the grid
                            countc = 1;// a variable to prvent printing of excess starements
                        }
                        else
                        {
                            scanf("%d", &input);
                        }
                    }
                    else

                    {
                        if (count % 2 != 0)
                        {
                            scanf("%d", &input);
                        }
                        else
                        {
                            input = (rand() % (8-0+1)+0);
                            countc = 1;
                        }
                    }
                }
                else
                {
                    scanf("%d", &input);
                }

                if (input >= 0 && input <= 8)
                {
                    k = -1;
                    if (count % 2 == 0)
                    {
                        if ((input >= 0 && input < 3))
                        {
                            plce_chk(0, 'X', 0, input);
                        }

                        else if (input >= 3 && input < 6)
                        {
                            plce_chk(1, 'X', 3, input);
                        }

                        else
                        {
                            plce_chk(2, 'X', 6, input);
                        }
                    }
                    else
                    {
                        if (input >= 0 && input < 3)
                        {
                            plce_chk(0, 'O', 0, input);
                        }

                        else if (input >= 3 && input < 6)
                        {
                            plce_chk(1, 'O', 3, input);
                        }

                        else
                        {
                            plce_chk(2, 'O', 6, input);
                        }
                    }
                }
                else
                {
                    system("clear");
                    printf("\t\t\t\t\t Invalid input try again..\n");
                    display();
                }
            }
            system("clear");
            display();
            check();
        }
        printf("   \t\t\t\t\t\t         Press '1' to play again, or press other any numbers to exit \n \t\t\t\t\t\t\t\t\t    --->  ");
        scanf("%d", &v);
        restart = v;
        // reintialising the tic tac toe
        tic[0][0] = '0';
        tic[0][1] = '1';
        tic[0][2] = '2';
        tic[1][0] = '3';
        tic[1][1] = '4';
        tic[1][2] = '5';
        tic[2][0] = '6';
        tic[2][1] = '7';
        tic[2][2] = '8';
        b[0] = 7;
        b[1] = 7;
        b[2] = 7;
        b[3] = 7;
        b[4] = 7;
        b[5] = 7;
        b[6] = 7;
        b[7] = 7;
        b[8] = 7;
    }

    return 0;
}

void formatChar(char c, int m)
{
    if (c == 'X')
    {
        if (b[m] != 2)
        {
            b[m] = 6;
            printf("\033[1;3%dm X \033[0m", b[m]);
        }

        else
        {
            printf("\033[1;3%dm X \033[0m", b[m]);
        }
    }
    else if (c == 'O')
    {
        if (b[m] != 2)
        {
            b[m] = 5;
            printf("\033[1;3%dm O \033[0m", b[m]); // method of printing coloured text here prints as a normal colour
        }

        else
        {
            printf("\033[1;3%dm O \033[0m", b[m]); // prints the green font
        }
    }
    else 
    {
        printf(" %c ", c);
    }
}

void display()
{
    printf ("\n\n\n\n");
    printf("\t\t\t\t\t\t\033[1;31m********************************************************************************\033[0m\n");
    printf ("\t\t\t\t\t\t\033[1;31m*\t\t\t\t\t\t\t\t\t       *\033[0m\n");
    printf("\t\t\t\t\t\t\033[1;31m*\033[0m\t\t\t\t --- --- ---\t\t\t\t       \033[1;31m*\033[0m\n");
    for (int i = 0; i < 3; ++i)
    {
        printf("\t\t\t\t\t\t\033[1;31m*\033[0m\t\t\t\t|");
        for (int j = 0; j < 3; ++j)
        {
            formatChar(tic[i][j], (3 * i) + j);
            if (j==2)
            {
                printf("|\t\t\t\t       \033[1;31m*\033[0m");
            }
            else
            {
                printf("|");
            }
            
        }
        printf("\n\t\t\t\t\t\t\033[1;31m*\033[0m\t\t\t\t --- --- ---\t\t\t\t       \033[1;31m*\033[0m\n");
    }
    printf ("\t\t\t\t\t\t\033[1;31m*\033[0m\t\t\t\t\t\t\t\t\t       \033[1;31m*\033[0m\n");
    printf("\t\t\t\t\t\t\033[1;31m********************************************************************************\033[0m\n");
    printf("\n");
}

void check() 
{
    if (tic[0][0] == tic[0][1] && tic[0][1] == tic[0][2])
    { // row checks

        
        b[0] = 2;
        b[1] = 2;
        b[2] = 2;
        w = tic[0][0];
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }

        flag = 1;
    }
    else if (tic[1][0] == tic[1][1] && tic[1][1] == tic[1][2])
    {
        b[3] = 2;
        b[4] = 2;
        b[5] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[1][0];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else if (tic[2][0] == tic[2][1] && tic[2][1] == tic[2][2])
    {
        b[6] = 2;
        b[7] = 2;
        b[8] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(200); // wait for a second
            display();
            w = tic[2][0];
            win_(w);  // print this statement on screen.
            msleep(200); // wait for a second
        }
        flag = 1;
    }
    else if (tic[0][0] == tic[1][0] && tic[1][0] == tic[2][0])
    { // column check
        b[0] = 2;
        b[3] = 2;
        b[6] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[0][0];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else if (tic[0][1] == tic[1][1] && tic[1][1] == tic[2][1])
    {
        b[1] = 2;
        b[4] = 2;
        b[7] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[0][1];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else if (tic[0][2] == tic[1][2] && tic[1][2] == tic[2][2])
    {
        b[2] = 2;
        b[5] = 2;
        b[8] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[0][2];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else if (tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2])
    { // diagonal check
        b[0] = 2;
        b[4] = 2;
        b[8] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[0][0];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else if (tic[0][2] == tic[1][1] && tic[1][1] == tic[2][0])
    {
        b[2] = 2;
        b[4] = 2;
        b[6] = 2;
        for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            display();
            w = tic[0][2];
            win_(w);  // print this statement on screen.
            msleep(400); // wait for a second
        }
        flag = 1;
    }
    else
    { // Draw condition
        if (count == 9)
        {
            printf("Game ends in a draw!\n");
        }
    }
}

void win_(int w)
{
    if (pvc == 1)// print winning winning for comp vs player
    {
        if (xoro == 1 && w == 'O') 
        {
            printf("   \t\t\t**********************%s, YOU WON THE GAME !!! ********************\n", name1);
        }

        else if (xoro == 1 && w == 'X')

        {
            printf("   \t\t\t\t\t\t     ********************** COMPUTER WON THE GAME , YOU lose !!! ********************\n");
        }

        else if (xoro == 0 && w == 'O')

        {
            printf("   \t\t\t\t\t\t     ********************** COMPUTER WON THE GAME , YOU lose !!! ********************\n");
        }

        else
        {
            printf("   \t\t\t\t\t\t     **********************%s, YOU WON THE GAME !!! ********************\n", name1);
        }
    }
    else // print winning winning for player vs player
    {
        if (w == 'X')
        {
            printf("  \t\t\t\t\t\t      **********************%s, YOU WiN THE GAME !!! ********************\n", name1);
        }

        else
        {
            printf("   \t\t\t\t\t\t     **********************%s, YOU WiN THE GAME !!! ********************\n", name2);
        }
    }
}

int plce_chk(int m, char l, int n, int inp) // prevnts player from mistankingly place x/o in an already placed posistion
{
    if ((tic[m][inp - n] == 'X') || (tic[m][inp - n] == 'O'))
    {
        if (countc == 1)
        {
            countm++;
            k = 0;
        }
        else
        {
            printf("   \t\t\t\t\t\t\t        Please dont give posistion that is occupied !!!!! \n\t\t\t\t\t\t\t\t\t\t  ---> ");
            countm++;
            k = 0;
        }
    }
    else
    {
        tic[m][inp - n] = l;
        count++;
        k = -1;
    }
}
int msleep(unsigned int tms)
{
  return usleep(tms * 1000);
}
void  ds()
{
    for (int i = 1; i <= 5; i++) // 15 time statement will blink
        {
            system("clear"); // clear the screen
            msleep(400); // wait for a second
            printf("\t\t\t\t\t\t ----------------------------------------------------- \n");
            printf("\t\t\t\t\t\t|\t\033[1;33m WELCOME TO THE GAME OF TIC--TAC--TOE \033[0m \t      |\n");  // print this statement on screen.
            printf("\t\t\t\t\t\t ----------------------------------------------------- \n");
            msleep(400);
        }
}