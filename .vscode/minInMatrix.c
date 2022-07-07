#include<stdio.h>

void main()
{
    int a[3][4], minRow[3], minCol[4];
    printf("Enter elements in the 3*4 matrix: \n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("a[%d][%d]:  ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe matrix you entered is: \n\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<3; i++)
    {   
        minRow[i] = a[i][0];
        for(int j=0; j<4; j++)
        {
            if(a[i][j] < minRow[i]);
                minRow[i] = a[i][j]; 
        }
    }

    for(int i=0; i<3; i++)
    {
    printf("Minimum element in row%d is %d\n",i+1, minRow[i]);
    }

    for(int j=0; j<4; j++)
    {
    printf("Minimum element in row%d is %d\n",j+1, minCol[j]);
    }
}