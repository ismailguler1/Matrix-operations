#include <stdio.h>
#include <stdlib.h>
#include "Matris.h"



int main()
{

    int choice;

    int row;
    int column;

    int flag=0;

    while(flag==0)
    {
        printf("\nDetermine number of rows of the matrix you want to create    : ");
        scanf("%d",&row);
        printf("Determine number of columns of the matrix you want to create : ");
        scanf("%d",&column);

        if(row>4 || column>4 || row<1 || column<1)
            printf("\nError!! You have been entered a wrong number\n");
        else
            flag = 1;
    }




    float matrix[row][column];

    printf("\nEnter values for matrix : \n");
    printf("------------------------------\n");

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
        printf("%d. row %d. column : ",i+1,j+1);
        scanf("%f",&matrix[i][j]);
        }
    }




    do
    {
        printf("\n====================================");
        printf("\n 1-) Print the matrix\n");
        printf(" 2-) Find the determinant of the matrix\n");
        printf(" 3-) Sum of 2 matrices\n");
        printf(" 4-) Multiplication of 2 matrices\n");
        printf(" 5-) Find inverse of the matrix\n");
        printf(" 6-) Exit\n");
        printf("====================================\n");

        printf("\nPlease enter the number of the process you desire :");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printMatrix(row,column,matrix);
        }
        else if(choice == 2)
        {
            float det = Determinant(row,column,matrix);
            printf("The determinant of the matrix is = %.2f\n",det);
        }
        else if(choice == 3)
        {
            SumOfMatrices(row,column,matrix);
        }
        else if(choice == 4)
        {
            multiply2Matrices(row,column,matrix);
        }
        else if(choice == 5)
        {
            Inverse(row,column,matrix);
        }
    }
    while(choice != 6);


    return 0;
}
