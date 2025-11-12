#include <bits/stdc++.h>
#define gc getchar
#define ll long long
using namespace std;
int rd() {
	int x = 0, f = 1; char c = gc();
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = gc(); }
	while(c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
	return (x * f);
}

const int N = 100000;
int n, a[N + 1][3];
vector < int > nds[3];
#define siz(x) ((int)x.size())
inline bool cmp(int x, int y) { return max(a[x][1], a[x][2]) - a[x][0] > max(a[y][1], a[y][2]) - a[y][0]; }
void Solve() {
	n = rd();
	nds[0].clear(); nds[1].clear(); nds[2].clear();
	for(int i = 1; i <= n; ++ i) {
		a[i][0] = rd(); a[i][1] = rd(); a[i][2] = rd();
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) nds[0].emplace_back(i);
		else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) nds[1].emplace_back(i);
		else nds[2].emplace_back(i);
	}
	int ans = 0;
	for(int i : nds[0]) ans += a[i][0];
	for(int i : nds[1]) ans += a[i][1];
	for(int i : nds[2]) ans += a[i][2];
	if(! (siz(nds[0]) <= n / 2 && siz(nds[1]) <= n / 2 && siz(nds[2]) <= n / 2)) {
		int k = 0;
		if(siz(nds[1]) > n / 2) k = 1;
		else if(siz(nds[2]) > n / 2) k = 2;
		if(k) {
			for(int i = 1; i <= n; ++ i) swap(a[i][0], a[i][k]);
			swap(nds[0], nds[k]);
		}
		sort(nds[0].begin(), nds[0].end(), cmp);
		int cnt = siz(nds[0]) - n / 2;
		for(int i = 0; i < cnt; ++ i) ans += (max(a[nds[0][i]][1], a[nds[0][i]][2]) - a[nds[0][i]][0]);
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = rd();
	while(T --) Solve();
	return 0;
}