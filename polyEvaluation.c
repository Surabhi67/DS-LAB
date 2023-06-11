#include <stdio.h>

typedef struct matrix{
    int row;
    int col;
    int value;
} matrix; 

void sparserep(struct matrix a[])
{
    int m[25][25] = {0},i ,j, r, c, k = 0;
    scanf("%d %d",&r ,&c );
    printf("Enter the elements of the matrix \n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d",&m[i][j]);
            if(m[i][j] != 0)
            {
                k++;
                a[k].row = i;
                a[k].col = j;
                a[k].value = m[i][j];
            }
        }
    }
    a[0].row = r;
    a[0].col = c;
    a[0].value = k;
    float l = k;
    printf("The sparse matrix representaion is\n");
    for(i = 0; i <= k; i++)
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value );
}

int sum(struct matrix a[], struct matrix b[])
{
    matrix c[10] = {0};
    int i, p, j = 1, k = 1, l = 1;
    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Matrices have to be of same size");
        return 0;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    while(a[j].value != 0 && b[k].value != 0)
    {
        if(a[j].row == b[k].row)
        {
            if (a[j].col == b[k].col)
            {
                c[l].row = a[j].row;
                c[l].col = a[j].col;
                c[l].value = a[j].value + b[k].value;
                k++;
                j++;
         

            l++;
            }
            else if(a[j].col < b[k].col)
            {
                c[l].row = a[j].row;
                c[l].col = a[j].col;
                c[l].value = a[j].value;
                l++;
                j++;
            }
            else 
            {
                c[l].row = b[k].row;
                c[l].col = b[k].col;
                c[l].value = b[k].value;
                l++;
                k++;
            }
        }
        else if(a[j].row < b[k].row)
        {
            c[l].row = a[j].row;
            c[l].col = a[j].col;
            c[l].value = a[j].value;
            l++;
            j++;
        }
        else
        {
            c[l].row = b[k].row;
            c[l].col = b[k].col;
            c[l].value = b[k].value;
            l++;
            k++;
        }
    }
    while(a[j].value != 0 )
    {
        c[l].row = a[j].row;
        c[l].col = a[j].col;
        c[l].value = a[j].value;
        l++;
        j++;
    }
    while(b[k].value != 0 )
    {
        c[l].row = b[k].row;
        c[l].col = b[k].col;
        c[l].value = b[k].value;
        l++;
        k++;
    }
    c[0].value = l - 2;
    printf("The sum matrix is \n");
    for( i = 0; i < l; i++)
        printf("%d %d %d\n",c[i].row, c[i].col, c[i].value);
}

void main()
{
    matrix a[10] = {0}, b[10] = {0};
    printf("Enter the number of rows and columns in the first matrix ");
    sparserep(a);
    printf("Enter the number of rows and columns in the second matrix ");
    sparserep(b);
    sum(a, b);
}
