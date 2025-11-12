#include<bits/stdc++.h>
#define int long long
using namespace std;
struct g{
	int u, v, w;
} ci[1000005];
struct gg{
	int c, a[10005];
} cou[15];
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int m, n, k, ans = 0;
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i++){
		cin >> ci[i].u >> ci[i].v >> ci[i].w;
		ans += ci[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> cou[i].c;
		for(int j = 1; j <= n; j++){
			cin >> cou[i].a[j];
		}
	}
	cout << ans;
	return 0;
}
