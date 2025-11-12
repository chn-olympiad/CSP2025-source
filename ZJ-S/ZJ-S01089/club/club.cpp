#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100010;
int t,n,ans,a[MAXN][3],cnt[3],b[MAXN];

void dfs(int now,int sum) {
	if (now == n + 1) {
		ans = max(ans,sum);
		return ;
	}
	for (int i = 0;i < 3;i++) {
		if (cnt[i] >= n / 2) continue;
		cnt[i] += 1;
		sum += a[now][i];
		dfs(now + 1,sum);
		cnt[i] -= 1;
		sum -= a[now][i];
	}
}

bool check() {
	for (int i = 1;i <= n;i++) {
		if (a[i][1] != 0 || a[i][2] != 0) return false;
	}
	return true;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i = 1;i <= n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		memset(cnt,0,sizeof(cnt));
		ans = 0;
		if (n <= 20) dfs(1,0);
		else if (check()) {
			for (int i = 1;i <= n;i++) b[i] = a[i][0];
			sort(b + 1,b + n + 1);
			for (int i = n / 2 + 1;i <= n;i++) ans += b[i];
		}
		else {
			for (int i = 1,x,y,z;i <= n;i++) {
				x = a[i][0],y = a[i][1],z = a[i][2];
				ans += max(x,max(y,z));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}