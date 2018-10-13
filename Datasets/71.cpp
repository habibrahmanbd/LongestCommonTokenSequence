using namespace std;
#include<bits/stdc++.h>

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II,m=II;
        int arr[n+1][n+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=INF;
            }
        }
        for(int i=1; i<=m; i++)
        {
            int u=II, v=II;
            arr[u][v]=1;
            arr[v][u]=1;
        }
        int source=II, des=II;

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        int res=0;
        for(int i=0; i<n; i++)
            res=max(res, arr[source][i]+arr[i][des]);
        pf("Case %d: %d\n",cs, res);

    }
    return 0;
}
