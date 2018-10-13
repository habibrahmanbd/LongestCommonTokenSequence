using namespace std;
#include<bits/stdc++.h>
int gold[102];
double dp[102],res;

int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        for(int i=1; i<=n; i++)
            gold[i]=II;
        res=0.0;
        if(n<=2)
        {
            for(int i=1; i<=n; i++)
                res+=(db)gold[i];
        }
        else
        {
            dp[1]=(db)gold[1];
            dp[n]=(db)gold[n];
            for(int i=n-1; i>=1; i--)
            {
                int _in,_out;
                if(n-i<6)
                {
                    _in=n-i;
                    _out=i+6-n;
                }
                else
                    _in=6,_out=0;
                db _in_sum=0.0;
                for(int k=1; k<=_in; k++)
                    _in_sum+=dp[i+k];
                if(_out<6)
                    dp[i]=(6.0/(6.0-(db)_out))*(((db)_in_sum/6.0)+((db)_in/6.0)*(db)gold[i]);
                else
                    dp[i]=(((db)_in_sum/6.0)+((db)_in/6.0)*(db)gold[i]);
            }
            res+=dp[1];
        }
        pf("Case %d: %.10lf\n",cs,res);

    }
    return 0;
}
