#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5;

int T, n, d[N][4], cnt[4];

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld", &T);
	while (T -- ) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++ i ) scanf("%lld%lld%lld", &d[i][1], &d[i][2], &d[i][3]);
		memset(cnt, 0, sizeof(cnt));
		priority_queue <pair <int, int> > q[4][4], s[4][4];
		int ans = 0;
		for (int i = 1; i <= n; ++ i ) {
			int maxn = -1;
			for (int j = 1; j <= 3; ++ j ) {
				if (cnt[j] < n / 2) {
					if (d[i][j] > maxn) {
						maxn = d[i][j];
					}
				} else {
					for (int k = 1; k <= 3; ++ k ) {
						if (cnt[k] < n / 2) {
							while (q[j][k].size() && s[j][k].size() && q[j][k].top() == s[j][k].top()) {
								q[j][k].pop();
								s[j][k].pop();
							}
							if (q[j][k].size()) {
								pair <int, int> tmp = q[j][k].top();
								if (tmp.first + d[i][j] > maxn) {
									maxn = tmp.first + d[i][j];
								}
							}
						}
					}
				}
			}
			ans += maxn;
			for (int j = 1; j <= 3; ++ j ) {
				if (cnt[j] < n / 2) {
					if (d[i][j] == maxn) {
						for (int k = 1; k <= 3; ++ k ) 
						    if (j != k)
						        q[j][k].push({d[i][k] - d[i][j], i});
					    
					    ++ cnt[j];
					    break;
					}
				} else {
					bool is = false;
					for (int k = 1; k <= 3; ++ k ) {
						if (cnt[k] < n / 2) {
							while (q[j][k].size() && s[j][k].size() && q[j][k].top() == s[j][k].top()) {
								q[j][k].pop();
								s[j][k].pop();
							}
							if (q[j][k].size()) {
								pair <int, int> tmp = q[j][k].top();
								if (tmp.first + d[i][j] == maxn) {
									is = true;
									int u = tmp.second;
									for (int t = 1; t <= 3; ++ t )
									    if (t != j)
									        s[j][t].push({d[u][t] - d[u][j], u});
									        
									for (int t = 1; t <= 3; ++ t )
									    if (t != k)
									        q[k][t].push({d[u][t] - d[u][k], u});
									        
									for (int t = 1; t <= 3; ++ t )
									    if (t != j)
									        q[j][t].push({d[i][t] - d[i][j], i});
									
									++ cnt[k];
									break;
								}
							}
						}
					}
					if (is) break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 

/*



*/
