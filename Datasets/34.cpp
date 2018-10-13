using namespace std;
#include<bits/stdc++.h>

ll nCr[1010][1010];
ll DERANGEMENT[1010];
int main()
{
    nCr[0][0]=1;
    for(ll i=1; i<=1009; i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        nCr[i][1]=i;
        for(ll j=2; j<i; j++)
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }
    //cout<<nCr[3][2]<<endl;
    DERANGEMENT[0]=1;
    DERANGEMENT[1]=0;
    for(ll i=2; i<=1009;i++)
        DERANGEMENT[i] = ((i-1) * (DERANGEMENT[i-1]+DERANGEMENT[i-2])%mod)%mod;
    ll t=ILL;
    ll cs=1;
    while(t--)
    {
        ll n=ILL,m=ILL,k=ILL;
        ll res=0;
        for(ll i=0; i<=n-m;i++)
            res=(res+(DERANGEMENT[m-k+i]*nCr[n-m][i])%mod)%mod;
        //cout<<nCr[m][k]<<endl;
        res = (res * nCr[m][k])%mod;
        pf("Case %lld: %lld\n",cs++,res);
    }
    return 0;
}
