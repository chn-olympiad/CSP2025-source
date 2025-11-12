#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[100005];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int aaa=0;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		if(c[i] != 0) aaa++;
	}
	if(m > n - aaa) {
		cout << 0 << '\n';
		return 0;
	}
	long long res = 1;
	for(int i = 1; i <= n; i++) {
		res = res * i % mod;
	}
	cout << res << '\n';
	return 0;
}
