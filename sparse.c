#include <stdio.h>

typedef struct matrix{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    matrix a[10] = {0}, b[10] = {0}, c[10] = {0};
    int i ,j, k, w, x;
    printf("Enter the number of non zero values in first matrix ");
    scanf("%d",&k);
    printf("Enter the sparse representation of the first matrix \n");
    for(i = 0; i < k; i++)
        scanf("%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);
    printf("Enter the number of non zero values in second matrix ");
    scanf("%d",&w);
    printf("Enter the sparse representation of the second matrix \n");
    for(i = 0; i < w; i++)
        scanf("%d %d %d\n", &b[i].row, &b[i].col, &b[i].value );

    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Both the matrices should have same number of rows and columns\n");
        return 0;
    }

    for(i = 1; i < a[0].value; i++)
    {
        for(j = 1; j < b[0].value; j++)
        {
            if(a[i].row == b[j].row && a[j].col == b[j].col)
            {
                c[i].row = a[i].row;
                c[i].col = a[i].col;
                c[i].value = a[i].value + b[i].value;
            }
            else
            {
                c[i].row = a[i].row;
                c[i].col = a[i].col;
                c[i].value = a[i].value;
            }
        }
    }

    x = i;
    for(i = x; i < b[0].value; i++)
    {
        for(j = 1; j < a[0].value; j++)
        {
            if(a[i].row != b[j].row || a[j].col != b[j].col)
            {
                c[i].row = b[i].row;
                c[i].col = b[i].col;
                c[i].value = b[i].value;
            }
        }
    }

    c[0].row = b[0].row;
    c[0].col = b[0].col;
    c[0].value = i;

    printf("The sparse matrix representaion of their sum is\n");
    for(i = 0; i <= k; i++)
    {
        printf("%d %d %d\n", c[i].row, c[i].col, c[i].value );
    }

}
