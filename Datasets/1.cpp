using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II, w=II, k=II;
        int y[n+3],temp;
        for(int i=0; i<n; i++)
            temp=II,y[i]=II;
        sort(y,y+n);
        y[n++]=INT_MAX;
        int dp[105][105];
        memset(dp, 0, sizeof dp);
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(i!=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                int high=i;
                while(y[high]<=y[i]+w)
                    high++;
                dp[high][j+1]=max(dp[high][j+1],dp[i][j]+high-i);
            }
        }
        int res=0;
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                res=max(res, dp[i][j]);
//                cout<<res<<endl;
            }
        }
        pf("Case %d: %d\n",cs,res);
    }
    return 0;
}
