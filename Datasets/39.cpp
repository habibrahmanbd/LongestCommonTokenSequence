using namespace std;
#include<bits/stdc++.h>

#define sz 102
bool L[sz];
bool R[sz];
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        memset(L,0,sizeof L);
        memset(R,0,sizeof R);
        int ans_left=0,ans_right=0;
        for(int i=1; i<=n; i++)
        {
            int u=II, v=II, cost=II;
            if(!L[u]&&!R[v])
            {
                L[u]=R[v]=1;
                ans_left+=cost;
            }
            else
            {
                R[u]=L[v]=1;
                ans_right+=cost;
            }
        }
        pf("Case %d: %d\n",cs, min(ans_left,ans_right));
    }
    return 0;
}
