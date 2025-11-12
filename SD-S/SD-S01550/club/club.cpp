#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n;
struct node {
	int val, id;
}c[N];
int a[N][4], b[N][4];
bool cmp(node a1, node a2) {
	return a1.val > a2.val;
}
bool cmp2(node a1, node a2) {
	return a1.val > a2.val;
}

int get(int x, int y, int z) {
	for(int i = 1; i <= n; i ++) b[i][1] = b[i][2] = 0;
	for(int i = 1; i <= n; i ++) {
//		for(int j = 1; j <= 3; j ++) cin >> a[i][j];
		c[i].val = abs(a[i][x] - a[i][y]);
		c[i].id = i;
		b[i][2] = a[i][z];
	}
	sort(c + 1, c + n + 1, cmp);
	int ans = 0, sum1 = 0, sum2 = 0; 
	for(int i = 1; i <= n; i ++) {
		if(a[c[i].id][x] - a[c[i].id][y] > 0) {
			if(sum1 < n / 2) {
				ans += a[c[i].id][x];
				b[c[i].id][1] = a[c[i].id][x];
				sum1 ++;
			}
			else ans += a[c[i].id][y], sum2 ++, b[c[i].id][1] = a[c[i].id][y];
		}
		else {
			if(sum2 < n / 2) {
				ans += a[c[i].id][y];
				b[c[i].id][1] = a[c[i].id][y];
				sum2 ++;
			}
			else ans += a[c[i].id][x], sum1 ++, b[c[i].id][1] = a[c[i].id][x];
		}
	}
	
	for(int i = 1; i <= n; i ++) {
		c[i].val = abs(b[i][1] - abs(b[i][2]));
		c[i].id = i;
	}
	sort(c + 1, c + n + 1, cmp2);
	ans = 0, sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i ++) {
		if(b[c[i].id][1] - b[c[i].id][2] > 0) {
			ans += b[c[i].id][1];
			sum1 ++;
		}
		else {
			if(sum2 < n / 2) {
				ans += b[c[i].id][2];
				sum2 ++;
			}
			else ans += b[c[i].id][1], sum1 ++;
		}
	}
	return ans;
}
int sum[4];
int cnt, ans;
void dfs(int now, int id) {
	if(now == n) {
		cnt = max(cnt, ans);
		return;
	}
	for(int i = 1; i <= 3; i ++) {
		if(sum[i] < n / 2) {
			sum[i] ++;
			ans += a[now + 1][i];
			dfs(now + 1, i);
			ans -= a[now + 1][i];
			sum[i] --;
		}
	}
}
void solve10() {
	sum[1] = sum[2] = sum[3] = 0;
	cnt = 0;
	ans = 0;
	dfs(0, 0);
	cout << cnt << endl;
}
void solve() {
	
	cin >> n;
	for(int i = 1; i <= n; i ++) b[i][1] = b[i][2] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= 3; j ++) cin >> a[i][j];
	}
	if(n <= 10) {
		solve10();
		return;
	}
	cout << max(get(1, 2, 3), max(get(1, 3, 2), get(2, 3, 1))) << endl;
//	cout << get(1, 2, 3) << " " << get(2, 3, 1) << endl;
}
int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int T;	
	cin >> T;
	while(T --) solve();
	return 0; 
} 


