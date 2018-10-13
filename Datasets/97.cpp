
#include<bits/stdc++.h>
using namespace std;

void process()
{
    int sqrtN, i;
    i64 res;

    sqrtN = (int)sqrt((double)n) + 1;
    res = 1;
    for(i=0; pr[i]<=sqrtN; i++) if(!(n % pr[i]))
        {
            i64 cnt = 0;
            while(!(n % pr[i]))
            {
                cnt++;
                n /= pr[i];
            }
            res = ( res * ( bigMod( pr[i], cnt * m + 1, MOD ) + MOD - 1 ) ) % MOD;
            res = ( res * modularInverse( pr[i] - 1, MOD ) ) % MOD;
        }
    if(n > 1)
    {
        res = ( res * ( bigMod( n, m + 1, MOD ) + MOD - 1 ) ) % MOD;
        res = ( res * modularInverse( n - 1, MOD ) ) % MOD;
    }
    printf("Case %d: %d\n",++caseno, (int)res);
}

int main()
{
    sieve();
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&n,&m);
        process();
    }
    return 0;
}
