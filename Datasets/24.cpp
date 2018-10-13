using namespace std;

#include <bits/stdc++.h>

int main()
{
    input;
    int t=II,cs=1;
    while(t--)
    {
        double x=ID,y=ID, c=ID;
        double up=x<y ? x:y, lb=0.0, mid=(up+lb)/2.0,dis=mid;
        for(int i=0; i<50; i++)
        {
            mid=(up+lb)/2.0, dis=mid;
            double h1= sqrt(x*x - dis*dis);
            double h2= sqrt(y*y - dis*dis);
            double c1 = h1*h2 / (h1+h2);
            if(c1<c)
                up=mid;
            else lb=mid;
        }
        OC(cs++);
        pf("%0.7lf\n",dis);
    }
    return 0;
}
