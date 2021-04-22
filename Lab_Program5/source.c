/*Sort a given set of N integer elements using Insertion Sort technique and compute its time taken.*/\



#include <math.h>
#include <stdio.h>


void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


void printArray(int a[], int n)
{
    int i;
    printf("The numbers in sorted form are-\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    printf("\n");
}


int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("The numbers are-\n");
    for (int i = 0; i < n; i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }
    int k = sizeof(a) / sizeof(a[0]);

    insertionSort(a, k);
    printArray(a, k);

    return 0;
}
