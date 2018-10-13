using namespace std;

#include <bits/stdc++.h>

#define MOD 10056
int fact[1010];
int nSr[1010][1010];
int stirling(long n, long r)
{
    if(n==r||r==1)
        return 1;
    if(n<r)
        return 0;
    if(nSr[n][r]!=-1)
        return nSr[n][r];
    else
        return nSr[n][r]=(stirling(n-1,r-1)%MOD+(r%MOD*stirling(n-1,r)%MOD)%MOD)%MOD;
}
int main()
{
//    input;
    int t=II;
    memset(fact,-1,sizeof fact);
    memset(nSr,-1,sizeof nSr);
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=1000; i++)
        fact[i]=(fact[i-1]%MOD * i%MOD )% MOD;
    int cs=1;
    while(t--)
    {
        int res=0;
        int n=II;
        for(int i=1; i<=n; i++)
            res = (res % MOD + (stirling(n,i)%MOD*fact[i]%MOD)%MOD)%MOD;
        OC(cs++);
        pf("%d\n",res);
    }
    return 0;
}
