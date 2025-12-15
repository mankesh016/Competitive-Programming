const int N = 2e5 + 5;
const int LG = 18;

int spt[LG][N];
int lg[N];

void build(vector<int> &a) {
	lg[1] = 0;
	for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;

	int n = s.size();
	for (int i = 0; i < n; i++) {
		spt[0][i] = a[i];
	}
	for (int k = 1; k < LG; k++) {
		for (int i = 0; i + (1 << k) <= n; i++) {
			spt[k][i] = min(spt[k - 1][i], spt[k - 1][i + (1 << k - 1)]);
		}
	}
}

int query(int l, int r) {
	int k = lg[r - l];
	return min(spt[k][l], spt[k][r - (1 << k)]);
}

int querySum1(int l, int r) {
	int sum = 0;
	for (int k = lg[r - l]; k >= 0; k--) {
		if ((1 << k) <= r - l) {
			sum += spt[k][l];
			l += (1 << k);
		}
	}
	return sum;
}

int querySum2(int l, int r) {
	int sum = 0;
	for (int k = lg[r - l]; l < r; k = lg[r - l]) {
		sum += spt[k][l];
		l += (1 << k);
	}
	return sum;
}


int querySum3(int l, int r) {
	int sum = 0;
	int len = r - l;

	for (int k = lg[r - l]; k >= 0; k--) {
		if (len & (1 << k)) {
			sum += spt[k][l];
			l += (1 << k);
		}
	}
	return sum;
}

// build(a)
// query(l,r) // zero base indexing
