using namespace std;

#include <bits/stdc++.h>
int main()
{
    int t=II;
    int cs=1;
    while(t--)
    {
        int Ox=II, Oy=II, Ax=II, Ay=II, Bx=II, By=II;
        db rad     = sqrt((db)((Ox-Ax)*(Ox-Ax))+(db)((Oy-Ay)*(Oy-Ay)));
        db AB      = sqrt((db)((Bx-Ax)*(Bx-Ax))+(db)((By-Ay)*(By-Ay)));
        db angle   = acos(1.0 - 0.5 * pow((AB/rad),2));
        db arc     = rad * angle ;
        OC(cs++);
        pf("%lf\n",fabs(arc));
    }
    return 0;
}
