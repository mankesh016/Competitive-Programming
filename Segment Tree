class Seg {
	int n;
	vector<long long> seg;
public:
	Seg(int n) {
		this->n = n;
		seg.resize(4 * n);
	}

	void build(int left, int right, int node, vector<int> &a) {
		if (left == right) {
			seg[node] = a[left];
			return;
		}

		int mid = (left + right) / 2;
		build(left, mid, 2 * node + 1, a);
		build(mid + 1, right, 2 * node + 2, a);

		seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
	}

	void update(int left, int right, int node, int idx, int val) {
		if (left == right) {
			seg[node] = val; return;
		}

		int mid = (left + right) / 2;
		if (idx <= mid) update(left, mid, 2 * node + 1, idx, val);
		else update(mid + 1, right, 2 * node + 2, idx, val);

		seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
	}

	long long query(int left, int right, int node, int l, int r) {
		if (right < l || r < left) return 0;
		if (l <= left && right <= r) return seg[node];

		int mid = (left + right) / 2;
		long long q1 = query(left, mid, 2 * node + 1, l, r);
		long long q2 = query(mid + 1, right, 2 * node + 2, l, r);

		return q1 + q2;
	}


	long long query(int l, int r) {
		return query(0, n - 1, 0, l, r);
	}
	void update(int idx, int val) {
		update(0, n - 1, 0, idx, val);
	}
	void build(vector<int> &a) {
		build(0, n - 1, 0, a);
	}
};
