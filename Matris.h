#ifndef MATRIS_H_INCLUDED
#define MATRIS_H_INCLUDED



void printMatrix(int nrow, int ncol, float arr[nrow][ncol])
{
    for(int i=0; i<nrow; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            printf("  %.2f",arr[i][j]);

        }
        printf("\n");
    }
}



float Determinant(int nrow, int ncol, float arr[nrow][ncol])
{
    if(nrow != ncol)
    {
        printf("The matrix you create has to be square matrix !!\n");
    }
    else if(nrow == 1)
    {
        return arr[0][0];
    }
    else if(nrow == 2)
    {
        //  a11 a12
        //  a21 a22

        float a11 = arr[0][0];
        float a12 = arr[0][1];
        float a21 = arr[1][0];
        float a22 = arr[1][1];

        float m = a11 * a22;
        float n = a12 * a21;

        //printf("The determinant of the matrix is = %1.f",m-n);
        return (m-n);
    }
    else if(nrow == 3)
    {
        //   b11 b12 b13
        //   b21 b22 b23
        //   b31 b32 b33

        float b11 = arr[0][0];
        float b12 = arr[0][1];
        float b13 = arr[0][2];
        float b21 = arr[1][0];
        float b22 = arr[1][1];
        float b23 = arr[1][2];
        float b31 = arr[2][0];
        float b32 = arr[2][1];
        float b33 = arr[2][2];

        float k = b11 * b22 * b33;
        float l = b12 * b23 * b31;
        float m = b13 * b21 * b32;

        float x = b13 * b22 * b31;
        float y = b11 * b23 * b32;
        float z = b12 * b21 * b33;

        return (k+l+m-x-y-z);
    }
    else if(nrow == 4)
    {
        // c11 c12 c13 c14
        // c21 c22 c23 c24
        // c31 c32 c33 c34
        // c41 c42 c43 c44

        float c11 = arr[0][0];
        float c12 = arr[0][1];
        float c13 = arr[0][2];
        float c14 = arr[0][3];

        float c21 = arr[1][0];
        float c22 = arr[1][1];
        float c23 = arr[1][2];
        float c24 = arr[1][3];

        float c31 = arr[2][0];
        float c32 = arr[2][1];
        float c33 = arr[2][2];
        float c34 = arr[2][3];

        float c41 = arr[3][0];
        float c42 = arr[3][1];
        float c43 = arr[3][2];
        float c44 = arr[3][3];


        float k = (c11 * ((c22*c33*c44) + (c23*c34*c42) + (c24*c32*c43) - (c24*c33*c42) - (c22*c34*c43) - (c23*c32*c44)));
        float l = (c12 * ((c21*c33*c44) + (c23*c34*c41) + (c24*c31*c43) - (c24*c33*c41) - (c21*c34*c43) - (c23*c31*c44)));
        float m = (c13 * ((c21*c32*c44) + (c22*c34*c41) + (c24*c31*c42) - (c24*c32*c41) - (c21*c34*c42) - (c22*c31*c44)));
        float n = (c14 * ((c21*c32*c43) + (c22*c33*c41) + (c23*c31*c42) - (c23*c32*c41) - (c21*c33*c42) - (c22*c31*c43)));

        return (k-l+m-n);
    }
}




void SumOfMatrices(int nrow, int ncol, float arr[nrow][ncol])
{
    int row;
    int column;

    int flag=0;

    while(flag==0)
    {
        printf("\nDetermine number of rows of the next matrix you want to create    : ");
        scanf("%d",&row);
        printf("Determine number of columns of the next matrix you want to create : ");
        scanf("%d",&column);

        if(row>4 || column>4 || row<1 || column<1)
            printf("\nError!! You have been entered a wrong number\n");
        else
        {
            flag = 1;

            if(nrow != row || ncol != column)
            {
                printf("Error!! Rows and columns of matrices must be equivalent\n");
                flag = 0;
            }
        }
    }

    //Creating second matrix for addition process
    float matrix[row][column];

    printf("\nEnter values of the matrix you want to add :");
    printf("\n--------------------------------------------\n");

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d. row %d. column : ",i+1,j+1);
            scanf("%f",&matrix[i][j]);
        }
    }


    //printing sum of 2 matrices

    for(int i=0; i<nrow; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            printf("  %.2f",(arr[i][j] + matrix[i][j]));
        }
        printf("\n");
    }
}




