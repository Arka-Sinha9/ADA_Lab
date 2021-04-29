/*Sort a given set of N integer elements using Selection Sort technique and compute its time taken*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n, i, j, pos, temp;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int a[n];
    printf("The numbers are-\n");
    for (i = 0; i < n; i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }
    for(i = 0; i < n - 1; i++)
    {
        pos=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[pos] > a[j])
                pos=j;
        }
        if(pos != i)
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
        }
    }
    printf("Sorted Array-\n");
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}
