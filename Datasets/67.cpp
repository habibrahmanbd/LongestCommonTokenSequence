using namespace std;
#include<bits/stdc++.h>

#define s 1000010
bool col[s];
ll prime[s];
ll maxim;
void seive()//1 indexed
{
    ll i,j,k;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<s;j+=2)
        col[j]=true;
    for(i=3;i<s;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    col[j]=true;
         }
    maxim=k;
    return;
}

int main()
{
    seive();
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll res=1;
        for(ll i=1; prime[i]*prime[i]<=n && i<=maxim; i++)
        {
            ll cnt=0;
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt++;
                }
            }
            res*=(cnt+1);
        }
        if(n>1)
            res*=2;
        res-=1;
        pf("Case %d: %lld\n",cs, res);
    }
    return 0;
}
