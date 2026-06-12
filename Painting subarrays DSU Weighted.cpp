/*
We have a segment of length L, each element initially has the color 0. 
We have to repaint the subarray [l, r]  with the color c for each query (l, r, c). 
At the end we want to find the final color of each cell. 
We assume that we know all the queries in advance, i.e. the task is offline.
n, q
q queries
Input:
7 5
2 5 1
3 6 2
4 5 3
1 2 4
2 4 5
Output:
4 5 5 5 3 2 0

*/
// Code!


#define int long long
const int N = 2e5 + 5;

struct Query {
	int l, r, c;
};


class Dsu {
	vector<int> par, sz, last;
public:
	Dsu(int n) {
		sz.assign(n + 1, 1);
		par.resize(n + 1);
		iota(par.begin(), par.end(), 0);
		last.resize(n + 1);
		iota(last.begin(), last.end(), 0);
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	int giveLast(int x) {
		x = find(x);
		return last[x];
	}

	bool unite(int x, int y) {

		x = find(x);
		y = find(y);
		if (x == y) return false;

		if (sz[x] > sz[y]) swap(x, y);

		last[y] = max(last[y], last[x]); // rightmost position
		par[x] = y;
		sz[y] += sz[x];

		return true;
	}
	// If we represent leader as rightmost position,
	// we not use Union by size, complexity O(logN) per union (which is fast enough)
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		int n, q; cin >> n >> q;

		vector<Query> queries;
		while (q--) {
			int l, r, c; cin >> l >> r >> c;
			queries.push_back({l, r, c});
		}

		Dsu dsu(n + 1);

		vector<int> col(n + 1);
		for (int i = queries.size() - 1; i >= 0; i--) {
			int l = queries[i].l, r = queries[i].r, c = queries[i].c;
			// each component contains rightmost unclored position
			// 0 [5 5 5 0] 0 0 [2 0] 0 0 like that
			for (int x = dsu.giveLast(l); x <= r; x = dsu.giveLast(x)) {
				col[x] = c;
				dsu.unite(x, x + 1);
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << col[i] << " ";
		}
		cout << "\n";
	}
}
