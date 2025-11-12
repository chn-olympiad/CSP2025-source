#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m, c[N], a[N];
string str;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> str;
	str = " " + str;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	} 
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}
	int ans = 0;
	do {
		int tot = 0, no = 0;
		for (int i = 1; i <= n; ++i) {
//			cout << c[a[i]] << ' ';
//			cout << no << ' ';
			if(no < c[a[i]] && str[i] == '1') ++ tot;
			else ++ no;
//			cout << tot << '\n';
		}
		if(tot >= m) ++ ans;
//		cout << '\n';
	} while(next_permutation(a + 1, a + n + 1));
	cout << ans << '\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
