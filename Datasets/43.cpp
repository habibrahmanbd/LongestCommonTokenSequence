using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL, p=ILL,q=ILL;
        ll arr[n];
        for(ll i=0; i<n; i++)
            arr[i]=ILL;
        ll j=0;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            if(sum+arr[i]<=q&&j<p)
                sum+=arr[i],j++;
            else
                break;
        }
        pf("Case %lld: %lld\n",cs,j);
    }
    return 0;
}
