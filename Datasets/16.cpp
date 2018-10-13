using namespace std;
#include<bits/stdc++.h>

ll fact[21],n;
ll a[21];
void solve()
{
    ll m=0;
    for(ll i=20; i>=0; i--)
    {
        if(n>=fact[i])
        {
            n-=fact[i];
            a[m++]=i;
        }
    }
    if(n)
        n=-1;
    else n=m;
}
int main()
{
    fact[0]=(ll)1;
    for(ll i=1; i<=20 ;i++)
        fact[i]=fact[i-1]*i;
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        n=ILL;
        solve();
//        cout<<n<<endl;
        if(n<0)
            pf("Case %lld: impossible\n",cs);
        else
        {
            pf("Case %lld: ",cs);
            for(ll i=n-1; i>0; i--)
                pf("%lld!+",a[i]);
            pf("%lld!\n",a[0]);
        }
    }
    return 0;
}
