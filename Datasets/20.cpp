using namespace std;

#include <bits/stdc++.h>

#include<stdio.h>
int main()
{
    long long n,caseno = 0,cases,fn[10005],i;
    scanf("%lld",&cases);
    while( cases-- )
    {
        for(i=0; i<6; i++)
            scanf("%lld",&fn[i]);
        scanf("%lld",&n);
        for(i=6; i<=n; i++)
            fn[i]=(fn[i-1]+fn[i-2]+fn[i-3]+fn[i-4]+fn[i-5]+fn[i-6])%10000007;
        printf("Case %lld: %lld\n", ++caseno, fn[n]% 10000007);
    }
}
