// CSES Problem Set
// Range Queries and Copies
// https://cses.fi/problemset/task/1737/

#include<bits/stdc++.h>
using namespace std;

#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif

#define endl "\n"
#define int long long

const int N = 2e5 + 5;
// PST: 4*N + Q * logN
// 4*2e5 + 2e5 Queries * 18 new Nodes in each Query
// 2e5 *(4+18)

const int MAX_NODES = N * 22;

struct Node {
	int val;
	int l, r;
};

class PST {
	int n;
	vector<Node> tree;
	int cnt;
public:
	vector<int> roots;

	PST(int n) {
		this->n = n;
		tree.resize(MAX_NODES);
		roots.push_back(0);
		cnt = 0;
	}

	int build(int left, int right, vector<int> &a) {
		int node = ++cnt;
		if (left == right) {
			tree[node] = {a[left], 0, 0};
			return node;
		}
		int mid = (left + right) / 2;
		tree[node].l = build(left, mid, a);
		tree[node].r = build(mid + 1, right, a);
		tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
		return node;
	}

	int update(int left, int right, int prev_node, int idx, int val) {
		int node = ++cnt;
		tree[node] = tree[prev_node];

		if (left == right) {
			tree[node].val = val;
			return node;
		}

		int mid = (left + right) / 2;
		if (idx <= mid) {
			tree[node].l = update(left, mid, tree[prev_node].l, idx, val);
		} else {
			tree[node].r = update(mid + 1, right, tree[prev_node].r, idx, val);
		}

		tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
		return node;
	}

	int query(int left, int right, int node, int l, int r) {
		if (r < left || right < l) return 0;
		if (l <= left && right <= r) {
			return tree[node].val;
		}

		int mid = (left + right) / 2;
		int q1 = query(left, mid, tree[node].l, l, r);
		int q2 = query(mid + 1, right, tree[node].r, l, r);
		return q1 + q2;
	}

	void build(vector<int> &a) {
		int root = build(0, n - 1, a);
		roots.push_back(root);
	}

	void update(int prev_version, int idx, int val) {
		int new_root = update(0, n - 1, roots[prev_version], idx, val);
		roots.push_back(new_root);
	}

	void update_version(int k, int idx, int val) {
		roots[k] = update(0, n - 1, roots[k], idx, val);
	}

	int query(int k, int l, int r) {
		return query(0, n - 1, roots[k], l, r);
	}

	void copy(int k) {
		roots.push_back(roots[k]);
	}
};

// 20 dec 2025!!!
// yet to pratice!!!
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		int n; cin >> n;
		int q; cin >> q;

		vector<int> a(n);
		for (auto &x : a)cin >> x;

		PST pst(n);
		pst.roots.push_back( pst.build(0, n - 1, a) );

		while (q--) {
			int type; cin >> type;
			if (type == 1) {
				int k, idx, x; cin >> k >> idx >> x;
				idx--;
				pst.update_version(k, idx, x);
			}
			else if (type == 2) {
				int k, l, r; cin >> k >> l >> r;
				l--; r--;
				cout << pst.query(k, l, r) << endl;
			}
			else {
				int k; cin >> k;
				pst.copy(k);
			}
		}

	}
}
