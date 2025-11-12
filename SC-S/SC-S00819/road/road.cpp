#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+15;
int fa[N];
struct node{
	int u, v;
	ll w;
	bool operator<(const node &o)const{
		return w < o.w;
	}
}g[N];
int fnd(int x){
	if(fa[x] == x){
		return fa[x];
	}
	return fnd(fa[x]);
}
ll c[15], a[15][N];
int n, m, k;
void f(ll &res, int lim, int ve){ 
	for(int i=1; i<=lim+n; ++i){
		fa[i] = i;
	}                  
//	cout << m + lim << ' ';
	sort(g+1,g+1+ve);             
	int sum=0;
	while(sum < lim + n){
		++sum;
		int x = g[sum].u,y=g[sum].v,w=g[sum].w;
//		cout << x << ' ' << y << ',';
		int fx = fnd(x), fy = fnd(y);
		if(fx==fy)continue;
		fa[fy] = fx;
		res += w;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i=1; i<=m; ++i){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[i]={u,v,w};
	}
	for(int i=1; i<=k; ++i){
		cin >> c[i];
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	ll Min=LLONG_MAX;
	for(int S=0; S < (1<<(k)); ++S){
		int num_1=0;
		int cnt = m;
		ll ans=0;
		for(int i=1; i<=k; ++i){
			if((1<<(i-1)) & S){
				num_1++;
				for(int j=1; j<=n; ++j){
					g[++cnt]={n+num_1,j,a[i][j]};
				}
				ans += c[i];
			}
		}
		f(ans, num_1, cnt);
		Min=min(Min, ans);
	}
	cout << Min;
	return 0;
}
