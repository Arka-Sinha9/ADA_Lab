#include<stdio.h>


int LEFT_TO_RIGHT = 1;
int RIGHT_TO_LEFT = 0;


int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
           return i + 1;
}


int getMobile(int a[], int dir[], int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {

        if (dir[a[i]-1] == 0 && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        // direction 1 represents LEFT TO RIGHT.
        if (dir[a[i]-1] == 1 && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}

void swap(int a[], int pos_1, int pos_2)
{
    int temp = a[pos_1];
    a[pos_1] = a[pos_2];
    a[pos_2] = temp;
}



int printOnePerm(int a[], int dir[], int n)
{
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);



    if (dir[a[pos - 1] - 1] ==  0)
       swap(a, pos-1, pos-2);

    else if (dir[a[pos - 1] - 1] == 1)
       swap(a, pos, pos-1);


    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == 1)
                dir[a[i] - 1] = 0;
            else if (dir[a[i] - 1] == 0)
                dir[a[i] - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\t");
}


int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}

void printPermutation(int n)
{

    int a[n];


    int dir[n];


    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
    }
    printf("\n");


    for (int i = 0; i < n; i++)
        dir[i] =  0;


    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}


int main()
{
    int n;
    printf("Enter number of numbers: ");
    scanf("%d",&n);
    printPermutation(n);
    return 0;
}
