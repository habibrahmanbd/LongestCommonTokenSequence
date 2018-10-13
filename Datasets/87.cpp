using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II, d=II;
        deque<pi>dq1,dq2;
        vi v(n);
        for(int i=0; i<n; i++)
            v[i]=II;
        int ans=-1;
//        pf("here");
        for(int i=0; i<n; i++)
        {
            while(dq1.size()&&dq1.front().first>=v[i])
                dq1.pop_front();
            while(dq1.size()&&dq1.back().second<=i-d)
                dq1.pop_back();
            dq1.push_front(pi(v[i],i));
            while(dq2.size()&&dq2.front().first<=v[i])
                dq2.pop_front();
            while(dq2.size()&&dq2.back().second<=i-d)
                dq2.pop_back();
            dq2.push_front(pi(v[i],i));
            if(i>=d-1)
                ans=max(ans, abs(dq1.back().first-dq2.back().first));
        }
        pf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
