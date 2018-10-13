using namespace std;

#include <bits/stdc++.h>

int main()
{
    int T=II;
    int cs=1;
    while(T--)
    {
        char s1[11];
        sf("%s",s1);
        int i;
        int p=strlen(s1);
        OC(cs++);
        for(i=0; i<(p/2); i++)
        {
            if(s1[p-i-1]!=s1[i])
            {
                pf("No\n");
                break;
            }
        }
        if(i>=(p/2))
            pf("Yes\n");
    }
    return 0;
}
