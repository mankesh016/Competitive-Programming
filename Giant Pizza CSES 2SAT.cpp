#include<bits/stdc++.h>
using namespace std;
 
#ifdef local
#include "algo/debug.h"
#else
#define debug(...)
#endif
 
#define int long long
const int N = 2e5 + 5;
#define endl "\n"
 
vector<int> gr[N], grr[N]; // 2*N
int vis[N], scc[N];
 
// topo order
vector<int> order;
void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) dfs(x);
	}
	order.push_back(cur);
}
 
// SCC in rev graph
void dfs2(int cur, int col) {
	scc[cur] = col;
	for (auto x : grr[cur]) {
		if (!scc[x]) dfs2(x, col);
	}
}
 
 
// if a is false b must be true
// if b is false a must be true
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		int n; cin >> n;
		int m; cin >> m;
 
		// + pick it
		// - drop it
		char ch1, ch2;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> ch1 >> x >> ch2 >> y;
 
			x = 2 * x + (ch1 == '-');
			y = 2 * y + (ch2 == '-');
 
			gr[x ^ 1].push_back(y);
			gr[y ^ 1].push_back(x);
			grr[x].push_back(y ^ 1);
			grr[y].push_back(x ^ 1);
		}
 
		for (int i = 2; i <= 2 * m + 1; i++) {
			if (vis[i] == 0) dfs(i);
		}
		reverse(order.begin(), order.end());
		int col = 1;
		for (int i = 0; i < order.size(); i++) {
			int x = order[i];
			if (scc[x] == 0) dfs2(x, col++);
		}
 
		bool f = true;
		for (int i = 1; i <= m; i++) {
			if (scc[2 * i] == scc[2 * i + 1]) f = false;
		}
		if (f == false) {
			cout << "IMPOSSIBLE" << endl; return 0;
		}
 
		for (int i = 1; i <= m; i++) {
			if (scc[2 * i] > scc[2 * i + 1]) cout << "+ ";
			else cout << "- ";
		}
		cout << endl;
	}
}
