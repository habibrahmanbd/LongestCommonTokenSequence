using namespace std;
#include<bits/stdc++.h>

int dp[11][11];
int arr[11];
int M,N;
int dprec(int m, int n) //m=current position and n=number of digits in the set
{
    if(m==1)
        return 1;
    if(dp[m][n]==-1)
    {
        int total=0;
        for(int i=1; i<=N; i++)
        {
            if(abs(arr[i]-arr[n])<=2)
            {
                total+=dprec(m-1,i);
            }
        }
        dp[m][n]=total;
    }
    return dp[m][n];
}
int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        N=II,M=II;
        memset(dp, -1, sizeof dp);
        for(int j=1; j<=N; j++)
        {
            arr[j]=II;
        }
        ll res=0;
        for(int j=1; j<=N; j++)
        {
            res+=dprec(M,j);
        }
        pf("Case %d: %lld\n",cs,res);
    }
    return 0;
}
