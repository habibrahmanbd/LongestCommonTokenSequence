using namespace std;
#include<bits/stdc++.h>

int main()
{
    ll T=ILL;
    for(ll cs=1; cs<=T; cs++)
    {
        ll N=ILL, M=ILL;
        ll Life_cycle[M];
        for(ll i=0; i<M; i++) Life_cycle[i]=ILL;
        ll to = (ll) pow(2,M);
        ll res=0;
        for(ll i=1; i<to; i++)
        {
            ll lcm_of_sets = 1;
            ll num_of_sets=0;
            ll bit_len = (ll)ceil(log2(i));
            for(ll j=0; j<=bit_len; j++)
            {
                if((1<<j)&i)
                {
                    num_of_sets++;
                    lcm_of_sets = (lcm_of_sets*Life_cycle[j])/gcd(lcm_of_sets,Life_cycle[j]);
                }
            }
            if((num_of_sets+1)%2)
                res-=(ll)floor(N/lcm_of_sets);
            else
                res+=(ll)floor(N/lcm_of_sets);
//            cout<<"Res: "<<res<<endl;
        }

        pf("Case %lld: %lld\n",cs,N-res);
    }
    return 0;
}
