#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
string s;
int c[505], su[505], k[505];
bool vis[505];
bool dis[505];

void dfs(int now, int depth) {
	k[depth] = now;
	vis[now] = 1;
	if (depth == n) {
		int total = 0, tots = 0;
		for (int i = 1;i <= n; ++i) {
			if (s[k[i]] == '1' || tots >= c[k[i]]) continue;
			tots += s[k[i]] - '0'; ++total;
		} if (total >= m) ++ ans;
	}
	else {
		for (int i = 1;i <= n; ++i) {
			if (!vis[i]) {
				dfs(i, depth + 1);
				vis[i] = 0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n; ++i) {
		cin >> c[i];
	}
	
	if (m == n) {
		int flag = 1;
		for (int i = 0;i < s.length(); ++i) if (s[i] == '1') {
			flag= 0; break;
		} if (flag) {
			long long rans = 1;
			for (int i = 1;i <= n; ++i) {
				rans *= i;
				rans %= 998244353;
			} cout << rans;
		}
		else cout << 0;
	} else {
		int flag = 1;
		for (int i = 0;i < s.length(); ++i) if (s[i] == '0') {
			flag= 0; break;
		} if (flag) {
			long long rans = 1;
			for (int i = 1;i <= n; ++i) {
				rans *= i;
				rans %= 998244353;
			} cout << rans;
		}
		else {
			for (int i = 1;i <= n; ++i) {
				dfs(i, 1);
			} cout << ans;
		}
	}
	return 0;
}