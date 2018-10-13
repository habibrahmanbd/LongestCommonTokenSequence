using namespace std;
#include<bits/stdc++.h>


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

struct points
{
    db x, y, z;
    double dist(points p)
    {
        p.x -= x;
        p.y -= y;
        p.z -= z;
        return sqrt(p.x * p.x + p.y * p.y+ p.z*p.z);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        points a,b,p;
        cin>>a.x>>a.y>>a.z;
        cin>>b.x>>b.y>>b.z;
        cin>>p.x>>p.y>>p.z;
        db res=(db)(1e15);
        for(ll i=0; i<=50; i++)
        {
            points left, right;

            left.x= a.x+(b.x-a.x)/3.0;

            left.y= a.y+(b.y-a.y)/3.0;

            left.z= a.z+(b.z-a.z)/3.0;

            right.x= b.x-(b.x-a.x)/3.0;

            right.y= b.y-(b.y-a.y)/3.0;

            right.z= b.z-(b.z-a.z)/3.0;

            db m1 = p.dist(left);

            db m2 = p.dist(right);

            res=min(res,min(m1,m2));

            if(m1>m2)
                a=left;
            else
                b=right;
//            cout<<res<<endl;
        }
        cout<<"Case "<<cs<<": "<<setprecision(10)<<res<<endl;
    }
    return 0;
}
