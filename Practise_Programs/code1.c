#include<stdio.h>
#include<stdlib.h>
#define n 100;
int a[n];

int main()
{
    printf("The numbers are: \n");
    for(int i=0;i<n;i++)
    {
        a[i]=rand()
        printf("%d",a[i]);
    }
    int ch;
    printf("|-----------------**-----------------|");
    do{
        printf("1.Linear Search\n2.Binary Search\n3.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                linear();
                break;
            case 2:
                binary();
                break;
            case 3:
                break;
            default:
                printf("Enter valid choice!!");
                break;
        }
    }while(ch!=3);
    return 0;
}

void linear()
{
    int k,flag=0;
    printf("Enter the number to search: ");
    scanf("%d",&k);
    for(int j=0;j<n;j++)
    {
        if(k==a[j])
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("The number %d is found in position %d!!\n",k,j+1);
    }
    else
    {
        printf("The number %d is not found",k)
    }
}

void binary()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    int mid=50;
    if
}
