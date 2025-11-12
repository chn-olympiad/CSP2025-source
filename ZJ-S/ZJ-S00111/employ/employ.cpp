#include <bits/stdc++.h>
#define N 1000
#define MOD 998244353ll
#define ll long long
using namespace std;
int seq[N], n, m, a[N];
ll ans;
string str;
bool vis[N];
void dfs(int k) {
	if(k == n) {
		int tmp=0, cnt=0;
		for(int i=0 ; i<n ; i++) {
			if(cnt >= a[seq[i]]) {
				cnt ++;
				continue;
			} if(str[i] == '1') tmp++;
			else cnt ++;
		} if(tmp >= m) ans = (ans + 1) % MOD;
		return;
	}
	for(int i=0 ; i<n ; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			seq[k] = i;
			dfs(k+1);
			vis[i] = 0;
		}
	}
}
ll A(int n, int m) {
	ll tmp = 1;
	for(int i=n ; i>=m ; i--) tmp = (tmp * i) % MOD;
	return tmp;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cin >> str;
	int tt=0;
	bool SubtaskA = 1;   //
	for(int i=0 ; i<n ; i++) {
		if(str[i] == '0') {
			SubtaskA = 0;
			break;
		}
	}
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		if(!a[i]) SubtaskA = 0, tt++;
	}
	if(m == 1 && n > 12) {
		for(int p=0 ; p<n ; p++) {
			if(!a[p]) continue;
			ll tmp=0;
			for(int i=0 ; i<=a[p] ; i++) {
				tmp = (tmp + A(tt, i) * A(tt, tt-i) % MOD) % MOD;
			}
			ans = max(ans, A(n, n) * tmp % MOD * A(n-1-tt, n-1-tt) % MOD * A(tt+2, n-1-tt) % MOD);
		}
	} else if(SubtaskA) {
		ans = 1;
		for(int i=1 ; i<=n ; i++) {
			ans = (ans * i) % MOD;
		}
	} else dfs(0);
	printf("%lld", ans);
	return 0;
}
