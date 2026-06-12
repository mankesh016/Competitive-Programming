#include<bits/stdc++.h>
using namespace std;

#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif

// ICPC 2024, Amritapuri Regionals
// Problem E, Difficulty Order 7
// Expected Rain
// Expected values

// Problem Description
// There are N buildings on a 1-D line. The i-th building spans from x-coordinate (i − 1) to
// x-coordinate i, and has a height of Hi
// When rain falls, water gets collected between the buildings. There are no buildings to the left
// of x = 0 or to the right of x = N, and so no water gets collected there.
// Let f(H) denote the amount of rain collected.
// Unfortunately, you only remember the N heights, but not the order in which they were present.
// Find the expected value of f(H) over all possible permutations of H.
// The expected value must be computed modulo 998244353.


#define int long long
const int N = 2e5 + 5;
const int mod = 998244353;

int fast_pow(int x, int p) {
	if (p == 0 ) return 1;

	int ans = fast_pow((1ll * x * x) % mod, p / 2) % mod;

	if (p & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int TC; cin >> TC; while (TC--)
	{
		int n; cin >> n;

		vector<int> a(n);
		for (auto &x : a)cin >> x;

		sort(a.begin(), a.end());

		int total_water = 0;
		// Think of horizontal contribution!
		for (int i = 0; i + 2 < n; i++) {
			int wall = n - (i + 1);
			int gap = i + 1;
			int delta = a[i + 1] - a[i];

			if (delta == 0) continue;
			// delta * small_building * (good_regions/total_regions)
			// delta * small_building * (walls-1)/(walls+1)

			int here = delta * gap * (wall - 1) % mod * fast_pow(wall + 1, mod - 2) % mod;
			total_water = (total_water + here) % mod;
		}

		cout << total_water << "\n";
	}
}
