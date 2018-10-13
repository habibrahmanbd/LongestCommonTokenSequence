using namespace std;
#include<bits/stdc++.h>

int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        db v1=ID, v2=ID, v3=ID, a1=ID, a2=ID;
        db t1=v1/a1;
        db t2=v2/a2;
        db s1 = (v1*v1*0.5)/a1;
        db s2 = (v2*v2*0.5)/a2;
        pf("Case %lld: %.10lf %.10lf\n",cs,s1+s2,max(t1,t2)*v3);
    }
    return 0;
}
