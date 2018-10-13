using namespace std;
#include<bits/stdc++.h>
#define db          double
#define ll          long long
#define ull         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>
#define pb          push_back
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mll         map<ll,ll>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({ll a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         1<<29
ll nCr[1010][1010];
ll DERANGEMENT[1010];
int main()
{
    nCr[0][0]=1;
    for(ll i=1; i<=1009; i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        nCr[i][1]=i;
        for(ll j=2; j<i; j++)
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }
    //cout<<nCr[3][2]<<endl;
    DERANGEMENT[0]=1;
    DERANGEMENT[1]=0;
    for(ll i=2; i<=1009;i++)
        DERANGEMENT[i] = ((i-1) * (DERANGEMENT[i-1]+DERANGEMENT[i-2])%mod)%mod;
    ll t=ILL;
    ll cs=1;
    while(t--)
    {
        ll n=ILL,m=ILL,k=ILL;
        ll res=0;
        for(ll i=0; i<=n-m;i++)
            res=(res+(DERANGEMENT[m-k+i]*nCr[n-m][i])%mod)%mod;
        //cout<<nCr[m][k]<<endl;
        res = (res * nCr[m][k])%mod;
        pf("Case %lld: %lld\n",cs++,res);
    }
    return 0;
}
