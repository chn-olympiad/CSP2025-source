#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int a[N][10];
int n;
int b[N], d[N], e[N];
bool cmp(int x, int y){
	return x > y;
}
void solve(){
	memset(b, 0, sizeof b);
	memset(d, 0, sizeof d);
	memset(e, 0, sizeof e);
	cin >> n;
	int m = 0, ans = 0;
	for(int i = 1; i <= n; i ++){
		int mx = 1, mn = 1;
		for(int j = 1; j <= 3; j ++){
			scanf("%lld", &a[i][j]);
			if(a[i][j] > a[i][mx]) mx = j;
		//	if(a[i][j] > a[i][mn]) mn = j;
		}
		b[i] = mx;
	//	c[i] = mn;
		ans += a[i][mx];
		d[b[i]] ++;
	}
//	cout << ans << endl ;
	int mx = 1;
	for(int i = 1; i <= 3; i ++){
		if(d[i] > d[mx]) mx = i; 
	}
	
	for(int i = 1; i <= n; i ++){
		if(b[i] != mx) continue;
		int c = -1e18;
		for(int j = 1; j <= 3; j ++){
			if(b[i] != j)
			c = max(c, a[i][j] - a[i][b[i]]);
		}
		e[++ m] = c;
		 
	}
	sort(e + 1, e + m + 1, cmp);
//	for(int i = 1; i <= m; i ++) cout << e[i] << " " ; cout << endl ;
	if(d[mx] <= n / 2) {
		printf("%lld\n", ans);
		return ;
	}
	for(int i = 1; i <= d[mx] - n / 2; i ++) ans += e[i];
	printf("%lld\n", ans);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t --) solve();	
	return 0;
}
