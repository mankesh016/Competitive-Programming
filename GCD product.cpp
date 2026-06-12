// https://www.hackerrank.com/contests/w3/challenges/gcd-product/problem
// 11 Dec 2025, 

// Approch:
// Calculate Contribution of each prime. Answer = 2^a * 3^b * 5^c * 7^d 
// We just need to find powers a, b, c ...
// Iterate through prime numbers (2, 3, 5...)
// For each prime, count how many pairs are multiples of p, p^2, p^3 ...
// Add those counts to get the total exponent for that prime.

// power_of_a_prime = (n/p)(m/p) + (n/p^2)(m/p^2) + (n/p^3)(m/p^3) ...

#include<bits/stdc++.h>
using namespace std;

// #define int long long
const int N = 1.5e7 + 5;
const int mod = 1e9 + 7;

bool prime[N];
vector<int> primes;
void pre() {
	for (int i = 2; i < N; i++) prime[i] = 1;
	for (int i = 2; i * i < N; i++) {
		if (prime[i] == 1) {
			for (int j = i * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		if (prime[i]) primes.push_back(i);
	}
}

long long fast_pow(long long x, long long p) {
	if (p == 0 ) return 1;
	long long ans = fast_pow((1ll * x * x) % mod, p / 2) % mod;
	if (p & 1) ans = (1ll * ans * x) % mod;
	return ans;
}

int solve(int n, int m) {
	pre();
	int limit = max(n, m);
	long long prod = 1;
	for (auto p : primes) {
		long long t = p;
		long long pow = 0;
		if (p > limit) break;
		while (t <= n && t <= m) {
			pow += (n / t) * (m / t) % (mod - 1);
			t *= p;
		}
		prod *= fast_pow(p, pow);
		prod %= mod;
	}
	return prod;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		int n, m; cin >> n >> m;
		int product = solve(n, m);
		cout << product << "\n";
	}
}
