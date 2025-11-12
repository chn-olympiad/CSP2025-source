// std T1
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
struct node{
	int x, y, z, id;
}a[N];
int n; 
int vis[N], cnt[4];

bool cmp(node p, node q) {
	int s = max({p.x, p.y, p.z});
	int t = max({q.x, q.y, q.z});
	return (s > t);
}

void solve() {
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		vis[i] = 0;
		a[i].id = i;
		cin >> a[i].x >> a[i].y >> a[i].z;
		int mx = max({a[i].x, a[i].y, a[i].z});
		ans += mx;
		if(mx == a[i].x) vis[i] = 1;
		else if(mx == a[i].y) vis[i] = 2;
		else vis[i] = 3;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		cnt[vis[i]]++;
	}
	int g = 0;
	if(cnt[1] > n / 2) g = 1;
	if(cnt[2] > n / 2) g = 2;
	if(cnt[3] > n / 2) g = 3;
	if(g == 0) {
		cout << ans << "\n";
		return;
	}
	for(int i = 1; i <= n; i++) {
		int x = a[i].x, y = a[i].y, z = a[i].z, id = a[i].id;
		if(vis[id] == g) {
			if(g == 1 && (y == x || z == x)) cnt[g]--, vis[id] = 0;
			if(g == 2 && (x == y || z == y)) cnt[g]--, vis[id] = 0;
			if(g == 3 && (x == z || y == z)) cnt[g]--, vis[id] = 0;
			if(cnt[g] <= n / 2) {
				cout << ans << "\n";
				return;
			}
		}
	}
	vector<int> vec;
	for(int i = n; i >= 1; i--) {
		int x = a[i].x, y = a[i].y, z = a[i].z, id = a[i].id;
		if(vis[id] == g) {
			int tmp = 0, o = 0;
			if(g == 1) o = x, tmp = max(y, z);
			if(g == 2) o = y, tmp = max(x, z);
			if(g == 3) o = z, tmp = max(x, y);
			vec.push_back({o - tmp});
		}
	}
	sort(vec.begin(), vec.end());
	for(auto x : vec) {
		cnt[g]--;
		ans -= x;
		if(cnt[g] <= n / 2) {
			cout << ans << "\n";
			return;
		}
	} 
}

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
} 
/*
0. 看题 
1. 别急，争取 T1T2AC，T3 高分暴力， T4 也不要爆零
2. freopen
3. long long
4. 防 CE，-Wall -W, linux，ulimit, size, time  
*/