using namespace std;
#include<bits/stdc++.h>
ull solve(ll row, ll col, ll k)
{
    if(k>col||k>row)
        return 0;
    else if(k==0)
        return 1;
    else if(col==1)
        return row;
    else
        return row*solve(row-1,col-1,k-1)+solve(row, col-1, k);
}
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL, k=ILL;
        pf("Case %lld: %llu\n",cs,solve(n,n,k));
    }
    return 0;
}
