
using namespace std;

#include <bits/stdc++.h>

int main()
{
    int64 t=ILL;
    int64 cs=1;
    fact[0]=1;
        fact[1]=1;
    for(long long i=2; i<1000001; i++)
        fact[i]=(fact[i-1]*i)%MOD;
//    vector<int64>r;
//    r[1]=1;
//    for(long long i=2; i<1000004;i++)
//        r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
    while(t--)
    {
        int64 n=ILL, r=ILL;
        //cout<<fact[n-r]<<" "<<fact[r]<<endl;
        int64 p  = ((fact[n-r]%MOD)*(fact[r]%MOD))%MOD;
        //cout<<BigMod(p,MOD-2)<<endl;
        int64 res = (fact[n]%MOD*BigMod(p,MOD-2)%MOD)%MOD;
//        int q= r[p];
//        int64 res = (fact[n]%MOD*r[p]%MOD)%MOD;
        pf("Case %lld: %lld\n",cs++,res);
    }
    return 0;
}
