#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[4][N], cnt1, cnt2, cnt3, ans, sum1, sum2, sum3;
int n;
struct Node{
	int a, b, c;
} b[N];
void dfs(int i){
	if(i == n + 1){
		ans = max(sum1 + sum2 + sum3, ans);
		return ;
	}
	if(cnt1 < n / 2) sum1 += a[1][i], cnt1++, dfs(i + 1), cnt1--, sum1 -= a[1][i];
	if(cnt2 < n / 2) sum2 += a[2][i], cnt2++, dfs(i + 1), cnt2--, sum2 -= a[2][i];
	if(cnt3 < n / 2) sum3 += a[3][i], cnt3++, dfs(i + 1), cnt3--, sum3 -= a[3][i];
	return ;
}
void solve(){
	cnt1 = cnt2 = cnt3 = ans = sum1 = sum2 = sum3 = 0;
	cin >> n;
	bool flag = 1, flag2 = 1;
	for(int i = 1; i <= n; ++i){
		cin >> a[1][i] >> a[2][i] >> a[3][i];
		flag &= a[2][i] == 0 && a[3][i] == 0;
		flag2 &= a[3][i] == 0;
	}
	if(flag){
		sort(a[1] + 1, a[1] + n + 1, greater <int> ());
		for(int i = 1; i <= n / 2; ++i) ans += a[1][i];
		cout << ans << '\n';
	} else if(flag2){
		for(int i = 1; i <= n; ++i) b[i].a = a[1][i], b[i].b = a[2][i], b[i].c = a[3][i];
		sort(b + 1, b + n + 1, [](Node x, Node y){
			return x.a == y.a ? x.b > y.b : x.a > y.a;
		});
		for(int i = 1; i <= n; ++i){
			if(b[i].a > b[i].b){
				if(cnt1 < n / 2) cnt1++, ans += b[i].a;
				else cnt2++, ans += b[i].b;
			} else {
				if(cnt2 < n / 2) cnt2++, ans += b[i].b;
				else cnt1++, ans += b[i].a;
			}
		}
		cout << ans << '\n';
	} else dfs(1), cout << ans << '\n';
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
