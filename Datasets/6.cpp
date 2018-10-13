using namespace std;
#include<bits/stdc++.h>

#define EPS 0.000000001
int main()
{
    ll t=ILL;
    for(ll i=1; i<=t; i++)
    {
        db a,b;
        sf("%lf : %lf",&a,&b);
        db high=400.0, low=0.0;
        while(fabs(high-low)>EPS)
        {
            db len =(high+low)/2.0;
            db half_len = len/2.0;
            db width = (b*len)/a;
            db half_width = width/2.0;
            db rad = sqrt((half_len*half_len) + (half_width*half_width));
            db theta = acos(half_len/rad);
            db arc  = theta*rad;
            db ex_arc = (200.0-len)/2.0;
            if(arc>ex_arc)
                high = len;
            else low = len;
        }
        pf("Case %lld: %.8lf %.8lf\n",i, low, (b*low)/a);
    }
    return 0;
}
