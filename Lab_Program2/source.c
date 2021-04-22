/*Implement Recursive Binary search and Linear search and determine the time required to search
an element. Repeat the experiment for different values of N and plot a graph of the time taken
versus N.*/

#include<stdio.h>
#include<stdlib.h>

int binarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (a[mid] == x)
            return mid;

        if (a[mid] > x)
            return binarySearch(a, l, mid-1, x);

        return binarySearch(a, mid+1, r, x);
    }

    return -1;
}



int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return recSearch(arr, l+1, r-1, x);
}



int main(void)
{
    int n;
    int x;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("The numbers are-\n");
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }
    int j,k;
    printf("Enter number to search: ");
    scanf("%d",&x);
    int t = sizeof(a)/ sizeof(a[0]);
    int index = recSearch(a, 0, t-1, x);
    printf("|--Linear Search--|\n");
    if (index != -1)
       printf("Element %d is present at index %d\n", x, index);
    else
        printf("Not Found\n");
    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(a[j]>a[k])
            {
                int temp=a[j];
                a[j]=a[k];
                a[k]=temp;
            }
        }
    }
    printf("|--Binary Search--|\n");
    printf("Elements in sorted order is-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    int o = sizeof(a)/sizeof(a[0]);
    int result = binarySearch(a, 0, o-1, x);
    (result == -1)? printf("Not Found!!\n"): printf("Element is present at position %d", result+1);
    return 0;
}
