using namespace std;
#include<bits/stdc++.h>

ll f[6];
int main()
{
    ios_base::sync_with_stdio(0);
    f[0]=1,f[1]=1,f[2]=2,f[3]=6,f[4]=24,f[5]=120;
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n,k;
        cin>>n>>k;
//        cout<<fact[n]<<endl;
        char arr[n+1];
        for(ll i=0; i<n; i++)
            arr[i]='A'+i;
//        arr[n]='\0';
        ll to;
        if(n<=5)
            to=min(k,f[n]);
        else
            to=k;
//        cout<<to<<endl;
        cout<<"Case "<<cs<<":\n";
        for(ll i=1; i<=to; i++)
        {
            for(ll j=0; j<n; j++)
            cout<<arr[j];
            cout<<endl;
            next_permutation(arr,arr+n);
        }
    }
    return 0;
}
