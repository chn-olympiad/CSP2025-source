#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e5 + 10;
int T, n, a[N][4], id, b[N];
vector<int> e[4];

bool cmp(const int &u, const int &v) {
	return b[u] < b[v];
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	for(; T; T--) {
		id = 0;
		for(int i = 1; i <= 3; i++) e[i].clear();
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) 
				scanf("%lld", &a[i][j]); 
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) 
				e[1].pb(i), b[i] = a[i][1] - max(a[i][2], a[i][3]);
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
				e[2].pb(i), b[i] = a[i][2] - max(a[i][1], a[i][3]);
			else e[3].pb(i), b[i] = a[i][3] - max(a[i][1], a[i][2]);
		}
		for(int i = 1; i <= 3 && !id; i++)
			if((int)e[i].size() > (n / 2))
				id = i;
		sort(e[id].begin(), e[id].end(), cmp);
		int ans = 0, cnt = e[id].size();
		for(int i = 1; i <= 3; i++)
			for(auto j : e[i])
				ans += a[j][i];
		for(auto i : e[id]) {
			if(cnt <= (n / 2)) break;
			ans -= b[i], cnt--;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
