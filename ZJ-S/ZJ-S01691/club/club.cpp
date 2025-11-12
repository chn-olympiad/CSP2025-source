#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int T,n;
LL ans;
int a[N][5];

void dfs(int j,int i,LL cnt,int a1,int b,int c) {
	if(i == n + 1) {
		ans = max(cnt,ans);
	}
	for(int k = 1;k <= 3;k ++) {
		if(a1 == n / 2 && k == 1) continue;
		if(b == n / 2 && k == 2) continue;
		if(c == n / 2 && k == 3) continue;
		dfs(k,i + 1,cnt + a[i][j],a1 + (k == 1),b + (k == 2),c + (k == 3));
	}
}

void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= 3;j ++) {
			cin >> a[i][j];
		}
	}
	ans = 0;
	dfs(1,1,0,1,0,0);
	LL ans1 = ans;
	ans = 0;
	dfs(2,1,0,0,1,0);
	LL ans2 = ans;
	ans = 0;
	dfs(3,1,0,0,0,1);
	//cout << ans1 << ' ' << ans2 << ' ' << ans << endl;
	cout << max(max(ans1,ans2),ans) << endl;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --) solve();
	return 0;
}
