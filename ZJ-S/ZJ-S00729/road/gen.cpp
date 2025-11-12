#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie() -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= r; i++)
#define R(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e4 + 4;

int n = 1e4, m = 1e6, k = 10, V = 1e9;

mt19937 seed(random_device{}());
int rand(int l, int r) {
	return uniform_int_distribution < int >(l, r)(seed);
}

int main() {
	qio(), cout << n << ' ' << m << ' ' << k << '\n';
	L(i, 2, n) cout << rand(1, i - 1) << ' ' << i << ' ' << rand(0, V) << '\n';
	L(i, n, m) {
		int u = rand(1, n - 1), v = rand(u + 1, n), w = rand(0, V);
		cout << u << ' ' << v << ' ' << w << '\n';
	}
	L(i, 1, k) {
		cout << rand(1, V) << ' ';
		L(j, 1, n) cout << rand(1, V) << " \n"[j == n];
	}
	return 0;
}
