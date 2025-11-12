#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
	int x, y, w;
}edge[1000005], mst[10005], b[100005];

bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
int msttot, btot;
int n, m, a[15][10005], k, fa[10015], c[15], id[15][10005];
bool vis[100005];

int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		edge[i] = {x, y, w};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			b[++btot] = {i, j, a[i][j]};
		}
	}
	sort(b + 1, b + btot + 1, cmp);
	
	for(int i = 1; i <= btot; i++){
		id[b[i].x][b[i].y] = i;
	}
	
	sort(edge + 1, edge + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int x = edge[i].x, y = edge[i].y, w = edge[i].w;
		if(find(x) == find(y)) continue;
		mst[++msttot] = (Edge){x, y, w};
		fa[find(x)] = find(y);
	}
	
	int ans = (int)1e18;
	for(int S = 0; S < (1 << k); S++){
		for(int i = 1; i <= n * k; i++) vis[i] = 0;
		
		int res = 0, lian = n;
		for(int i = 1; i <= k; i++){
			if((S >> (i - 1)) % 2){
				res += c[i];
				lian++;
				for(int j = 1; j <= n; j++) vis[id[i][j]] = 1;
			}
		}
		
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		int j = 1;
		for(int i = 1; i < n; i++){
			while(j <= n * k && b[j].w < mst[i].w){
				if(vis[j]){
					int fax = find(b[j].x + n), fay = find(b[j].y);
					if(fax != fay){
						fa[fax] = fay;
						res += b[j].w;
						lian--;
						
//						cout << S << " add edge " << b[j].x + n << " " << b[j].y << " " << b[j].w << endl; 
					}
				}
				j++;
			}
			
			int fax = find(mst[i].x), fay = find(mst[i].y);
			if(fax != fay){
				lian--;
				fa[fax] = fay;
				res += mst[i].w;
//				cout << S << " add edge " << mst[i].x << " " << mst[i].y << " " << mst[i].w << endl; 
			}
			
			if(lian == 1) break;
		}
		ans = min(ans, res);
		
//		cout << S <<" " << res << endl; 
	}
	cout << ans << "\n";
	return 0;
}
