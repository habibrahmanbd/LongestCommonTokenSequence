using namespace std;

#include <bits/stdc++.h>

int main()
{
    vector<db>arr(1000005);

    for(int64 i=1; i<=1000000; i++)
        arr[i]=arr[i-1]+log(i);

    int64 t=IL;
    int64 cs=1;
    while(t--)
    {
        int64 n=ILL,b=ILL;
        OC(cs++);
        pf("%lld\n",(int64)floor(arr[n]/log(b))+1);
    }

    return 0;
}
