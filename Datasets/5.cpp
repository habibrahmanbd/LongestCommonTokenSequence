using namespace std;
#include<bits/stdc++.h>
#define INF         LLONG_MAX
#define endl	    '\n'

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}
//------------------------------------------------------


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll rx1,rx2,ry1,ry2,rz1,rz2;
        rx1=ry1=rz1=-INF;
        rx2=ry2=rz2=INF;
        for(ll i=1; i<=n; i++)
        {
            ll x1=ILL,y1=ILL,z1=ILL;
            ll x2=ILL,y2=ILL,z2=ILL;
            rx1 = max(rx1, x1);
            ry1 = max(ry1, y1);
            rz1 = max(rz1, z1);
            rx2 = min(rx2, x2);
            ry2 = min(ry2, y2);
            rz2 = min(rz2, z2);
        }
        ll volume = (rx2-rx1)*(ry2-ry1)*(rz2-rz1);
        pf("Case %lld: %lld\n",cs,volume>0?volume:0);
    }
    return 0;
}