//Multiplication operation of two matrices
void multiply2Matrices(int nrow, int ncol, float arr[nrow][ncol])
{
    int row;
    int column;

    int flag=0;

    while(flag==0)
    {
        printf("\nDetermine number of rows of the next matrix you want to create    : ");
        scanf("%d",&row);
        printf("Determine number of columns of the next matrix you want to create : ");
        scanf("%d",&column);

        if(row>4 || column>4 || row<1 || column<1)
            printf("\nError!! You have been entered a wrong number\n");
        else
        {
            flag = 1;

            if(ncol != row)
            {
                printf("Error!! Column of the first matrix and row of the second matrix must be equal\n");
                flag = 0;
            }
        }
    }

    //Creating second matrix for addition process
    float matrix[row][column];



    printf("\nEnter values of the matrix you want to multiply :");
    printf("\n-------------------------------------------------\n");

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d. row %d. column : ",i+1,j+1);
            scanf("%f",&matrix[i][j]);
        }
    }

    float multi[nrow][column];

    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < column; j++)
        {
            multi[i][j] = 0;
            for (int k = 0; k < row; k++)
            {
                multi[i][j] += arr[i][k] * matrix[k][j];
            }
        }
    }


    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("  %.2f\t", multi[i][j]);
        }
        printf("\n");
    }
}




