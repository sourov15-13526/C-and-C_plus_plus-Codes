#include<bits/stdc++.h>
using namespace std;
int main()
{
    // N = number of node and M = number of Edge
    int N,M;
    N=12;
    int arr[][2]= {{1,2},{1,3},{1,4},{2,5},{2,6},{4,7},{4,8},{5,9},{5,10},{7,11},{7,12}};
    M=11;//Number of edges
    // for adjacency matrix
    int Adj[N+1][N+1];

    // initialize all adjacency list to Zero
    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<N+1; j++)
        {
            Adj[i][j]=0;
        }

    }
    // traverse the array of edges
    for( int i=0; i<M; i++)
    {
        // Find x and y of edges
        int x =arr[i][0];
        int y =arr[i][1];

        // update the value to 1
        Adj[x][y]=1;
        Adj[y][x]=1;

    }
    //Travers and print the adj[][]
    for(int i=1; i<N+1; i++)
    {
        for(int j=1; j<N+1; j++)
        {
            printf("%d ",Adj[i][j]);
        }
        printf("\n");
    }

    int level[N+1];
    bool vis[N+1];
    queue<int>q;
    int s = 1;
    for(int i = 0; i<N+1; i++)
        level[i] = 0;
    for(int i = 0; i<N+1; i++)
        vis[i]=false;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    int res[N+1];
    int k=0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        res[k] = p;
        k++;
        for(int i = 0; i<N+1; i++)
        {
            if(Adj[p][i] == 1 && vis[i]==false)
            {
                if(level[i]==0)
                    level[i] = level[p]+1;
                q.push(i);
                vis[i] = true;
            }
             else if(Adj[p][i] == 1)
             {
                 for(int a=0; a<N+1; a++)
                 {
                     if (res[a] == i)
                     {
                          printf("cycle exits: ");
                     }

                 }

             }

        }
    }
    printf("\n\n");
    for(int i = 0; i<N+1;i++)printf("%d %d\n",i,level[i]);
    printf("\nResult : \n");
    for(int i = 0; i<N;i++)printf("%d\n",res[i]);

    return 0;

}

