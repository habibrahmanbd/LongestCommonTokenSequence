using namespace std;
#include<bits/stdc++.h>

ll len;
ll fact[21];
ll arr[26]={0};
ll n,all;
void F()
{
    fact[0]=1;
    for(ll i=1; i<21;i++)
        fact[i]=fact[i-1]*i;
    return;
}
ll permutation(ll n)
{
    ll res = fact[n];
    for(ll i=0; i<26;i++)
        res/= fact[arr[i]];
    return res;
}
void solve(ll father, ll pos)
{
    if(pos==len)
        return;
    for(ll i=0; i<26;i++)
    {
        if(arr[i])
        {
            arr[i]--;
            ll res = permutation(len-pos-1);
            if(father+res>=n)
            {
                pf("%c",i+'a');
                solve(father, pos+1);
            }
            else
                father+=res, arr[i]++;
        }
    }
}
int main()
{
    F();
    ll t=ILL;
    ll cs=1;
    while(t--)
    {
        string s;
        cin>>s;
        n=ILL;
        len = s.length();
        memset(arr,0,sizeof arr);
        for(ll i=0; i<len;i++)
            arr[s[i]-'a']++;
        all = permutation(len);
        pf("Case %lld: ",cs++);
        if(n>all)
            pf("Impossible\n");
        else
            solve(0,0),pf("\n");
    }
    return 0;
}
