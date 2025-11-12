#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 505;
int m, n, cnt;
int a[N];
int per[N], vis[N];
string s;
void dfs(int now) {
	if(now == n + 1) {
//		for(int i = 1; i <= n; i++) {
//			cout << per[i] << " ";
//		}
//		cout << endl;
		int ans = 0, now1 = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i - 1] == '0') {
				now1++;
			} else {
				if(now1 >= a[per[i]]) {
					now1++;
				}
				else {
					ans++;
				}
			}
//			cout << now1 << " " << ans << endl;
		}
		if(ans >= m) {
			cnt++;
//			cout << "ok" << endl;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		per[now] = i;
		vis[i] = 1;
		dfs(now + 1);
		vis[i] = 0;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << cnt << endl;
	return 0;
}

/*
3 2
101
1 1 2



10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
