using namespace std;
#include<bits/stdc++.h>
ll dp[60][60];
bool visit[60][60];
string w;
ll solve(int i, int j)
{
    if(j<i) // i and j cross themselves.
        return 0;
    if(j==i) //pointing the same character of the string
        return 1;
    if(!visit[i][j])
    {
        if(w[i]==w[j])
            dp[i][j]=(1+solve(i+1,j)+solve(i,j-1));
//            this expression basically is- 1 + solve(i+1,j-1) + ( solve(i+1,j) + solve(i, j-1) - solve(i+1, j-1))
        else
        {
            dp[i][j]=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
//            inclusion and exclusion is done here for the reason of over counting of solve(i+1, j-1)
        }
    }
    visit[i][j]=1;
    return dp[i][j];
}
//            the solution technique is given in http://codeforces.com/blog/entry/15372
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>w;
        memset(dp, -1, sizeof dp);
        memset(visit, 0, sizeof visit);
        pf("Case %d: %lld\n", cs, solve(0,w.length()-1));
    }
    return 0;
}
