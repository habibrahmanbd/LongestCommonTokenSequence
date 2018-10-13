using namespace std;

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

ll solve  (ll a,  ll b,  ll m)
{
    ll n =  (ll) sqrt (m + .0)  +  1;
    ll an =  1;
    for (ll i=0; i<n; ++i)
        an =  (an * a)  % m;
    map<ll, ll> vals;
    for (ll i=1, cur=an; i<=n; ++i)
    {
        if (!vals.count(cur))
            vals[ cur]  = i;
        cur =  (cur * an)  % m;
    }
    ll res=INF;
    for (ll i=0, cur=b; i<=n; ++i)
    {
        if (vals.count(cur))
        {
            ll ans = vals[cur] * n - i;
            if (ans < m)
                res=min(res,ans);
        }
        cur =  (cur * a)  % m;
    }
    if(res!=INF)
        return res;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        ll a,b;
        cin>>a>>b;
        pf("Case %lld: %lld\n",cs,solve(a,b,mod));
    }
    return 0;
}
