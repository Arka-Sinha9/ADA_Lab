/*a. Print all the nodes reachable from a given starting node in a digraph using BFS method. b. Check whether a given graph is connected or not using DFS method.*/

#include<stdio.h>
#include<stdlib.h>

int a[20][20],q[20],visited[20],reach[20],n,i,j,f=0,r=-1,count=0;

void bfs(int v)
{
    int k;
    for(k=1;k<=n;k++)
        if(a[v][k] && !visited[k])
            q[++r]=k;
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}

void dfs(int v)
{
    int k;
    reach[v]=1;
    for(k=1;k<=n;k++)
        if(a[v][k] && !reach[k])
        {
            printf("\n %d->%d",v,k);
            dfs(k);
        }
}

int main()
{
    int v,ch;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        reach[i]=0;
        for(j=1;j<=n;j++)
            a[i][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("Enter the adjacency matrix of the graph:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("The graph is-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    do{
        printf("\n\n|-----MENU-----|\n");
        printf("1.Print all nodes reachable\n2.Check if graph is connected\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the starting vertex: ");
                scanf("%d",&v);
                bfs(v);
                printf("The node which are reachable are:\n");
                for(i=1;i<=n;i++)
                    if(visited[i])
                        printf("%d\t",i);
                break;
            case 2:
                dfs(1);
                printf("\n");
                for(int k=1;k<=n;k++)
                {
                    if(reach[k])
                        count++;
                }
                if(count==n)
                    printf("Graph is connected\n");
                else
                    printf("Graph is not connected\n");
                break;
            case 3:
                break;
            default:
                printf("Enter valid choice!!\n");
        }

    }while(ch!=3);
    return 0;
}

