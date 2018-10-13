using namespace std;
#include<bits/stdc++.h>

int dp[102][102];
int len;
string str;
int generate_palindrome(int st, int end)
{
//    pf("st: %d end= %d\n",st,end);
    if(st>=end)
        return 0;
    if(dp[st][end]==-1)
    {
//        int res=INT_MAX;
        int res1=INT_MAX,res2=INT_MAX,res3=INT_MAX;
        if(str[st]==str[end])
            res1=generate_palindrome(st+1,end-1);
        res2=1+generate_palindrome(st+1,end);
        res3=1+generate_palindrome(st,end-1);
        dp[st][end]=min(min(res1,res2),res3);

    }
    return dp[st][end];
}

int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>str;
        len=str.length();
        memset(dp, -1, sizeof dp);
        int res=generate_palindrome(0,len-1);
        pf("Case %d: %d\n",cs,res);
    }
    return 0;
}
