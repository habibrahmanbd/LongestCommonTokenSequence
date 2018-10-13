using namespace std;
#include<bits/stdc++.h>


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++ )
    {
        int n=II;
//        int temp=n;
        int arr[102]= {0};
        for(int i=1; i<=n; i++ )
        {
            int p=i;
            for(int j=2; j*j<=i; j++ )
            {
                if(p%j==0)
                {

                    int cnt=0;
                    while(p%j==0)
                    {
                        p/=j;
                        cnt++;
                    }
                    arr[j]+=cnt;
                }
            }
            if(p>1)
                arr[p]++;
        }
        bool flag=0;
        for(int i=1; i<=n; i++ )
        {
            if(arr[i])
            {
                if(flag)
                    pf(" * %d (%d)",i,arr[i]);
                else
                    flag=1,pf("Case %d: %d = %d (%d)",cs,n,i,arr[i]);
            }
        }
        pf("\n");

    }
    return 0;
}
