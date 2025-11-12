# include <bits/stdc++.h>
# define endl '\n'
typedef long long i64;

const int _ = 2e4 + 10;
const int __ = 2e6 + 10;

int n, m, k;
int c[20];
i64 a[20][_], w[__];
int u[__], v[__];

int p[__];
namespace dsu{
	int fa[_], siz[_];
	void init(int n){
		std::iota(fa + 1, fa + 1 + n, 1);
		std::fill(siz + 1, siz + 1 + n, 1);
	}
	int find(int x){
		return fa[x] = fa[x] == x ? x : find(fa[x]);
	}
	bool mer(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return false;
		if(siz[x] > siz[y]) std::swap(x, y);
		fa[x] = y, siz[y] += siz[x];
		return true ;
	}
}

bool vis[20];
i64 dis[20];

signed main(){
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		std::cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++){
		std::cin >> c[i];
		for(int j = 1;j <= n;j++){
			std::cin >> a[i][j];
		}
	}
	
	i64 ans = 1e18;
	for(int s = 0;s < (1 << k);s++){
		i64 mst = 0;
		int tot = 0, edge = m;
		for(int i = 1;i <= k;i++) if(s >> i - 1 & 1){
			mst += c[i];
			tot ++;
			for(int j = 1;j <= n;j++){
				u[++ edge] = n + tot;
				v[edge] = j;
				w[edge] = a[i][j];
			}
		}
		std::iota(p + 1, p + 1 + edge, 1);
		std::sort(p + 1, p + 1 + edge, [&](int x, int y){ return w[x] < w[y]; });
		dsu::init(n + tot);
		for(int i = 1, cnt = 0;i <= edge && cnt < n + tot - 1;i++){
			int x = p[i];
			if(dsu::mer(u[x], v[x])){
				mst += w[x];
				cnt ++;
			}
		}
		ans = std::min(ans, mst);
	}
	std::cout << ans << endl;
	return 0;
} 
