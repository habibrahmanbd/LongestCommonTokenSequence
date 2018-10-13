
#include <algorithm>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, w, k, y[maxN], f[maxN][maxN];

int solve() {
    fill(f, 0);
    REP(i, n - 1) {
        REP(j, k) {
            if (i)
                f[i][j] = max(f[i][j], f[i - 1][j]);
            int t = i;
            while (y[t] <= y[i] + w)
                t++;
            f[t][j + 1] = max(f[t][j + 1], f[i][j] + t - i);
        }
    }
    int res = 0;
    REP(i, n) REP(j, k + 1)
        res = max(res, f[i][j]);
    return res;
}

int main() {
//    #ifndef ONLINE_JUDGE
//        inpFile("test.inp"); //outFile("test.out");
//    #endif
    int caseNo, cases = 0, garbage;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d %d ", &n, &w, &k);
        REP(i, n)
            scanf("%d %d", &garbage, &y[i]);
        sort(y, y + n);
        y[n++] = INF;
        printf("Case %d: %d\n", ++cases, solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
