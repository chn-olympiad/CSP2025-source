#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;
using tp = std::tuple<int, int, int>;
const int N = 1070; int n, m, k, s;
struct{
	int f[N]; void set(){for(int i=1;i<N;i++) f[i]=i;}
	inline int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
	int mg(int x, int y){x=fd(x),y=fd(y);int t=x^y;f[x]=y;return t;}
} T;
ll sv(std::vector<tp>&G, std::vector<tp>&R){
	T.set(); ll rs = 0; for(auto [w, u, v] : G){
		if(T.mg(u, v)) rs += w, R.push_back({w, u, v});
	}
	return rs;
}
void mg(std::vector<tp>&a, std::vector<tp>&b, std::vector<tp>&rs){
	rs.resize(a.size() + b.size());
	for(int i = 0, pa = 0, pb = 0; i < rs.size(); i++){
		if(pa==a.size()) rs[i] = b[pb++];
		else if(pb==b.size()) rs[i] = a[pa++];
		else rs[i]=(a[pa]<b[pb])?a[pa++]:b[pb++];
	}
}
std::vector<tp> G[N], g[12]; int c[N], a[13][N]; ll sm[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m >> k; s = 1 << k;
	for(int i = 1, x, y, w; i <= m; i++)
		std::cin >> x >> y >> w, G[s].push_back({w, x, y});
	std::sort(G[s].begin(), G[s].end()); ll rs = sv(G[s], G[0]);
	for(int i = 1; i <= k; i++){
		std::cin >> c[i];
		for(int j = 1; j <= n; j++)
			std::cin>>a[i][j], g[i].push_back({a[i][j],i+n,j});
		std::sort(g[i].begin(), g[i].end());
	}
	for(int t = 1; t < s; t++) for(int i = k; i; i--)
		if(t & (1 << i - 1)){
			sm[t] = sm[t ^ (1 << i - 1)] + c[i];
			mg(g[i], G[t ^ (1 << i - 1)], G[s]);
			rs = std::min(rs, sm[t] + sv(G[s], G[t]));
		}
	std::cout << rs << '\n';
}
