#include<stdio.h>

typedef struct poly{
    int coeff;
    int data;
}poly;

int main()
{
    poly a[50] = {0};
    int d1, d2, s1 = 0, s2, e1 = 0, e2, avail, u,v, i, w;
    printf("Enter the degree of the two polynomials  ");
    scanf("%d %d", &d1, &d2);
    printf("Input the coefficients of the first polynomial\n");
    for(i = d1;i >= 0; i--)
    {
        printf("coeff of x^%d = ", i);
        scanf("%d", &a[e1].data);
        a[e1].coeff = i;
        e1++;
    }
    s2 = e1;
    e2 = s2;
    w = d2;
    printf("\nInput the coefficients of the second polynomial\n");
    for(i = d1 + d2 + 1;i >= d1 + 1; i--)
    {
        printf("coeff of x^%d = ", w);
        scanf("%d", &a[e2].data);
        a[e2].coeff = w;
        w--;
        e2++;
    }
    avail = e2;
    int end = avail;
    u = s1;
    v = s2;
    if(d1 > d2)
    {
        w = d2;
        int t = s1;
        for(i = d1;i > d2; i--)
        {
            a[end].data = a[t].data;
            a[end].coeff = a[t].coeff;
            t++;
            end++;
            u++;
        }
    }
    else if(d2 > d1)
    {
        int t = s2;
        w = d1;
        for(i = d2;i > d1; i--)
        {
            a[end].data = a[t].data;
            a[end].coeff = a[t].coeff;
            t++;
            end++;
            v++;
        }
    }
    else
        w = d1;

    for(i = 0;i < w + 1; i++)
    {
        a[end].data = a[u].data + a[v].data;
        a[end].coeff = a[u].coeff;
        u++;
        v++;
        end++;
    }


    printf("\nFirst polynomial : ");

    for( i = s1; i < e1; i++ )
    {
        printf("%dx^%d",a[i].data, a[i].coeff);
        d1--;
        if( i != e1 - 1)
          printf("  +  ");
    }
    printf("\nSecond polynomial : ");

    for( i = s2; i < e2; i++ )
    {
        printf("%dx^%d",a[i].data, a[i].coeff);
        d2--;
        if( i != e2 - 1)
          printf("  +  ");
    }
    
    printf("\nResultant sum : ");
    u = end - avail;
    for( i = avail; i < end; i++ )
    {
        u--;
        printf("%dx^%d",a[i].data, a[i].coeff);
        if( i != end - 1)
          printf("  +  ");
    }
    printf("\n");
}



