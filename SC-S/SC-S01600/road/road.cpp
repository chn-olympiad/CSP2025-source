#include<bits/stdc++.h>
#define F(i,l,r) for(int i(l); i <= (r); ++ i)
#define G(i,r,l) for(int i(r); i >= (l); -- i)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
//#define int ll
using namespace std;
using ll = long long;
const int N = 2e6;
struct node{
	int u, v, w;
	bool operator < (const node &other)const{
		return w < other.w;
	}
}a[N], b[N], d[N];
int n, m, k, num = 0;
ll ans = 0;
int c[100], val[20][20000], fa[N];
void add(int x, int y, int z){
	b[++ num] = (node){x, y, z};
}
int getfather(int x){
	if(fa[x] != x) return fa[x] = getfather(fa[x]);
	return fa[x];
}
void merge(int u, int v){
	fa[u] = v;
}
void kru(int sm){
	sort(a + 1, a + num + 1);
	F(i, 1, sm) fa[i] = i;
	int cnt = 0;
	F(i, 1, num){
		int u = a[i].u, v = a[i].v, w = a[i].w;
		int fu = getfather(u), fv = getfather(v);
		if(fu == fv) continue; 
		merge(fu, fv);
		ans += w;
		d[++ cnt] = a[i];
		if(cnt == sm - 1) return ;
	}
}
ll kruskal(int sm){
	sort(b + 1, b + num + 1);
	F(i, 1, n + k) fa[i] = i;
	int cnt = 0;
	ll sum = 0;
	F(i, 1, num){
		int u = b[i].u, v = b[i].v, w = b[i].w;
		int fu = getfather(u), fv = getfather(v);
		if(fu == fv) continue; 
		merge(fu, fv);
		sum += w;
		++ cnt;
		if(cnt == sm - 1) return sum;
	}
	return -1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	F(i, 1, m){
		int u, v, w;
		cin >> u >> v >> w;
		a[++ num] = (node){u, v, w};
	}
	kru(n);
//	printf("ans = %d\n", ans);
	F(i, 1, k){
		cin >> c[i];
		F(j, 1, n) cin >> val[i][j];
	}
	F(o, 1, (1 << k) - 1){
//		printf("o = %d:\n", o);
		int x = o, id = 0, cc = 0;
		ll delta = 0;
		num = n - 1;
		F(i, 1, n - 1) b[i] = d[i];
		while(x){
			++ id;
			if(x % 2 == 1){
//				printf("%d ", id);
				delta += c[id];
				++ cc;
				F(i, 1, n) add(id + n, i, val[id][i]);
			}
			x /= 2;
		}
//		printf("\n");
		sort(b + 1, b + num + 1);
		ll nw = kruskal(n + cc);
//		printf("nw = %d\n", nw + delta);
		ans = min(ans, nw + delta);
	}
	cout << ans << '\n';
	return fflush(0), 0;
}