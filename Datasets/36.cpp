using namespace std;

#include <bits/stdc++.h>

int n,k;
int coins[51];
int number_of_coins[51];
int dp[51][1001];
int coin_change(int i,int amount)
{
    if(i>=n)
    {
        if(amount==k)
            return 1;
        else
            return 0;
    }
    if(amount>k)
        return 0;
    if(amount==k)
        return 1;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int     ret=0;
    for(int j=1; j<=number_of_coins[i]; j++)
    {
        if(amount + coins[i]*j<=k)
            ret += coin_change(i+1, amount+coins[i]*j)%MOD;
        else
            break;
    }
    ret += coin_change(i+1,amount)%MOD;
    return dp[i][amount] = ret%MOD;
}
int main()
{
    input;
    int  t=II;
    int cs=1;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        n=II,k=II;
        f(0,n-1,1)
        coins[i]=II;
        f(0,n-1,1)
        number_of_coins[i]=II;
        pf("Case %d: %d\n",cs++,coin_change(0,0)%MOD);
    }
    return 0;
}
