#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>inline void read(T &x){
	x = 0; T w = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-')	w = -1; ch = getchar();}
	while (isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x *= w;
}
template<typename T>inline void write(T x){
	if (x < 0)	putchar('-'), x = ~(x - 1);
	if (x > 9)	write(x / 10);
	putchar(x % 10 ^ 48);
}

const ll N = 1e4 + 5;
const ll M = 1e6 + 5;
const ll K = 15;

ll n, m, k, ans = 1e18, cnt, sum, popcnt;

struct edge{
	ll u, v, w;
}e[M + N * K];
int tp, lst_tp, now_cnt;
bool cmp(edge alp, edge bet){
	return alp.w < bet.w;
}

int fa[N + K];
int getfa(int u){
	return u ^ fa[u] ? fa[u] = getfa(fa[u]) : u;
}

bool ck, vis[N];

ll c[K], a[K][N];

int main(){
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
//	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

	read(n), read(m), read(k);
	for (int i = 1; i <= m; ++i)
		read(e[i].u), read(e[i].v), read(e[i].w);
	for (int i = 1; i <= k; ++i){
		read(c[i]);
		if (c[i])	ck = true;
		for (int j = 1; j <= n; ++j)	read(a[i][j]);
	}
	if (k <= 5 && m <= 1e5){
		for (int st = 0; st < (1 << k); ++st){
			sum = 0, tp = m, popcnt = cnt = 0;
			for (int i = 1; i <= k; ++i)
				if ((st >> (i - 1)) & 1){
					sum += c[i], ++popcnt;
					for (int j = 1; j <= n; ++j)
						e[++tp] = (edge){i + n, j, a[i][j]};
				}
			sort(e + 1, e + tp + 1, cmp);
			for (int i = 1; i <= n + k; ++i)	fa[i] = i;
			for (int i = 1, u, v; i <= tp; ++i){
				u = getfa(e[i].u), v = getfa(e[i].v);
				if (u ^ v){
					++cnt, sum += e[i].w, fa[u] = v;
					if (cnt == n + popcnt - 1)	break;
				}
			}
			ans = min(ans, sum);
		}
		write(ans);
		return 0;
	}
	if (!ck){
		tp = m;
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= n; ++j)
				e[++tp] = (edge){i + n, j, a[i][j]};
		sort(e + 1, e + tp + 1, cmp);
		for (int i = 1; i <= n + k; ++i)	fa[i] = i;
		for (int i = 1, u, v; i <= tp; ++i){
			u = getfa(e[i].u), v = getfa(e[i].v);
			if (u ^ v){
				++cnt, sum += e[i].w, fa[u] = v;
				if (cnt == n + k - 1)	break;
			}
		}
		write(sum);
		return 0;
	}
	ans = cnt = 0;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; ++i)	fa[i] = i;
	for (int i = 1, u, v; i <= m; ++i){
		u = getfa(e[i].u), v = getfa(e[i].v);
		if (u ^ v){
			++cnt, ans += e[i].w, fa[u] = v;
			if (cnt == n - 1)	break;
		}
	}
	lst_tp = tp = m, now_cnt = n;
	for (int t = 1; t <= k; ++t){
		vis[t] = true;
		for (int i = 1; i <= n; ++i)
			e[++tp] = (edge){t + n, i, a[t][i]};
		sort(e + 1, e + tp + 1, cmp);
		for (int i = 1; i <= n + k; ++i)	fa[i] = i;
		cnt = 0, sum = 0;
		for (int i = 1, u, v; i <= tp; ++i){
			u = getfa(e[i].u), v = getfa(e[i].v);
			if (u ^ v){
				++cnt, sum += e[i].w, fa[u] = v;
				if (cnt == now_cnt)	break;
			}
		}
		for (int i = 1; i <= k; ++i)
			if (vis[i])	sum += c[i];
		if (sum >= ans){
			vis[t] = false;
			tp = lst_tp;
		}
		else{
			ans = sum, lst_tp = tp, ++now_cnt;
		}
	}
	write(ans);

	return 0;
}
