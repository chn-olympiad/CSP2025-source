#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int MOD = 998244353;

int n, m;
int c[N];
string s;

long long jc(int n) {
	long long sum = 1;
	for(int i = 2; i <= n; ++ i)
		sum = sum * i % MOD;
	return sum;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; ++ i)
		cin >> c[i];
	cout << (jc(n) * jc(m) % MOD) << "\n";
	return 0;
}