void Inverse(int nrow, int ncol, float arr[nrow][ncol])
{

    if(nrow != ncol)
    {
        printf("The matrix you create has to be square matrix !!\n");
    }
    else if(Determinant(nrow,ncol,arr)==0)
    {
        printf("\nThis matrix has no inverse because its determinant is 0\n");
    }
    else if(nrow == 1)
    {
        printf("\nThe inverse of the matrix is = %.2f\n",arr[0][0]);
    }
    else if(nrow == 2)
    {
        float arr2[nrow][ncol];

        arr2[0][0] = (1/Determinant(nrow,ncol,arr)) * (arr[1][1]);
        arr2[0][1] = (1/Determinant(nrow,ncol,arr)) * (-1) * (arr[0][1]);

        arr2[1][0] = (1/Determinant(nrow,ncol,arr)) * (-1) * (arr[1][0]);
        arr2[1][1] = (1/Determinant(nrow,ncol,arr)) * (arr[0][0]);

        printMatrix(nrow,ncol,arr2);
    }
    else if(nrow == 3)
    {
        float N[nrow][ncol];


        N[0][0] = ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]));
        N[0][1] = (-1) * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]));
        N[0][2] = ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0]));

        N[1][0] = (-1) * ((arr[0][1] * arr[2][2]) - (arr[0][2] * arr[2][1]));
        N[1][1] = ((arr[0][0] * arr[2][2]) - (arr[0][2] * arr[2][0]));
        N[1][2] = (-1) * ((arr[0][0] * arr[2][1]) - (arr[0][1] * arr[2][0]));

        N[2][0] = ((arr[0][1] * arr[1][2]) - (arr[0][2] * arr[1][1]));
        N[2][1] = (-1) * ((arr[0][0] * arr[1][2]) - (arr[0][2] * arr[1][0]));
        N[2][2] = ((arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]));


        float arr3[nrow][ncol];

        arr3[0][0] = (1/Determinant(nrow,ncol,arr)) * (N[0][0]);
        arr3[0][1] = (1/Determinant(nrow,ncol,arr)) * (N[1][0]);
        arr3[0][2] = (1/Determinant(nrow,ncol,arr)) * (N[2][0]);

        arr3[1][0] = (1/Determinant(nrow,ncol,arr)) * (N[0][1]);
        arr3[1][1] = (1/Determinant(nrow,ncol,arr)) * (N[1][1]);
        arr3[1][2] = (1/Determinant(nrow,ncol,arr)) * (N[2][1]);

        arr3[2][0] = (1/Determinant(nrow,ncol,arr)) * (N[0][2]);
        arr3[2][1] = (1/Determinant(nrow,ncol,arr)) * (N[1][2]);
        arr3[2][2] = (1/Determinant(nrow,ncol,arr)) * (N[2][2]);

        printMatrix(nrow,ncol,arr3);
    }
    else if(nrow == 4)
    {

        float det = Determinant(nrow,ncol,arr);

        float arr4[nrow][ncol];

        float a11 = arr[0][0];
        float a12 = arr[0][1];
        float a13 = arr[0][2];
        float a14 = arr[0][3];

        float a21 = arr[1][0];
        float a22 = arr[1][1];
        float a23 = arr[1][2];
        float a24 = arr[1][3];

        float a31 = arr[2][0];
        float a32 = arr[2][1];
        float a33 = arr[2][2];
        float a34 = arr[2][3];

        float a41 = arr[3][0];
        float a42 = arr[3][1];
        float a43 = arr[3][2];
        float a44 = arr[3][3];



        arr4[0][0] = (1/det) * ((a22*a33*a44)+(a23*a34*a42)+(a24*a32*a43)-(a24*a33*a42)-(a23*a32*a44)-(a22*a34*a43));
        arr4[0][1] = (1/det) * (-(a12*a33*a44)-(a13*a34*a42)-(a14*a32*a43)+(a14*a33*a42)+(a13*a32*a44)+(a12*a34*a43));
        arr4[0][2] = (1/det) * ((a12*a23*a44)+(a13*a24*a42)+(a14*a22*a43)-(a14*a23*a42)-(a13*a22*a44)-(a12*a24*a43));
        arr4[0][3] = (1/det) * (-(a12*a23*a34)-(a13*a24*a32)-(a14*a22*a33)+(a14*a23*a32)+(a13*a22*a34)+(a12*a24*a33));

        arr4[1][0] = (1/det) * (-(a21*a33*a44)-(a23*a34*a41)-(a24*a31*a43)+(a24*a33*a41)+(a23*a31*a44)+(a21*a34*a43));
        arr4[1][1] = (1/det) * ((a11*a33*a44)+(a13*a34*a41)+(a14*a31*a43)-(a14*a33*a41)-(a13*a31*a44)-(a11*a34*a43));
        arr4[1][2] = (1/det) * (-(a11*a23*a44)-(a13*a24*a41)-(a14*a21*a43)+(a14*a23*a41)+(a13*a21*a44)+(a11*a24*a43));
        arr4[1][3] = (1/det) * ((a11*a23*a34)+(a13*a24*a31)+(a14*a21*a33)-(a14*a23*a31)-(a13*a21*a34)-(a11*a24*a33));

        arr4[2][0] = (1/det) * ((a21*a32*a44)+(a22*a34*a41)+(a24*a31*a42)-(a24*a32*a41)-(a22*a31*a44)-(a21*a34*a42));
        arr4[2][1] = (1/det) * (-(a11*a32*a44)-(a12*a34*a41)-(a14*a31*a42)+(a14*a32*a41)+(a12*a31*a44)+(a11*a34*a42));
        arr4[2][2] = (1/det) * ((a11*a22*a44)+(a12*a24*a41)+(a14*a21*a42)-(a14*a22*a41)-(a12*a21*a44)-(a11*a24*a42));
        arr4[2][3] = (1/det) * (-(a11*a22*a34)-(a12*a24*a31)-(a14*a21*a32)+(a14*a22*a31)+(a12*a21*a34)+(a11*a24*a32));

        arr4[3][0] = (1/det) * (-(a21*a32*a43)-(a22*a33*a41)-(a23*a31*a42)+(a23*a32*a41)+(a22*a31*a43)+(a21*a33*a42));
        arr4[3][1] = (1/det) * ((a11*a32*a43)+(a12*a33*a41)+(a13*a31*a42)-(a13*a32*a41)-(a12*a31*a43)-(a11*a33*a42));
        arr4[3][2] = (1/det) * (-(a11*a22*a43)-(a12*a23*a41)-(a13*a21*a42)+(a13*a22*a41)+(a12*a21*a43)+(a11*a23*a42));
        arr4[3][3] = (1/det) * ((a11*a22*a33)+(a12*a23*a31)+(a13*a21*a32)-(a13*a22*a31)-(a12*a21*a33)-(a11*a23*a32));


        printMatrix(nrow,ncol,arr4);
    }







}





#endif // MATRIS_H_INCLUDED
