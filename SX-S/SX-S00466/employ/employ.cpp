#include <bits/stdc++.h>
using namespace std;
long long n, m, a[550], ans = 1, chushu = 1, beichu = 1;
string s;

int main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n - m; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			ans = ans * (i / j);
		}
	}
	cout << ans;
	return 0;

}