#include<bits/stdc++.h>
#define int long long
#define f(i , x , y) for(int i = (x); i <= (y); ++ i)
using namespace std;
inline int read(){
	int x = 0 , f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	return x * f;
}
int n , m , k , cnt = 0;
constexpr int N = 1e6 + 55 , M = 1e4 + 101;
int c[M];
struct Node{
	int u , v , w;
}E[N] , p[11][M];
inline bool cmp(Node x , Node y){
	return x . w < y . w;
}
struct Onion{
	int fa[M] , sz[M];
	int sp;
	inline void reset(int n , int spp = 0){
		sp = spp;
		for(int i = 0; i <= n + 20; ++ i){
			fa[i] = i;
			sz[i] = 1;
		}
	}	
	inline int find(int u){
		if(fa[u] == u) return u;
		return fa[u] = find(fa[u]);
	}
	inline void merge(int u , int v){
		u = find(u) , v = find(v);
		if(u == v) return ;
		-- sp;
		if(sz[v] > sz[u]) swap(u , v);
		fa[v] = u;
		sz[u] += sz[v];
		return ;
	} 
}O;
namespace Solution{
	inline void solve(){
		n = read() , m = read(); k = read();
		f(i , 1, m){
			int u = read() , v = read() , w = read();
			E[i] = {u , v , w};
		}
		f(j , 1, k){
			c[j] = read(); //cerr << c[j] << '\n';
			f(i , 1 , n){
				p[j][i] . u = n + j;
				p[j][i] . v = i;
				p[j][i] . w = read();
			}
			sort(p[j] + 1 , p[j] + n + 1 , cmp);
		}
		sort(E + 1 , E + m + 1 , cmp);
		O . reset(n , n);
		int res = 0;
		f(i , 1 , m){
			int u = E[i] . u , v =  E[i] . v;
			if(O . find(u) == O . find(v)) continue;
			res += E[i] . w;
			p[0][++ cnt] = E[i];
			O . merge(u , v);
		}
		p[0][n] = p[0][1];
		for(int i = 1; i < (1LL << k); ++ i){
			int tot = 0 , sz = n;
			vector<int> v = {0};
			vector<int> pos(k + 3 , 1);
			for(int j = 0; j < k; ++ j)
				if(i >> j & 1)
					tot += c[j + 1] , sz ++ , v . push_back(j + 1);
			O . reset(n , sz);
			while(O . sp != 1){
				if(tot >= res) break;
				int mn = 2e9 , t = 0;
				Node c;
				for(auto j : v){
					if(pos[j] <= n && mn > p[j][pos[j]] . w){
						mn = p[j][pos[j]] . w;
						c = p[j][pos[j]];
						t = j;
					}
				}
				pos[t] ++;
				int u = c . u , v = c . v;
				if(O . find(u) == O . find(v)) continue;
				tot += mn;
				O . merge(u , v);
			}
			res = min(res , tot);
		}
		cout << res << '\n';
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T = 1;
	while(T --) Solution :: solve();
	return 0;
}

