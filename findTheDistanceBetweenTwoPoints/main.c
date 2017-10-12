#include <stdio.h>
#include <math.h>

int positionX[32] = {0};
int positionY[32] = {0};
float length[32][32] = {0};
int smallestLengthX, smallestLengthY;

int calcLengthOfPosition(int positionX1, int positionY1, int positionX2, int positionY2)
{
    int length = 0;
    length = hypot(positionX1 - positionX2, positionY1 - positionY2);
    return length;
}

int souatari(int howmany)
{
    int i, j;
    for (i = 0; i < howmany; i++)
    {
        for (j = 0; j < howmany - 1; j++)
        {
            length[i][j] = hypot(positionX[i] - positionX[j], positionY[i] - positionY[j]);
        }
    }
    return 0;
}

float isBiggest(int howmany)
{
    int i, j;
    float temp = length[0][0];

    for (i = 0; i < howmany; i++)
    {
        for (j = 0; j < howmany; j++)
        {
            if (temp < length[i][j])
            {
                temp = length[i][j];
            }
            if (temp > length[i][j])
            {
            }
        }
    }
    return temp;
}

float isSmallest(int howmany)
{
    int i, j;
    float temp = length[0][1];

    for (i = 0; i < howmany; i++)
    {
        for (j = 0; j < howmany; j++)
        {
            if (length[i][j] > 0 && temp > length[i][j] && i != j)
            {
                temp = length[i][j];
                smallestLengthX = i;
                smallestLengthY = j;
            }
        }
    }
    return temp;
}

int main(void)
{
    int i, howmany = 0, error = 1;
    printf("how many position? : ");
    scanf("%d", &howmany);
    while (error != 0)
    { //
        if (howmany < 2)
        {
            printf("input 2 or more number :");
            scanf("%d", &howmany);
            error = 1;
        }
        if (howmany > sizeof(positionX) / sizeof(positionX[0]))
        {
            printf("input %lu or less :", sizeof(positionX) / sizeof(positionX[0]));
            scanf("%d", &howmany);
            error = 1;
        }
        if (howmany > 1 && howmany < sizeof(positionX) / sizeof(positionX[0]))
        {
            error = 0;
        }
    }

    for (i = 0; i < howmany; i++)
    {
        printf("input position x[%d] : ", i);
        scanf("%d", &positionX[i]);
        printf("input position y[%d] : ", i);
        scanf("%d", &positionY[i]);
    }
    souatari(howmany);
    printf("biggest is %.3f\n", isBiggest(howmany));
    printf("smallest is %.3f\n", isSmallest(howmany));
    printf("smallest array is [%d][%d]\n", smallestLengthX, smallestLengthY);
}