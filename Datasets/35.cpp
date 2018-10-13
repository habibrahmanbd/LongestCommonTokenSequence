
#include <algorithm>
using namespace std;


int n, m, a[maxN];
int x[maxN * 6], y[maxN * 6], z[maxN * 6];

void build(int p, int lo, int hi)
{
    if (lo == hi)
    {
        x[p] = 1;
        a[lo] = y[p] = z[p] = 0;
        return;
    }
    int mid = (lo + hi) >> 1, c = p << 1;
    build(c, lo, mid);
    build(c + 1, mid + 1, hi);
    x[p] = x[c] + x[c + 1];
}

void update(int p, int lo, int hi, int u, int v)
{
    if (hi < u || v < lo) return;
    int mid = (lo + hi) >> 1, c = p << 1;
    if (u <= lo && hi <= v)
    {
    }
    update(c, lo, mid, u, v);
    update(c + 1, mid + 1, hi, u, v);
    x[p] = x[c] + x[c + 1];
    y[p] = y[c] + y[c + 1];
    z[p] = z[c] + z[c + 1];
}

int get(int p, int lo, int hi, int u, int v)
{
    if (hi < u || v < lo) return 0;
    if (u <= lo && hi <= v) return x[p];
    int mid = (lo + hi) >> 1, c = p << 1;
    return get(c, lo, mid, u, v) + get(c + 1, mid + 1, hi, u, v);
}

int main()
{
//////#ifndef ONLINE_JUDGE
//////    freopen("test.inp", "r", stdin);
//////    //freopen("test.out", "w", stdout);
//////#endif
    int cases, caseNo = 0, q, u, v;
    for (scanf("%d", &cases); cases--; )
    {
        scanf("%d %d", &n, &m);
        build(1, 0, n - 1);
        printf("Case %d:\n", ++caseNo);
        while (m--)
        {
            scanf("%d %d %d", &q, &u, &v);
            if (!q) update(1, 0, n - 1, u, v);
            else printf("%d\n", get(1, 0, n - 1, u, v));
        }
    }
    return 0;
}
