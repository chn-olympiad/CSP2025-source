#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, T;
inline bool cmp(int x, int y) {
	return x > y;
}
struct node {
	int a[4];
	int num, mx;
	inline void Sort() {
		sort(a + 1, a + 4, cmp);
		mx = a[1], num = a[1] - a[2];
	}
} a[N];
inline bool cmp2(node x, node y) {
	return x.num < y.num;
}
vector<node> vec[4];
inline void solve() {
	cin >> n;
	vec[1].clear(), vec[2].clear(), vec[3].clear();
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
		int x = a[i].a[1], y = a[i].a[2], z = a[i].a[3];
		a[i].Sort();
		if(a[i].a[1] == x)vec[1].push_back(a[i]);
		else if(a[i].a[1] == y)vec[2].push_back(a[i]);
		else vec[3].push_back(a[i]);
		ans += a[i].mx;
	}
	for(int j = 1; j <= 3; j ++) {
		if(vec[j].size() > n / 2) {
			sort(vec[j].begin(), vec[j].end(), cmp2);
			for(int i = 0; i < vec[j].size() - n / 2; i ++)ans -= vec[j][i].num;
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T --)solve();
	return 0;
}
