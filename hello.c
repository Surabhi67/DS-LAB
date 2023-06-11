#include <stdio.h>

typedef struct matrix{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    matrix a[10] = {0}, b[10] = {0}, c[10] = {0};
    int i, p, j = 1, k = 1, l = 1;
    printf("Enter the number of non zero values in the first matrix  ");
    scanf("%d",&a[0].value);
    printf("Enter the elements of the first matrix\n");
    for( i = 0; i <= a[0].value; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    printf("Enter the number of non zero elements in the second matrix  ");
    scanf("%d",&b[0].value);
    printf("Enter the eleents of the second matrix\n");
    for(i = 0; i <= b[0].value; i++)
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].value);
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
