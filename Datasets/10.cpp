using namespace std;
#include<bits/stdc++.h>

int T,n;
struct ed
{
    int x,y;
    bool operator < (const ed &a)const
    {
        if(a.x!=x)return a.x>x;
        return a.y>y;
    }
    bool operator ==(const ed &a)const
    {
        return a.x==x&&a.y==y;
    }
} edg[N*N];
int cnt[N*N];
int cp;
struct nd
{
    int x,y;
} nod[N];
int main()
{
    T=II;
    int tt=0;
    while(T--)
    {
        n=II;
        for(int i=1; i<=n; i++)
            nod[i].x=II,nod[i].y=II;
        cp=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                ed gg;
                gg.x=nod[i].x+nod[j].x;
                gg.y=nod[i].y+nod[j].y;
                edg[cp++]=gg;
            }
        }
        sort(edg,edg+cp);
        int yu=unique(edg,edg+cp)-edg; // Remove all the consecutive same elements
//        cout<<yu<<endl;
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                ed gg;
                gg.x=nod[i].x+nod[j].x;
                gg.y=nod[i].y+nod[j].y;
                int id=lower_bound(edg,edg+yu,gg)-edg; // returns the id of gg point
//                cout<<id<<endl;
                ans+=cnt[id];
                cnt[id]++;
            }
        }
//      those two for loop uses to detect the same element appears in the combination... If two same pair are same then it added to cnt 1.
        printf("Case %d: %d\n",++tt,ans);
    }
    return 0;
}
