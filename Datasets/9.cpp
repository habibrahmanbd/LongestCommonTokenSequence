using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll arr[2*n][n+1];
        ll dp[2*n][n+1];
        memset(dp,0,sizeof dp);
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<=i; j++)
            {
                arr[i][j]=ILL;
//                cout<<"here";
            }
        }
        for(ll i=n; i<=2*n-2; i++)
        {
            for(ll j=0; j<(2*n)-(i+1); j++)
            {
//                cout<<"I: "<<i<<" J: "<<j<<endl;
                arr[i][j]=ILL;
//                cout<<"here2";
            }
        }
        dp[0][0]=arr[0][0];
//        cout<<dp[0][0];
        for(ll i=1; i<n; i++)
        {
            for(ll j=0; j<=i; j++)
            {
                if(j==0)
                    dp[i][j]+=dp[i-1][j]+arr[i][j];
                else if(j==i)
                {
                    dp[i][j]+=dp[i-1][j-1]+arr[i][j];
                }
                else
                {
                    dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
                }
//                cout<<"I: "<<i<<" J: "<<j<<" Res : "<<dp[i][j]<<endl;
            }
        }
        for(ll i=n; i<=2*n-2; i++)
        {
            for(ll j=0; j<(2*n)-(i+1); j++)
            {
                dp[i][j]+=arr[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
//                cout<<dp[i][j]<<endl;
            }
        }
        pf("Case %lld: %lld\n",cs,dp[2*n-2][0]);
    }
    return 0;
}
