using namespace std;
#include<bits/stdc++.h>

#define p_z 1000005
ll prime[p_z/10];
bool is_prime[p_z+10];
ll total=0;
void prime_generate()
{
    is_prime[0]=is_prime[1]=1;
    for(ll i=4; i<=p_z; i+=2)
        is_prime[i]=1;
    for(ll i=2; i<=p_z; i++)
    {
        if(!is_prime[i])
        {
            prime[total++]=i;
            for(ll j=i*i; j<=p_z; j+=i)
                is_prime[j]=1;
        }
    }
    return;
}
bool vis[p_z+10];
int main()
{
    prime_generate();
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll a=ILL, b=ILL;
        ll ans=0;
        if(b<=100000)
        {
            ans=0;
            ll i;
            if(a<=2)
                i=3;
            else
                i=(a%2!=0?a:a+1);
            for(i; i<=b; i+=2)
            {
                if(is_prime[i]==0)
                    ans++;
            }
            if(a<=2&&b>=2)
                ans++;
        }
        else
        {
            ans=0;
            memset(vis,0,sizeof vis);
            ll n=(b-a);
            for(ll i=0; i<total&&prime[i]*prime[i]<=b; i++)
            {
                ll st=max((ll)a/prime[i]*prime[i], (ll)prime[i]*prime[i]);
                for(ll j=st; j<=b; j+=prime[i])
                    if(j>=a)
                        vis[b-j]=1;
            }
            for(ll i=0; i<=n; i++)
                if(vis[i]==0)
                    ans++;
            if(a==1)
                ans--;
        }
        pf("Case %d: %lld\n",cs, ans);

    }
    return 0;
}
