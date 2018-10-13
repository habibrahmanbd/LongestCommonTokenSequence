using namespace std;
#include<bits/stdc++.h>


int prime[700000];
bool is_prime[10000000];

int total=0;
void solve()
{
    total=0;
    is_prime[0]=is_prime[1]=1;
    for(int i=2; i<10000000; i++)
    {
        if(!is_prime[i])
        {
            prime[total++]=i;
            for(int j=i*2; j<10000000; j+=i)
            {
                is_prime[j]=1;
            }

        }
    }
    return;
}

int main()
{
    solve();
    int t=II;
    for(int cs=1;cs<=t; cs++)
    {
        int n=II;
        int res=0;
        for(int i=0; prime[i]<=n/2; i++)
        {
            int j=n-prime[i];
            if(!is_prime[j])
                res++;
        }
        pf("Case %d: %d\n", cs, res);
    }
    return 0;
}
