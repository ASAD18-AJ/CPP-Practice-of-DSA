#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    x = *y;
    y = temp;
}

void selectionsort(int a[], int n)
{
    int i, j, minp;
    for (i = 0; i < n - 1; i++)
        minp = i;
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                minp = j;
            }
        }
        if (minp != i)
        {
            swap(&a[i], &a[j]);
        }
    }
}
void printa(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        printf('\n');
    }
}
int main()
{
}