/*******************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib        *
*   Dept. of CSE, RUET          *
*   habib_cse_ruet@yahoo.com  *
********************************/

using namespace std;

#include <bits/stdc++.h>
//type def
#define PI 2*acos (0.0)
typedef long long int64;
typedef unsigned long long int64u;
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define MAX(p,q) p>q?p:q
#define MIN(p,q) p<q?p:q
#define MOD 100000007
#define INF 1<<29
//Intput_Output
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define pf printf
#define sf scanf
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ long a; scanf("%ld",&a);  a;})  //Long Integer Input
#define ILL ({ int64 a; scanf("%I64d",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %d: ",cs);  //Case Input
//Loops.....
#define f(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define fr(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
int main()
{
    int t=II;
    int cs=1;
    while(t--)
    {
        int Ox=II, Oy=II, Ax=II, Ay=II, Bx=II, By=II;
        db rad     = sqrt((db)((Ox-Ax)*(Ox-Ax))+(db)((Oy-Ay)*(Oy-Ay)));
        db AB      = sqrt((db)((Bx-Ax)*(Bx-Ax))+(db)((By-Ay)*(By-Ay)));
        db angle   = acos(1.0 - 0.5 * pow((AB/rad),2));
        db arc     = rad * angle ;
        OC(cs++);
        pf("%lf\n",fabs(arc));
    }
    return 0;
}
