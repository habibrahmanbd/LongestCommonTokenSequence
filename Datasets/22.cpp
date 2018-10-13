using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        unsigned int n;
        cin>>n;
        int x=__builtin_popcount (n);
        if(x%2)
        {
            pf("Case %d: odd\n",cs);
        }
        else
            pf("Case %d: even\n",cs);
    }
    return 0;
}
