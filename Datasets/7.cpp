using namespace std;
#include<bits/stdc++.h>

int S,T;
vi pmf[1001];
void primefactor(int n)
{
    int temp=n;
    for(int i=2; i*i<=temp; i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                n/=i;
                count++;
            }
            if(count)
                pmf[temp].pb(i);
        }
    }
    if(n>1&&n<temp)
        pmf[temp].pb(n);
    if(n==temp)
        pmf[temp].clear();
//    pf("%d: ",temp);
//    for(int i=0; i<pmf[temp].size(); i++)
//        pf("%d ",pmf[temp][i]);
//    pf("\n");
    return;
}
int bfs()
{
    int dp[1001];
    memset(dp, -1, sizeof dp);
    queue<int>q;
    q.push(S);
    dp[S]=0;
    int from, to;
    while(!q.empty())
    {
        from=q.front();
        q.pop();
        for(int i=0; i<pmf[from].size(); i++)
        {
//            cout<<pmf[from][i]
            to=from+pmf[from][i];
            if(dp[to]==-1&&to<=T)
            {
                dp[to]=dp[from]+1;
                q.push(to);
                if(to==T)
                    return dp[T];
            }
        }
    }
    return dp[T];
}
int main()
{
    for(int i=2; i<=1000; i++)
        primefactor(i);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        S=II,T=II;
        pf("Case %d: %d\n",cs,bfs());
    }
    return 0;
}
