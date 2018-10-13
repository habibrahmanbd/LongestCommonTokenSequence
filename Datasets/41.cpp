using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll xx=ILL;
        int ans=1;
        ll x=(xx<0?-xx:xx);
        for(ll i=2; i<=31; i++)
        {
            if(xx<0 &&i%2==0)
                continue;
            int y=(int)ceil(pow(x, 1.0/i));
//            cout<<i<<": HI "<<y<<" res: "<<(int)pow((db)y,(db)i)<<endl;
            for(int j=y-1; j<=y+1; j++)
            {
                ll k=1;
                for(ll m=1; m<=i; m++)
                    k*=j;
                if(x==k)
                    ans=i;
            }
        }
        pf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
