
struct Node {
	long long pref, suf, ans, sum;
	Node() {
		sum = 0;
		pref = suf = ans = -1e18;
	}

	Node(int val) {
		sum = val;
		pref = suf = ans = val;
	}
};

Node merge(Node &a, Node &b) {
	Node res;
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum + b.pref);
	res.suf = max(b.suf, b.sum + a.suf);
	res.ans = max({a.ans, b.ans, a.suf + b.pref});
	return res;
}


class Seg {
	int n;
	vector<Node> seg;
public:
	Seg(int n) {
		this->n = n;
		seg.resize(4 * n);
	}

	void build(int left, int right, int node, vector<int> &a) {
		if (left == right) {
			seg[node] = Node(a[left]);
			return;
		}

		int mid = (left + right) / 2;
		build(left, mid, 2 * node + 1, a);
		build(mid + 1, right, 2 * node + 2, a);

		seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
	}
	void update(int left, int right, int node, int idx, int val) {
		if (left == right) {
			seg[node] = Node(val); return;
		}

		int mid = (left + right) / 2;
		if (idx <= mid) update(left, mid, 2 * node + 1, idx, val);
		else update(mid + 1, right, 2 * node + 2, idx, val);

		seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
	}
	Node query(int left, int right, int node, int l, int r) {
		if (right < l || r < left) return Node(); // identity element
		if (l <= left && right <= r) return seg[node];

		int mid = (left + right) / 2;
		Node q1 = query(left, mid, 2 * node + 1, l, r);
		Node q2 = query(mid + 1, right, 2 * node + 2, l, r);

		return merge(q1, q2);
	}
	long long query(int l, int r) {
		return query(0, n - 1, 0, l, r).ans;
	}
	void update(int idx, int val) {
		update(0, n - 1, 0, idx, val);
	}
	void build(vector<int> a) {
		build(0, n - 1, 0, a);
	}
};
