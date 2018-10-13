
using namespace std;

#include <bits/stdc++.h>

int main()
{
//    input;
    int t=II,cs=1;
    while(t--)
    {
        double ab=ID, ac=ID, bc= ID, ratio=ID;
        double s = (ab+ac+bc) / 2.0;
        double abc = sqrt((s)*(s-ab)*(s-ac)*(s-bc));
        double up=ab, lb=0.0, mid=(up+lb) /2.0, ad=mid;
        for(int i=0; i<50; i++)
        {
            mid=(up+lb)/2.0, ad=mid;
            double temp_ratio = ad/ab, de = temp_ratio* bc, ae = temp_ratio * ac;
            double ss = (ad+de+ae)/2.0;
            double ade = sqrt(ss*(ss-ad)*(ss-ae)*(ss-de));
            if(ade/(abc-ade)>=ratio)
                up=mid;
            else lb=mid;
        }
        OC(cs++);
        pf("%0.15lf\n",ad);
    }
    return 0;
}
