#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
void CreateMatrix(int[][4]);
void ShowMatrix(int[][4]);
void swap(int *, int *);
void GameRules(int[][4]);
int CheckWinner(int[][4]);
int Shiftup(int[][4]);
int Shiftdown(int[][4]);
int Shiftright(int[][4]);
int Shiftleft(int[][4]);
int Arrowkey();
int main()
{
    int a[4][4];
    char name[20];
    printf("Enter Your Name : ");
    fgets(name, 20, stdin);

    while (1)
    {
        int move = 300;
        CreateMatrix(a);
        GameRules(a);
        while (!CheckWinner(a))
        {
            system("cls");
            if (move == 0)
                break;
            printf("Your Name is  :%s\n", name);
            printf("Game Move Remaining :%d", move);
            ShowMatrix(a);
            int key = Arrowkey();

            if (key == 62 || key == 101)
            {
                printf("\nThanks for Playing : \n");
                printf("If You Want to Exit the Game then : Press ESC :\n");
                key = Arrowkey();
                exit(0);
            }
            else if (key == 72)
            {
                if (Shiftup(a))
                    move--;
            }
            else if (key == 80)
            {
                if (Shiftdown(a))
                    move--;
            }
            else if (key == 77)
            {
                if (Shiftright(a))
                    move--;
            }
            else if (key == 75)
            {
                if (Shiftleft(a))
                    move--;
            }
            else
                printf("Not Allowed :\n");
        }
        if (!move)
            printf("||||||||YOU LOSE THE GAME||||||||");
        else
        {
            printf("\n||| Congratulation You Won ||| \n");
            printf("|||||YOU WON THE GAME|||||||||\n");
        }
        char ch;
        printf("\nIf YOU Want To Play Again Then Press 'Y' BUTTON ");
        scanf("%c", &ch);
        if (ch != 'y' && ch != 'Y')
            break;
    }
    return 0;
}
int Shiftleft(int a[][4])
{
    int i, j, flag = false;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (j == 3)
        return 0;
    else
    {
        swap(&a[i][j], &a[i][j + 1]);
        return 1;
    }
}
int Shiftright(int a[][4])
{
    int i, j, flag = false;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (j == 0)
        return 0;
    else
    {
        swap(&a[i][j], &a[i][j - 1]);
        return 1;
    }
}
int Shiftdown(int a[][4])
{
    int i, j, flag = false;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (i == 0)
        return 0;
    else
    {
        swap(&a[i][j], &a[i - 1][j]);
        return 1;
    }
}
int Shiftup(int a[][4])
{
    int i, j, flag = false;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (i == 3)
        return 0;
    else
    {
        swap(&a[i][j], &a[i + 1][j]);
        return 1;
    }
}
void GameRules(int a[][4])
{
    system("cls");
    int x;
    int i, j;
    printf("                 RULE OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by arrow key ");
    printf("\nMove Up   : by Up arrow key ");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Left : by Left arrow key");
    printf("\nMove Right: by Right arrow key");

    printf("\n2.You can move number at empty position only\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 \n");
    printf("4.Wining situation : number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            winning situation:\n");

    printf("----------------------\n");
    printf("\n---------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
                printf("%2d  |", 4 * i + j + 1);
            else
                printf("    | ");
        }
        printf("\n---------------------\n");
    }
    printf("\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");

    printf("\nSo Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");

    printf("\nEnter any key to start.....");
    x = Arrowkey();
}
int Arrowkey()
{
    char ch;
    ch = getch();
    return ch;
}
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int CheckWinner(int a[][4])
{
    int i, j, k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (k < 15)
                k++;
            else
                k = 0;
            if (a[i][j] != k)
                return 0;
        }
        printf("\n");
    }
    return 1;
}
void ShowMatrix(int a[][4])
{
    int i, j;
    printf("\n---------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
                printf("%2d  |", a[i][j]);
            else
                printf("    | ");
        }
        printf("\n---------------------\n");
    }
}
void CreateMatrix(int a[][4])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int MaxIndex = 14, index, i, j;
    srand(time(NULL));

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (MaxIndex >= 0)
            {
                index = rand() % (MaxIndex + 1);
                a[i][j] = arr[index];
                arr[index] = arr[MaxIndex];
                MaxIndex--;
            }
            else
                a[i][j] = 0;
        }
    }
}
