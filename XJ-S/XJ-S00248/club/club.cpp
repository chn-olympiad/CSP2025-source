#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;
int n, a[N][4], c[12];
int T, ans = 0;

inline void dfs(int i, int x, int y, int z) {
	if(i == n + 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += a[i][c[i]];
		ans = max(cnt, ans);
		return;
	}
	if(x < n / 2) {
		c[i + 1] = 1;
		dfs(i + 1, x + 1, y, z);
	}
	if(y < n / 2) {
		c[i + 1] = 2;
		dfs(i + 1, x, y + 1, z);
	}
	if(z < n / 2) {
		c[i + 1] = 3;
		dfs(i + 1, x, y, z + 1);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		ans = 0;
		cin >> n;
		bool ok1 = false, ok2 = false;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if(j == 3) {
					if(a[i][2] || a[i][3])
						ok1 = true;
					if(a[i][3])
						ok2 = true;
				}
			}
		if(!ok1) {
			vector<int> s;
			for(int i = 1; i <= n; i++)
				s.push_back(-a[i][1]);
			sort(s.begin(), s.end());
			ll ans = 0;
			for(auto y : s)
				ans -= y;
			cout << ans << '\n';
		}
		dfs(0, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}
