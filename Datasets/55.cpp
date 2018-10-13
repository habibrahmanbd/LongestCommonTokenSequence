using namespace std;
#include<bits/stdc++.h>


int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int i=1;i<=t;i++)
    {
        int n=II;
        int a[n][3];
        for(int j=0; j<n; j++)
            sf("%d %d %d",&a[j][0],&a[j][1],&a[j][2]);
        for(int j=1;j<n; j++)
        {
            a[j][0]+=min(a[j-1][1],a[j-1][2]);
            a[j][1]+=min(a[j-1][0],a[j-1][2]);
            a[j][2]+=min(a[j-1][1],a[j-1][0]);
        }
        pf("Case %d: %d\n",i,min(min(a[n-1][0],a[n-1][1]),a[n-1][2]));
    }
    return 0;
}
