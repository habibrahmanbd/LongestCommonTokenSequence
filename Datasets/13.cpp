using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    sf("\n");
    for(ll cs=1; cs<=t; cs++)
    {
        char str1[105],str2[105];
        gets(str1);
        gets(str2);
        ll a[26]={0},b[26]={0};
        for(ll i=0; i<strlen(str1); i++)
        {
            if(str1[i]==' ')
                continue;
            else
            {
                a[tolower(str1[i])-'a']++;
            }
        }
        for(ll i=0; i<strlen(str2); i++)
        {
            if(str2[i]==' ')
                continue;
            else
            {
                b[tolower(str2[i])-'a']++;
            }
        }
        bool flag=0;
        for(ll i=0; i<26; i++)
        {
            if(b[i]<=a[i])
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            pf("Case %lld: No\n",cs);
        }
        else
            pf("Case %lld: Yes\n",cs);
    }
    return 0;
}
