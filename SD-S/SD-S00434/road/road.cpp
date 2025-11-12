#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e4 + 20, MAXM = 4e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9'){if(f == '-')f = -1; c = getchar();}
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c - '0'); c = getchar();}
	return f * x;
}
int buf[40];
inline void write(ll x){
	if(!x){putchar('0');return;}
	if(x < 0){putchar('-');x = -x;}
	int len = 0;
	while(x){
		buf[++len] = x % 10;
		x /= 10;
	}
	while(len){
		putchar(buf[len] + '0');
		len--;
	}
}
ll n, m, k, a[12][MAXN], head[MAXN], cnt, dis[1025][MAXN], vis[MAXN], c[12], N;
struct Edge{
	ll to, nxt, w;
}e[MAXM];
void add(ll u, ll v, ll w){
	e[++cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].to = v;
	e[cnt].w = w;
}
ll tot;
ll prim(ll s){
	ll tmp = 0;
	for(int i = 1; i <= N; i++)
		dis[s][i] = inf, vis[i] = 0;
	dis[s][1] = 0;
	for(int tm = 1; tm <= N; tm++){
		ll u = -1, minn = inf;
		for(int i = 1; i <= N; i++){
			if(!vis[i] && dis[s][i] < minn)
				u = i, minn = dis[s][i];
		}
		if(u == -1)
			break;
		vis[u] = 1;
//		cout << u << ' ' << dis[s][u] << '\n';
		for(ll i = head[u]; i != -1; i = e[i].nxt){
			ll v = e[i].to, w = e[i].w;
			if(v > n){
				if(((1ll << (v - n - 1)) & s) == 0)
					continue;
			}
			if(dis[s][v] > w){
				dis[s][v] = w;//cout << v << ' ';
//				break;
			}
		}
//		puts("");
	}
	for(int i = 1; i <= N; i++){
		if(i > n){
			if(((1ll << (i - n - 1)) & s) == 0)
				continue;
		}
		tmp += dis[s][i];
	}
//	puts("end");
	return tmp;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	N = n + k;
	for(int i = 1; i <= N; i++)
		head[i] = -1;
	for(int i = 1; i <= m; i++){
		ll u = read(), v = read(), w = read();
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i <= k; i++){
		c[i] = read();
		for(int j = 1; j <= n; j++){
			a[i][j] = read();
			add(n + i, j, a[i][j]);
			add(j, n + i, a[i][j]);
		}
			
	}
	if(n <= 1000 && k <= 5 || k == 0){
		ll ans = inf;
		for(ll i = 0; i <= (1ll << k) - 1; i++){
			ll now = prim(i);
//			cout << now << '\n';
//			cout << tot << '\n';
//			write(now);
//			putchar('\n');
			for(ll j = 0; j < k; j++){
				if((1ll << j) & i)
					now += c[j + 1];
			}
			ans = min(ans, now);
		}
//		ans = prim(0);
		write(ans);
		return 0;
	}
	else{write(0);}
	return 0;
}
