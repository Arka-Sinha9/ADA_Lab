#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void median(int arr[],int size)
{
    float n=(arr[size/2]+arr[(size-1)/2])/2.0;
    printf("\nThe median of the array is: %f",n);
}

void sort(int arr[],int size)
{
    int temp,i,j;
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int n,i,j;
    printf("Enter size of both arrays: ");
    scanf("%d",&n);
    int a[n],b[n],c[2*n];
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    for(i=0;i<n;i++)
    {
        b[i]=rand();
    }
    printf("\nElements of first array-\n");
    printArray(a,n);

    printf("\nElements of second array-\n");
    printArray(b,n);

    sort(a,n);
    sort(b,n);

    printf("\nSorted first array-\n");
    printArray(a,n);

    printf("\nSorted second array-\n");
    printArray(b,n);

    clock_t begin = clock();

    for(j=0;j<n;j++)
    {
        c[j]=a[j];
    }
    for(int k=0;k<n;k++)
    {
        c[j+k]=b[k];
    }
    printf("\nMerged array is-\n");
    printArray(c,2*n);

    median(c,2*n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution Time : %f seconds\n", time_spent);


    return 0;
}
