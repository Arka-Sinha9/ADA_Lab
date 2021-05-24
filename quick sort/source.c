#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void quicksort(int a[],int first,int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}

int main()
{
    int i,count;
    printf("Enter number of elements in the array: ");
    scanf("%d",&count);
    int a[count];
    printf("The numbers are-\n\n");
    for(i=0;i<count;i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }
    clock_t begin = clock();
    quicksort(a,0,count-1);
    printf("Printing the sorted array:\n");
    for(i=0;i<count;i++)
    {
        printf("%d\n",a[i]);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution Time : %f seconds\n", time_spent);
    return 0;
}
