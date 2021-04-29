#include<stdio.h>
#include<stdlib.h>

void hanoi(int n,char x,char y,char z)
{
    if(n>0)
    {
        hanoi(n-1,x,z,y);
        printf("\nMove disk number %d from %c to %c",n,x,y);
        hanoi(n-1,z,y,x);
    }
}


int gcd(int n1,int n2)
{
    if (n2 != 0)
        return gcd(n2,n1%n2);
    else
        return n1;
}

int main()
{
    int ch,n,n1,n2;
    printf("Choose from the following-\n");
    do{
        printf("\n|----------**-----------|");
        printf("\n1.Tower of Hanoi\n2.GCD\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter number of disks: ");
            scanf("%d",&n);
            hanoi(n,'A','B','C');
            break;
        case 2:
            printf("Enter the first positive integer: ");
            scanf("%d",&n1);
            printf("Enter the second positive integer: ");
            scanf("%d",&n2);
            printf("G.C.D of %d and %d is %d.\n",n1,n2,gcd(n1, n2));
            break;
        case 3:
            break;
        default:
            printf("Enter valid choice!!\n");
            break;
        }
    }while(ch!=3);

    return 0;
}



