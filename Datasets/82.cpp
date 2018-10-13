using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        db r1=ID, r2=ID, h=ID, p=ID;
        db R1=r1, R2=r2, H=h, P=p;
        db v_g = 1.0/3.0*PI*h*((r2*r2)+(r1*r2)+(r1*r1));
        db mid = r2+(r1-r2)*p/h;
        pf("Case %lld: %.10lf\n",cs,(1.0/3.0*PI*p*((mid*mid)+(mid*r2)+(r2*r2))));
    }
    return 0;
}
