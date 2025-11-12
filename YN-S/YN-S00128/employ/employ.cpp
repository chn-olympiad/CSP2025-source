#include <bits/stdc++.h>
#define maxn 550
#define mod 998244353
using namespace std;
int n, m;
string s;
int c[550];

long long A(int n, int m) {
	long long ret = 1;
	for (int i = n - m + 1; i <= n; i++) {
		ret = (ret * i) % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << A(n, m);
	return 0;
}