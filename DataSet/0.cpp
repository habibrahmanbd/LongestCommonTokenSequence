using namespace std;
#include<bits/stdc++.h>

#define db          double
#define ll          long long
#define ull         unsigned long long

#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>

#define mii         map<int,int>
#define mll         map<ll,ll>

#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>

#define pb          push_back
#define mp          make_pair
#define fs          first
#define sc          second

#define pf          printf
#define sf          scanf
#define II          ({int a; _in(a); a;})
#define IL          ({long a; _in(a); a;})
#define ILL         ({ll a; _in(a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define IS          ({string a; _in_cin_string(a); a;})

#define repI(i,b,c)  for(int i=b;   i<=c; i++)
#define repL(i,b,c)  for(long i=b;  i<=c; i++)
#define repLL(i,b,c) for(ll i=b;    i<=c; i++)

#define all(V)      V.begin(),V.end()
#define clr(A,B)    memset(A,B,sizeof A)

#define _F_in       freopen("in.txt","r",stdin)
#define _F_out      freopen("out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         LLONG_MAX
#define sqr(n)      (n*n)

#define endl	    '\n'

template <typename T>inline T BigMod (T b,T p,T m)
{
    if (p == 0) return 1;
    if (p%2 == 0)
    {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T>inline T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
}
template <typename T>inline T Bigmod(T b,T p,T m)
{
    if(p==0) return 1;
    else if (!(p&1)) return sqr(Bigmod(b,p/2,m)) % m;
    else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template <typename T>inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <typename T>inline T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/gcd(a,b));
}
template <typename T>inline T euclide(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}
template <typename T>inline T Dis(T x1,T y1,T x2, T y2)
{
    return sqrt( (sqr((x1-x2)) + sqr((y1-y2))) );
}
template <typename T>inline T Angle(T x1,T y1,T x2, T y2)
{
    return atan(double(y1-y2) / double(x1-x2));
}
template <typename T>inline T DIFF(T a,T b)
{
    T d = a-b;
    if(d<(T)0)return -d;
    else return d;
}
template <typename T>inline T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}
template <typename T>inline ll isLeft(T a,T b,T c)
{
    return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);
}

template <typename T>inline void _in(T &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c<48 | c>57) && c != '-'); c = getchar());
    if(c=='-')
    {
        neg=1;
        c=getchar();
    }
    for(; c>47 && c<58; c = getchar())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x=-x;
}

template <typename T>inline bool isLeapYear(T N)
{
    if (N%4) return 0;
    else if (N%100) return 1;
    else if (N%400) return 0;
    else return 1;
}
template <typename T>inline T Set(T N,T pos)
{
    T A = 1;
    return N=N | (A<<pos);
}
template <typename T>inline T Reset(T N,T pos)
{
    T A = 1;
    return N= N & ~(A<<pos);
}
template <typename T>inline bool Check(T N,T pos)
{
    T A=1;
    return (bool)(N & (A<<pos));
}
template <class T, class X>inline T togglebit(T a, X i)
{
    T t=1;
    return (a^(t<<i));
}

template <class T, class X>inline T toInt(T &sm, X s)
{
    stringstream ss(s);
    ss>>sm;
    return sm;
}
template <typename T>inline int cdigittoint(T ch)
{
    return ch-'0';
}
template <typename T>inline bool isVowel(T ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;
    return false;
}
template <typename T>inline bool isConst(T ch)
{
    if (isalpha(ch) && !isVowel(ch)) return true;
    return false;
}


inline double DEG(double x)
{
    return (180.0*x)/(PI);
}
inline double RAD(double x)
{
    return (x*(double)PI)/(180.0);
}

//Knight Move
//ll dx[]= {-1, -2, -2, -1, +1, +2, +2, +1};
//ll dy[]= {-2, -1, +1, +2, +2, +1, -1, -2};

//8 Direction
//ll dx[]={-1, -1, -1, 0, +1, +1, +1, 0};
//ll dy[]={-1, 0, +1, +1, +1, 0, -1, -1};

//4 Direction
//ll dx[]={0, +1, 0, -1};
//ll dy[]={+1, 0, -1, 0};

///------------------------------------------------------///
#define lim          8010  //number of nodes(yes/no nodes)
//0 based
vector<int> adj[2*lim]; //2*lim for true and false argument(only adj should be cleared)
int col[2*lim],low[2*lim],tim[2*lim],timer;
int group_id[2*lim],components;//components=number of components, group_id = which node belongs to which node
bool ans[lim]; //boolean assignment ans
stack<int>S;

int res[lim];
int tot;
void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();
            S.pop();
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }
        while(tem!=u);
        components++;
    }
}

int TarjanSCC(int n)   //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    clr(col,0);
    while(!S.empty()) S.pop();
    for(i=0; i<n; i++)
        if(col[i]==0) scc(i);
    return components;
}

//double nodes needed normally
bool TwoSAT(int n)   //n=nodes (some change may be required here)
{
    TarjanSCC(n);
    int i;
    for(i=0; i<n; i+=2)
    {
        if(group_id[i]==group_id[i+1])
            return false;
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
            ans[i>>1]=true;
        else ans[i>>1]=false;
    }
    return true;
}

void add(int ina,int inb)
{
    adj[ina].pb(inb);
}

int complement(int n)
{
    if(n%2) return n-1;
    return n+1;
}

void initialize(int n)
{
    for(int i=0; i<n; i++)
        adj[i].clear();
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        int N,M;
        scanf("%d %d", &N, &M);
        M <<= 1;
        initialize(M+2);
        for(int i=0; i<N; i++)
        {
            char ac, bc;
            int a, b;
            sf(" %c%d %c%d",&ac,&a,&bc,&b);
            a--,b--;
            a<<=1;
            b<<=1;
            if(ac=='+')
                a^=1;
            if(bc=='+')
                b^=1;
//            cout<<ac<<' '<<bc<<endl;
            adj[a].pb(b^1); //!x v y
            adj[b].pb(a^1); //!y v x
        }
        printf("Case %d: ", caseNo + 1);
        if(TwoSAT(M))
        {
            pf("Yes\n");
            tot=0;
            for(int i=0; i<M; i+=2)
            {
                if(ans[i>>1])
                    res[tot++] = (i>>1)+1;
            }
            pf("%d",tot);
            for(int i=0; i<tot; i++)
                pf(" %d",res[i]);
            pf("\n");
        }
        else
            pf("No\n");
    }
    return 0;
}
