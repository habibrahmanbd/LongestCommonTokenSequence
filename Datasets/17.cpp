using namespace std;
#include<bits/stdc++.h>



int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll m=ILL,n=ILL;
        ll ans=0;
        if(m==1)
            ans=n;
        else if(n==1)
            ans=m;
        else if(n == 2)
		{
			ans = (m / 4) * 4;
			if(m % 4 == 1)
				ans += 2;
			else if(m % 4 > 1)
				ans += 4;
		}
		else if(m == 2)
		{
			ans = (n / 4) * 4;
			if(n % 4 == 1)
				ans += 2;
			else if(n % 4 > 1)
				ans += 4;
		}
		else
			ans = ((m * n) + 1) / 2;
        pf("Case %lld: %lld\n",cs, ans);
    }
    return 0;
}
