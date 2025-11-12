//SN-S00235 张正轩 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from, to, d;
}e[1000005];
bool cmp(edge a, edge b) {
	return a.d < b.d;
}
int f[1005];
int find(int x) {
	if (x == f[x]) return x;
	else return f[x] = find(f[x]);
}
int main() {
	freopen("rode.in", "r", stdin);
	freopen("rode.out", "w", stdout); 
	int n, m, k, t = 0, ans = 0;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			cin >> e[i].from >> e[i].to >> e[i].d;
		}
		sort(e + 1, e + 1 + m, cmp);
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			int x = e[i].from, y = e[i].to;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				t++;
				ans += e[i].d;
				f[fx] = fy;
			}
			if (t == n - 1){
				break;
			}
		}
		cout << ans;
	}else {
		cout << 0;
	}
	return 0;
}
