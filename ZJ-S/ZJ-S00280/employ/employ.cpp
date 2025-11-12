#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)

using namespace std;

int n, m;
string s;
const int N = 10005;
int a[N], ans, vis[N];
void dfs(int d, int cnt) {
	if(d == n + 1) {
		if(n - cnt >= m) 
			++ ans;
		return ;
	}
	rep(i, 1, n) {
		if(vis[i] == 0) {
			vis[i] = 1;
			
			if(s[d] == '1') {
				if(cnt >= a[i]) {
					dfs(d + 1, cnt + 1);
				}
				else dfs(d + 1, cnt);	
			} else {
				dfs(d + 1, cnt + 1);
			}
			
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = '#' + s;
	rep(i, 1, n) cin >> a[i];
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}

