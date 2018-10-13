using namespace std;
#include<bits/stdc++.h>

struct point
{
    ll x,y;
};
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        point a,b,c,d;
        a.x=ILL,a.y=ILL;
        b.x=ILL,b.y=ILL;
        c.x=ILL,c.y=ILL;
        d.x=a.x+c.x-b.x,d.y=a.y+c.y-b.y;
//        ll ot = abs((c.x-d.x)*(c.y-b.y));
        ll res  = abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
        pf("Case %lld: %lld %lld %lld\n",cs,d.x,d.y,res);
    }
    return 0;
}
