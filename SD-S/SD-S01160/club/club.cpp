#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N], b[N], c[N], cnt[3], ans;
void dfs(int x, int s){
	if(x == n){
		ans = max(ans, s);
		return;
	}
	if(cnt[0] + 1 <= n / 2){
		cnt[0]++;
		dfs(x + 1, s + a[x + 1]);
		cnt[0]--;
	}
	if(cnt[1] + 1 <= n / 2){
		cnt[1]++;
		dfs(x + 1, s + b[x + 1]);
		cnt[1]--;
	}
	if(cnt[2] + 1 <= n / 2){
		cnt[2]++;
		dfs(x + 1, s + c[x + 1]);
		cnt[2]--;
	}
}
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		bool flag = 1;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0 || c[i] != 0) flag = 0;
		}
		if(flag){
			sort(a + 1, a + 1 + n, cmp);
			for(int i = 1; i <= n / 2; i++) ans += a[i];
			cout << ans << endl;
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		cnt[0] = 1;
		dfs(1, a[1]);
		cnt[0] = 0;
		cnt[1] = 1;
		dfs(1, b[1]);
		cnt[1] = 0;
		cnt[2] = 1;
		dfs(1, c[1]);
		cnt[2] = 0;
		cout << ans << endl;
	}
	return 0;
}
