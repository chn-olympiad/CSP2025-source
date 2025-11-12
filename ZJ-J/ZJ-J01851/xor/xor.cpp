#include <bits/stdc++.h>
//#inlcude <bits\stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], n, k, ans, lc = 0, fx = 0;
unordered_map<int, vector<int>> mp;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ )	cin >> a[i];
	mp[0].emplace_back(0);
	for (int i = 1; i <= n; i ++ ) {
		fx ^= a[i];
		if (mp.count(fx ^ k)) {
			if (mp[fx ^ k].back() >= lc) {
				ans ++ ;
				lc = i;
			}
		}
		mp[fx].emplace_back(i);
	}
	cout << ans << '\n';
	return 0;
}
//ni bei pian le
/*
20min我把前三题过了，今年J组太水了，谢谢CCF 
*/
