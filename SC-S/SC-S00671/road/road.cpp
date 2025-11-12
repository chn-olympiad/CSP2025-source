#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node{
	int u, v, w;
}g[N];
int fa[N];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int getfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
	int fx = getfa(x), fy = getfa(y);
	fa[fx] = fy;
}
int n, m, k;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	sort(g + 1, g + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (getfa(g[i].u) != getfa(g[i].v)) {
			ans += g[i].w;
			merge(g[i].u, g[i].v);
		}
	}
	cout << ans;
	return 0;
} 



























//爱是什么
//是最完满的理解、接纳、信任与责任 
//喜欢与爱的区别是什么 
//一个想让对方陪在自己身边，一个想自己能陪在对方身边 
//一个欣赏着对方完美的样子，一个将自己最完美的样子展现给对方，希望对方将不完美的一面展现给自己 
//喜欢与爱的共同点是什么 
//在谈论到这个话题时，第一个想到了你


//误入高端局 ,这个题怎么这么难 