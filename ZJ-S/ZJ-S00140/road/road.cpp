#include <bits/stdc++.h>
#define int long long
using namespace std;
//byd i can't solve it when k > 0

//at least i can get 16pts

//min generated tree
int n, m, k, ans;
const int maxn = 1e4+5, maxm = 1e6+5;

struct edge{
	int from, to, w;
	bool operator<(const edge &another) const{
		return w < another.w;
	}
}edges[maxm];

int fa[maxn];
void init(){
	for (int i = 1; i <= n; i++){
		fa[i] = i;
	}
}

int find(int x){
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void update(int a, int b){
	int aa = find(a), bb = find(b);
	if (aa != bb) fa[aa] = bb;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (k == 0){
		init();
		for (int i = 1; i <= m; i++){
			cin >> edges[i].from >> edges[i].to >> edges[i].w;
		}
		sort(edges+1, edges+1+m);
		int cnt = 0;
		for (int i = 1; i <= m && cnt < n; i++){
			int a = edges[i].from, b = edges[i].to;
			if (find(a) != find(b)){
				if (cnt == 0) cnt = 2;
				else cnt++;
				update(a, b);
				ans += edges[i].w;
			}
		}
		cout << ans;
	}
	return 0;
}
