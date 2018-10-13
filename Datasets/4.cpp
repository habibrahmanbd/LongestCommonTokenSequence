using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll m=sqrt(n);
        ll res=0;
        for(ll i=1; i<=m; i++)
            res+=n/i;
        for(ll i=1; i<=m; i++)
            res+=(ll)((n/i)-(n/(i+1)))*i;
        if(m==n/m)
            res-=m;
        pf("Case %d: %lld\n",cs,res);
    }
    return 0;
}
///a nice shortest solution of ahmed faiyaz Bhai
/*
long long int res=0;
long long H( int n ) {
    res = 0;
    int tmp=sqrt(n);
    for( int i = 1; i <= tmp; i++ )
        res = res + n / i;

    return 2*res-tmp*tmp;
}

*/
