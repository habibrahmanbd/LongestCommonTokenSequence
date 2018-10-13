using namespace std;
#include<bits/stdc++.h>

int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll a=0,b=0;
        if(n>=11)
        {
            if(n%2)
            {
                a=n/2;
                b=a+1;
            }
            else
            {
                a=n/2;
                b=a;
            }
        }
        else
        {
            a=0, b=n;
        }
        pf("%lld %lld\n",a,b);
    }
    return 0;
}
