using namespace std;
#include<bits/stdc++.h>

inline void func()
{
    dp[0]=1;
    dp[1]=2;
    FRL(1,mod,1)
    {
        dp[i]=(dp[i-1]*i+1)%mod;
    }
}
int main()
{
    func();
    ll t=ILL;
    ll i=1;
    while(t--)
    {
        ll k=ILL;
        if(k>=7)
            cout<<"Case "<<i++<<": "<<setfill('0')<<setw(4)<<dp[k%mod]<<endl;
        else
            cout<<"Case "<<i++<<": "<<dp[k%mod]<<endl;
    }
    return 0;
}
