// kai bai!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int re = 1;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(x != 0)
		re *= x;
		re %= 998244353;
	}
	cout << re;
	return 0;
}