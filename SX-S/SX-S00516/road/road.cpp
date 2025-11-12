#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, w;
} side[10000005];
int n, m, k, fa[10005], nn, top, ans;
map<int,int> mp;
int city[12];
int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	nn = n;
	for (int i = 1; i <= m; i++) {
		top++;
		cin >> side[top].u >> side[top].v >> side[top].w;
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= k; i++) {
		int con;
		cin >> con;
		nn++;
		city[i]=con;
		for (int i = 1; i <= n; i++) {
			int ww;
			cin >> ww;
			top++;
			
			side[top].u = nn;
			side[top].v = i;
			side[top].w = ww;
		}
	}
	sort(side + 1, side + top + 1, cmp);
	for (int i = 1; i <= top; i++) {
		int uu = side[i].u, vv = side[i].v, ww = side[i].w;
		int uf = find(uu), vf = find(vv);
		if (uf == vf)
			continue;
		if(uu>n){
			if(mp[uu]==0){
				ans+=city[uu-n];
				mp[uu]=1;
			}
		}
		fa[uf] = vf;
		ans += ww;
	}
	cout << ans;
	return 0;

}