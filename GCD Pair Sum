#include<bits/stdc++.h>
using namespace std;

#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif

// https://www.spoj.com/problems/GCDEX/
// G = 0;
// for (i = 1; i < N; i++)
//   for (j = i+1; j <= N; j++)
//     G += gcd(i, j);

// ignore i==j
// j>i

#define int long long
const int N = 1e6 + 5;

int phi[N], fun[N], ans[N];
void calc_phi() {
	for (int i = 0; i < N; i++) phi[i] = i;

	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (int j = i; j < N; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}
// N loglogN

void calc_fun() {
	// d|n => fun[n]+= d * phi[n/d]
	for (int i = 1; i < N; i++) {
		for (int j = 2 * i; j < N; j += i) {
			fun[j] += i * phi[j / i];
		}
	}
}

void pre() {
	// G(n) = G(n-1) + f(i,n)
	// f(i,n)
	// gcd can be d -> if d divides n,
	// #ways for gcd d => gcd(i, n/d) = 1

	ans[0] = 0;
	for (int i = 1; i < N; i++) {
		// ans[i]= ans[i-1] + f(i-1, i)
		ans[i] = ans[i - 1] + fun[i];
	}
}

// 11 Dec 2025
// Euler totient function
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		calc_phi();
		calc_fun();
		pre();

		// GCD Pair Sum(N,N)

		int n;
		while (cin >> n && n) {
			cout << ans[n] << "\n";
		}



	}
}
