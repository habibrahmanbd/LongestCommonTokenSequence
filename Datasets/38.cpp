using namespace std;
#include<bits/stdc++.h>
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll arr[n];
        for(ll i=0; i<n; i++)
            arr[i]=ILL;
        ll count=0;
        if(arr[0]>2)
        {
            ll res=(arr[0]-2)/5;
            ll rem = (arr[0]-2)%5;
            count+=res;
            if(rem)
                count++;
        }
        for(ll i=0; i<n-1; i++)
            if(arr[i]<arr[i+1])
            {
                ll res=(arr[i+1]-arr[i])/5;
                ll rem = (arr[i+1]-arr[i])%5;
                count+=res;
                if(rem)
                    count++;
            }
        pf("Case %lld: %lld\n",cs,count);
    }
    return 0;
}
