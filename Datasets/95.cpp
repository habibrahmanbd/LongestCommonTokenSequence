using namespace std;
#include<bits/stdc++.h>

#define sz 30005
vector<vector<pi> >adjList;
bool visited[sz];
long cost[sz];
void dfs(int u)
{
//    visited[u]=1;
    for(int i=0; i<adjList[u].size(); i++)
    {
        int v=adjList[u][i].first;
        int temp_cost=adjList[u][i].second;

        if(!visited[v])
        {
            visited[v]=1;
//            cout<<u<< " "<<v<< " "<<temp_cost<<endl;
            cost[v]=cost[u]+temp_cost;
//            cout<<cost[v]<<endl;
            dfs(v);
        }
    }
    return;
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        memset(visited, 0, sizeof visited);
        memset(cost, 0, sizeof cost);
        vector<vector<pi> >temp(sz);
        swap(temp,adjList);
        for(int i=0; i<n-1; i++)
        {
            int u=II, v=II, w=II;
            adjList[u].pb(pi(v,w));
            adjList[v].pb(pi(u,w));
        }
        visited[0]=1;
        dfs(0);
        int res=-1;
        int ase=0;
        for(int i=0; i<n; i++)
            if(res<cost[i])
            {
//                pf("hello\n");
                res=cost[i];
                ase = i;
            }
//        pf("Why ase not showed!!");
//        cout<<ase<<endl;
        memset(visited, 0, sizeof visited);
        memset(cost,0, sizeof cost);
        visited[ase]=1;
        dfs(ase);
        res=-1;
        for(int i=0; i<n; i++)
            res = res<cost[i]?cost[i]:res;
        pf("Case %d: %ld\n", cs, res);

    }
    return 0;
}
