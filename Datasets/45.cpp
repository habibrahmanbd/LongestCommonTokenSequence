using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        db r1=ID, r2=ID, r3=ID;
        db a=r1+r2, b=r2+r3, c=r3+r1;
        db A = acos(((b*b)+(c*c)-(a*a))/(2.0*b*c));
        db B = acos(((a*a)+(c*c)-(b*b))/(2.0*a*c));
        db C = acos(((b*b)+(a*a)-(c*c))/(2.0*b*a));
        db sum=0.0;
        sum = ((r1*r1*B)/2.0);
        sum += ((r2*r2*C)/2.0);
        sum += ((r3*r3*A)/2.0);

        db s = (a+b+c)/2.0;
        db Area_T = sqrt(s*(s-a)*(s-b)*(s-c));
        pf("Case %lld: %.10lf\n",cs,fabs(Area_T)-sum);

    }
    return 0;
}
