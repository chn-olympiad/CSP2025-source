#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 10;
const int mod = 998244353;
int n, m, c[N], nw[N], ans = 0;
string s;
bool vis[N];
void dfs(int step) {
	if(step == n + 1) {
		int fail = 0, lqd = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0' || nw[i + 1] <= fail) fail++;
			else lqd++;
		}
		if(lqd >= m){
			ans++;
		} 
	} else {
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				nw[step] = c[i];
				vis[i] = true;
				dfs(step + 1);
				vis[i] = false;
			}
		} 
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	bool A = true;
	for(int i = 0; i < n; i++) {
		if(s[i] != '1') A = false;
	}
	if(A) {//肯定都能录取，直接计算排列数 (20pts)
		int ans = 1, cnt = 0;
		for(int i = 1; i <= n; i++) if(c[i] != 0) cnt++;
		if(cnt < m) {
			cout << 0 << endl;
		} 
		else {
			for(int i = 2; i <= n; i++) ans = (ans * i) % mod;
			cout << ans << endl;
		}
	} else if(m == 1) {//只需要录取一个，显然第一个人有耐心等过前面的所有0就可以，所以是个数*剩下排列 (12pts)
		int k = 0, cnt = 0, ans = 1;
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') {
				k = i;
				break;
			}
		}
		if(k == 0) {
			cout << 0 << endl;
		}
		else{
			for(int i = 1; i <= n; i++) {
				if(c[i] > k) cnt++;
			}
			for(int i = 2; i <= n - 1; i++) ans = (ans * i) % mod;
			cout << (ans * cnt) % mod << endl;
		}	
	} else {//可爱的爆搜，8pts 
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
//100+(48-64)+25+40=213-229