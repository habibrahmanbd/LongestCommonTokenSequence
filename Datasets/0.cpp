using namespace std;
#include<bits/stdc++.h>

inline ll gcd(ll a,ll b)
{
    a=abs(a);
    b=abs(b);
    while (a&&b)a>b?a-=b:b-=a;
    return a+b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n;
        cin>>n;
        ll x[n+1],y[n+1];
        ll s=0;
        ll bord=0;
        for (ll i=0; i<n; i++)
            cin>>x[i]>>y[i];

        x[n]=x[0];
        y[n]=y[0];
        for (ll i=0; i<n; i++)
            s+=x[i+1]*y[i]-x[i]*y[i+1];
        for (ll i=0; i<n; i++)
            bord+=gcd(y[i+1]-y[i],x[i+1]-x[i]);
//        cout<<bord<<endl;
        pf("Case %lld: %lld\n",cs, (abs(s)+2-bord)/2);
    }
    return 0;
}
