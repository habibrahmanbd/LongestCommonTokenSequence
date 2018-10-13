using namespace std;
#include<bits/stdc++.h>

int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        string a;
        cin>>a;
        ll j=0,b=ILL;
        if(a[0]=='-')
            j=1;
        if(b<0)
            b=-b;
        ll r=0;
        for(; j<a.length(); j++)
        {
            r = (r*10)+(a[j]-'0');
            r%=b;
        }
        if(r)
            pf("Case %lld: not divisible\n",cs);
        else
            pf("Case %lld: divisible\n",cs);

    }
    return 0;
}
