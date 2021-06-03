//Sort a given set of N integer elements using Heap Sort technique and compute its time taken.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
    {
    int temp = *a;
    *a = *b;
    *b = temp;
    }

void heap(int arr[], int n, int i)
{

    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left]>arr[largest])
        largest=left;

    if (right<n && arr[right]>arr[largest])
        largest=right;


    if (largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heap(arr,n,largest);
    }
}


void heapSort(int arr[], int n)
{

    for(int i=n/2-1;i>=0;i--)
        heap(arr, n, i);


    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);


        heap(arr,i,0);
    }
}


void printArray(int arr[], int n)
{
    for (int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}


int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    printf("The randomly generated array is-\n");
    printArray(arr,n);

    clock_t begin=clock();
    heapSort(arr, n);

    clock_t end=clock();

    printf("\n\nSorted array is-\n");
    printArray(arr, n);


    double time=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nSorting time: %f seconds!!",time);
}
