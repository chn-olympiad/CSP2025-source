#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 10;
inline int read(){
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, m, k, e[1010][1010], p[20][MAXN], e2[1010][1010], ok[20], c[MAXN],fa[MAXN];
struct Node{
	int u, v, w;
}es[1000010];

int d[20], tot;
bool az[2020];
bool vis[MAXN], flag;
int dis[MAXN];
ll ans = 0x3f3f3f3f3f3f3f3f, C = 0;

ll prim(){
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		vis[i] = 0, dis[i] = 0x3f3f3f3f;
	dis[1] = 0;
	for(int i = 1; i <= n; i++){
		int u = -1, t = 0x3f3f3f3f;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && dis[j] < t)
				u = j, t = dis[j];
		}
		if(u == -1) break;
		sum += t;
		vis[u] = true;
		for(int j = 1; j <= n; j++){
			if(u != j)
				dis[j] = min(dis[j], e2[u][j]);
		}
	}
	return sum;
}

void dfs(int id){
	if(id == k){
//		if(!flag) return ;
//		for(int i = 1; i <= k; i++)
//			cout << ok[i] << ' ';
//		cout << endl;
		tot = 0;
		ll sum = 0;
		for(int i = 1; i <= k; i++){
			if(ok[i])
				d[++tot] = i, sum += c[i];
		}
//		cout << tot << endl;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				int tmp = 0x3f3f3f3f;
				for(int h = 1; h <= tot; h++){
					int u = d[h];
					tmp = min(tmp, p[u][i]+p[u][j]);
					C++;
				}
				e2[i][j] = e2[j][i] = min(e[i][j], tmp);
			}
		}
		for(int i = 1; i <= n; i++)
			vis[i] = 0, dis[i] = 0x3f3f3f3f;
		dis[1] = 0;
		for(int i = 1; i <= n; i++){
			int u = -1, t = 0x3f3f3f3f;
			for(int j = 1; j <= n; j++){
				if(!vis[j] && dis[j] < t)
					u = j, t = dis[j];
			}
			if(u == -1) break;
			sum += t;
			if(sum > ans){
//				cout << "hym\n";
				return ;
			}
			vis[u] = true;
			for(int j = 1; j <= n; j++){
				if(u != j)
					dis[j] = min(dis[j], e2[u][j]);
			}
		}
		ans = min(ans, sum);
		return ;
	}
	ok[id+1] = 1;
	dfs(id+1);
	ok[id+1] = 0;
	dfs(id+1);
}

bool check1(){
	for(int i = 1; i <= k; i++){
		int mn = 0x3f3f3f3f;
		for(int j = 1; j <= n; j++)
			mn = min(mn, p[i][j]);
		if(mn != 0) return false;
	}
	return true;
}

bool cmp(Node x, Node y){
	return x.w < y.w;
}

int findd(int u){
	return u == fa[u] ? u : fa[u] = findd(fa[u]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	if(n <= 1e3){
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				e[i][j] = e[j][i] = 0x3f3f3f3f;
		for(int i = 1; i <= m; i++){
			int u = read(), v = read(), w = read();
			e[u][v] = e[v][u] = min(e[u][v], w);
		}
		if(k == 0){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++)
					e2[i][j] = e[i][j];
//					 cout << e[i][j] << ' ';
//				cout << endl;
			}
			ans = prim();
		} else{
			for(int i = 1; i <= k; i++){
				c[i] = read();
				for(int j = 1; j <= n; j++)
					p[i][j] = read();
			}
			if(check1()){
				for(int i = 1; i <= k; i++)
					ok[i] = 1;
				tot = 0;
				ll sum = 0;
				for(int i = 1; i <= k; i++){
					if(ok[i])
						d[++tot] = i, sum += c[i];
				}
		//		cout << tot << endl;
				for(int i = 1; i <= n; i++){
					for(int j = i+1; j <= n; j++){
						int tmp = 0x3f3f3f3f;
						for(int h = 1; h <= tot; h++){
							int u = d[h];
							tmp = min(tmp, p[u][i]+p[u][j]);
							C++;
						}
						e2[i][j] = e2[j][i] = min(e[i][j], tmp);
					}
				}
	//			cout << "debug : \n";
	//				for(int i = 1; i <= n; i++){
	//					for(int j = 1; j <= n; j++)
	//						cout << e2[i][j] << ' ';
	//					cout << endl;
	//				}
				ll tmp = sum + prim();
				ans = min(ans, tmp);
			} else if(k <= 5){
					dfs(0);
			}
		}
		cout << ans;
	}else if(k == 0){
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++){
			int u = read(), v = read(), w = read();
			es[i] = (Node){u,v,w};
		}
		ll ans = 0, cct = 0;
		sort(es+1, es+1+m, cmp);
		for(int i = 1; i <= m; i++){
			int u = es[i].u, v = es[i].v;
			int fu = findd(u), fv = findd(v);
			if(fu == fv) continue;
			ans += es[i].w;
			cct++;
			if(cct == n-1) break;
		}
		cout << ans;
	} 
	return 0;
}
