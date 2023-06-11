#include<stdio.h>

void swap(int a[], int i, int j)
{
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

int partition(int a[] , int lb, int ub)
{
    int pi = a[lb];
    int i = lb - 1, j;
    for(j = lb; j <= ub; j++)
    {
        if( a[j] <= pi)
        {
            i++;
            swap(a, i , j);
        }
    }
    swap(a, i , lb);
    return i;
}

void sort (int a[], int lb, int ub)
{
    while( lb < ub)
    {
    int pi = partition(a , lb, ub);
    sort(a , lb, pi - 1);
    sort(a , pi + 1, ub);
    }
}

void main()
{
    int a[50] = {0}, n, i;
    printf("Enter the number of elements in the list : ");
    scanf("%d",&n);
    printf("Enter the elements of the list : ");
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a, 0, n - 1);
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
}