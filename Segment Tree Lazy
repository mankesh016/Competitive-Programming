
class Seg {
	int n;
	vector<long long> seg;
	vector<long long> lazy;
public:
	Seg(int n) {
		this->n = n;
		seg.resize(4 * n);
		lazy.resize(4 * n, 0);
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

	void push(int left, int right, int node) {
		if (lazy[node] != 0) {
			int mid = (left + right) / 2;
			seg[2 * node + 1] += lazy[node] * (mid - left + 1);
			lazy[2 * node + 1] += lazy[node];

			seg[2 * node + 2] += lazy[node] * (right - mid);
			lazy[2 * node + 2] += lazy[node];

			lazy[node] = 0;
		}
	}

	void update(int left, int right, int node, int l, int r, int delta) {
		if (right < l || r < left) return;
		if (l <= left && right <= r) {
			seg[node] += delta * (right - left + 1);
			lazy[node] += delta;
			return;
		}

		push(left, right, node);
		int mid = (left + right) / 2;
		update(left, mid, 2 * node + 1, l, r, delta);
		update(mid + 1, right, 2 * node + 2, l, r, delta);

		seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
	}

	long long query(int left, int right, int node, int l, int r) {
		if (right < l || r < left) return 0;
		if (l <= left && right <= r) return seg[node];

		push(left, right, node);
		int mid = (left + right) / 2;
		long long q1 = query(left, mid, 2 * node + 1, l, r);
		long long q2 = query(mid + 1, right, 2 * node + 2, l, r);

		return q1 + q2;
	}

	long long query(int l, int r) {
		return query(0, n - 1, 0, l, r);
	}
	void update(int l, int r, int delta) {
		update(0, n - 1, 0, l, r, delta);
	}
	void build(vector<int> &a) {
		build(0, n - 1, 0, a);
	}
};
