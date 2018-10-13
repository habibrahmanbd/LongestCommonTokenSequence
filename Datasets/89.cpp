using namespace std;
#include<bits/stdc++.h>
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        points a,b,c,d;
        a.x=ID,a.y=ID;
        b.x=ID,b.y=ID;
        c.x=ID,c.y=ID;
        d.x=ID,d.y=ID;
        db res=(db)LONG_LONG_MAX;
        for(ll i=0; i<=100; i++)
        {
            points a_a,b_b, c_c, d_d;

            a_a.x= a.x+(b.x-a.x)/3.0;
            a_a.y= a.y+(b.y-a.y)/3.0;

            c_c.x= c.x+(d.x-c.x)/3.0;
            c_c.y= c.y+(d.y-c.y)/3.0;

            b_b.x= b.x-(b.x-a.x)/3.0;
            b_b.y= b.y-(b.y-a.y)/3.0;

            d_d.x= d.x-(d.x-c.x)/3.0;
            d_d.y= d.y-(d.y-c.y)/3.0;

            db m1 = a_a.dist(c_c);
            db m2 = b_b.dist(d_d);
            res=min(res,min(m1,m2));

            if(m1>m2)
                a=a_a,c=c_c;
            else
                b=b_b,d=d_d;
//            cout<<res<<endl;
        }
        pf("Case %lld: %.10lf\n",cs,res);
    }
    return 0;
}
