using namespace std;
//C headers

//vector<int>edge[mx];
//stack<int>S;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll testCase;
    cin>>testCase;
    for(ll oc=1; oc<=testCase;oc++)
    {
        ll n,m;
        cin>>n>>m;
        vector< vector<pair<ll,ll> > >g(n);
        for(ll i=0; i<m; i++)
        {
            ll a,b, c;
            cin>>a>>b>>c;
            g[a-1].push_back(make_pair(b-1,c));
            g[b-1].push_back(make_pair(a-1,c));
        }
        ll s=0;
        vector<ll>d(n,INF),p(n);
        d[s]=0;
        bool u[n];
        memset(u,0,sizeof u);
        for(ll i=0; i<n; ++i)
        {
            ll v=-1;
            for(ll j=0; j<n; ++j)
            {
                if(!u[j]&&(v==-1||d[j]<d[v]))
                    v=j;
            }
            if(d[v]==INF)
                break;
            u[v]=true;
            for(size_t j=0; j<g[v].size(); ++j)
            {
                ll to =g[v][j].first, len= g[v][j].second;
                if(d[v]+len<d[to])
                {
                    d[to]=d[v]+len;
                    p[to]=v;
                }
            }
        }
        pf("Case %lld: ",oc);
        if(u[n-1]==true)
            pf("%lld\n",d[n-1]);
        else
            pf("Impossible\n");
    }
    return 0;
}
