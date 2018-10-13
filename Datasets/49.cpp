using namespace std;
#include<bits/stdc++.h>

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll x1=ILL,y1=ILL,x2=ILL,y2=ILL;
        ll q = abs(gcd((x1-x2),(y1-y2)));
        pf("Case %d: %lld\n",cs, q+1);
    }
    return 0;
}
