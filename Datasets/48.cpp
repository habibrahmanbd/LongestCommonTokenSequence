
#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;

#define MAX_N 1000004
//long long c=0;
char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;


void kmpPreprocess()
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}
int match=0;
void kmpSearch()
{
    int i = 0, j = 0;
//    c=0;
    while (i < n)
    {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        i++;
        j++;
//        if (j == m)
//        {
//            c++;
//            j = b[j];
//        }
    }
    match=j;
}

int main()
{
    int test;
    scanf("%d",&test);
    int ss=1;
    while(test--)
    {
        scanf("%s",T);
//        scanf("%s",P);
        n = (int)strlen(T);
        int j=0;
        for(int i=n-1; i>=0; i--)
            P[j++]=T[i];
        P[j]='\0';
        m = n;
        kmpPreprocess();
//        c=0;
        kmpSearch();
        printf("Case %d: %d\n",ss++,2*n-match);
    }
    return 0;
}

/*
Special Thanks to "Rafi Kamal, BUET 10" brother for his nice support pushing the solution to GITHUB
*/
