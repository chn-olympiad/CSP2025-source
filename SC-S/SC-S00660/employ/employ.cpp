#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, a[510], c[510], p[510], ans;
bool st[510];
void dfs(int step) {
	if(step == n + 1) {
		int cnt = 0;//录入人数
		int cntt = 0;//拒绝人数 
		for(int i = 1; i <= n; ++ i) {
			if(cntt >= c[p[i]]) {
				cntt ++;
				continue;
			}
			if(a[i] == 1) cnt ++;
			else cntt ++;
		}if(cnt >= m) ans ++, ans %= mod;
		return ;		
	}for(int i = 1; i <= n; ++ i) {
		if(!st[i]) {
			p[step] = i;
			st[i] = 1;
			dfs(step + 1);
			st[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool stt = 1;
	for(int i = 1; i <= n; ++ i) {
		char c;
		cin >> c;
		a[i] = c - '0';
		if(a[i] != 1) stt = 0;
	}for(int i = 1; i <= n; ++ i) {
		cin >> c[i];
	}
	dfs(1);
	cout << ans % mod;
}
//