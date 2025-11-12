#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100010;
int n,m,ans,vis[MAXN],num[MAXN],c[MAXN],s[MAXN];
string str;

bool check() {
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (cnt >= c[num[i]] || s[i] == 0) cnt += 1;
	}
	return n - cnt >= m;
}

void dfs(int now) {
	if (now == n + 1) {
		if (check()) ans += 1;
		return ; 
	}
	for (int i = 1;i <= n;i++) {
		if (vis[i] == 1) continue;
		num[now] = i;
		vis[i] = 1;
		dfs(now + 1);
		vis[i] = 0;
		num[now] = 0;
	}
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>str;
	for (int i = 1;i <= n;i++) s[i] = str[i - 1] - '0';
	for (int i = 1;i <= n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
