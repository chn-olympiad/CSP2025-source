#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m ;
	cin >> s;
	int nn = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			nn--;
	}
	long long cnt = 1;
	if (nn < m) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= nn; i++) {
		cout << cnt << '\n';
		cnt *= i;
		cnt %= 998244353;
	}
	cout << cnt % 998244353 ;
	return 0;
}

