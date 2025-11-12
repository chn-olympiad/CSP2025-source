#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N], ans, cnt;
struct info{
	int l, r;
}v[N];
void dfs(int d, int s) {
	if(d > n) {
		ans = max(ans, s);
		return;
	} 
	dfs(d + 1, s);
	int t = a[d];
	if(t == k) {
		dfs(d + 1, s + 1);
		return;
	}
	for(int i = d + 1; i <= n; i ++) {
		t ^= a[i];
		if(t == k) {
			dfs(i + 1, s + 1);
			return;
		}
	}
}// 10
bool cmp(info x, info y) {
	if(x.r != y.r) return x.r < y.r;
	return x.l < y.l;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(k <= 1) {
		for(int i = 1; i <= n; i ++) {
			if(a[i] == k) ans ++;
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i ++) {
		int t = a[i];
		if(t == k) {
			v[++cnt].l = i;
			v[cnt].r = i;
		}
		for(int j = i + 1; j <= n; j ++) {
			t ^= a[j];
			if(t == k) {
				v[++cnt].l = i;
				v[cnt].r = j;
			}
		}
	}
	sort(v + 1, v + 1 + cnt, cmp);
	if(cnt == 0) {
		cout << 0;
		return 0;
	}
	int y = v[1].r;
	ans = 1;
	for(int i = 2; i <= cnt; i ++) {
		if(v[i].l > y) {
			y = v[i].r;
			ans ++;
		}
	}
	cout << ans;
	return 0;
}

