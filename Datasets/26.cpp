#include <algorithm>

using namespace std;

int d[maxN][11];
vii adj[maxN], adj2[maxN];

int dijkstra() {
	rep(i, n) fr(j, 0, r) d[i][j] = INF;
	set<iii> heap;
	d[0][0] = 0;
	heap.insert(mp(0, mp(0, 0)));
	while (!heap.empty()) {
		iii top = *heap.begin(); heap.erase(top);
		int u = top.ss.ff, k = top.ss.ss;
		if (u == n - 1) return d[u][k];
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (d[u][k] + w < d[v][k]) {
				if (d[v][k] != INF) heap.erase(mp(d[v][k], mp(v, k)));
				d[v][k] = d[u][k] + w;
				heap.insert(mp(d[v][k], mp(v, k)));
			}
		}
		if (k == r) continue;
		rep(i, adj2[u].size()) {
			int v = adj2[u][i].ff, w = adj2[u][i].ss;
			if (d[u][k] + w < d[v][k + 1]) {
				if (d[v][k + 1] != INF) heap.erase(mp(d[v][k + 1], mp(v, k + 1)));
				d[v][k + 1] = d[u][k] + w;
				heap.insert(mp(d[v][k + 1], mp(v, k + 1)));
			}
		}
	}
	return -1;
}

int main() {
//	#ifndef ONLINE_JUDGE
//	freopen("test.inp", "r", stdin);
//	//freopen("test.out", "w", stdout);
//	#endif
	int cases, caseNo = 0, m, k, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d %d", &n, &m, &k, &r);
		rep(i, n) adj[i].clear(), adj2[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
		}
		while (k--) {
			scanf("%d %d %d", &u, &v, &w);
			adj2[u].pb(ii(v, w));
		}
		int res = dijkstra();
		printf("Case %d: ", ++caseNo);
		if (res == -1) puts("Impossible");
		else printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
