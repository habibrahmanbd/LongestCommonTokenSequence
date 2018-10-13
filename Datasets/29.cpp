using namespace std;
#include<bits/stdc++.h>
#define maxN 5000011
ull phi[maxN];
bool isPrime[maxN];
void sieve()
{
    for(ull i=0; i<maxN; i++)
        isPrime[i] = true, phi[i] = i;
    for (ull i = 2; i < maxN; i++)
        if (isPrime[i])
            for (ull j = i; j < maxN; j += i)
            {
                isPrime[j] = false;
                phi[j] *= i - 1;
                phi[j] /= i;
            }
    phi[1] = 0;
    for(ll i=2; i<=maxN - 1; i++)
        phi[i] = phi[i - 1] + phi[i] * phi[i];
}

int main()
{
    sieve();
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll a=ILL,b=ILL;
        pf("Case %lld: %llu\n",cs,phi[max(b,a)]-phi[min(a,b)-1]);
    }
    return 0;
}
