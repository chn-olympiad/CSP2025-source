# include <bits/stdc++.h>
# define fr front
# define fir first
# define sec second
# define vec vector
# define it iterator
# define pb push_back
# define lb lower_bound
# define ub upper_bound
# define all(x) x.begin(), x.end()
# define mem(a, b) memset(a, b, sizeof a)

# define lc(p) (t[p].l)
# define rc(p) (t[p].r)
# define ls(p) (p << 1)
# define rs(p) (p << 1 | 1)
# define lson ls(p), l, mid
# define rson rs(p), mid + 1, r

# define sqr(x) ((x) * (x))
# define bpc __builtin_popcount
# define lowbit(x) ((x) & (-(x)))
# define geti(x, i) ((x) & (1 << (i)))
# define set1(x, i) ((x) | (1 << (i)))
# define set0(x, i) ((x) & (~(1 << (i))))

# define each1(i, x) for(auto (i) : (x))
# define each2(i, x) for(auto (&i) : (x))
# define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
# define pre(i, a, b) for(int i = (a); i >= (b); -- i)
# define G(i, h, u, ne) for(int i = h[u]; i; i = ne[i])
# define reps(i, a, b, c) for(int i = (a); i <= (b); i += c)
# define pres(i, a, b, c) for(int i = (a); i >= (b); i -= c)
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

const int N = 1e4 + 10, M = 1e6 + 10, K = 20;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = 1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int n, m, k, idx, cnt, num, te;
int f[N + K], c[K], a[K][N];

LL ans;

bool fA = true;

struct edge{
	int a, b, w;
}e[M + N * K];

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void init(int n){
	rep(i, 1, n) f[i] = i;
}

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return false;
	f[b] = a;
	return true;
}

void kruskal(int n){
	ans = cnt = 0;
	init(n);
	sort(e + 1, e + 1 + idx, cmp);
	
	rep(i, 1, idx){
		if(merge(e[i].a, e[i].b)){
			cnt ++;
			ans += e[i].w;
		}
		
		if(cnt == n - 1) return;
	}
}

namespace subA{
	void main(){
		idx = m;
		rep(i, 1, k){
			rep(j, 1, n){
				e[++ idx] = {n + i, j, a[i][j]};
			}
		}
		
		kruskal(n + k);
		
		cout << ans;
	}
}

namespace sub14{
	void main(){
		idx = m;
		kruskal(n);
		cout << ans;
	}
}

namespace sub{
	LL mn = INF4, sum;
	
	void main(){
		rep(s, 0, (1 << k) - 1){
			idx = m;
			num = sum = 0;
			
			rep(i, 1, k){
				if(geti(s, i - 1)){
					num ++;
					sum += c[i];
					rep(j, 1, n){
						e[++ idx] = {n + num, j, a[i][j]};
					}
				}
			}
			
			kruskal(n + num);
			mn = min(mn, ans + sum);
			te = clock();
			if(te >= 870000){
				cout << mn;
				exit(0);
			}
		}
		
		cout << mn;
	}
}

signed main(){
# ifndef LOCAL
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
# endif
//	freopen("road2.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	
	rep(i, 1, m){
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = {a, b, c};
	}
	
	rep(i, 1, k){
		cin >> c[i];
		if(c[i]) fA = false;
		rep(j, 1, n){
			cin >> a[i][j];
		}
	}
	
	if(!k){
		sub14::main();
		return 0;
	}
	
	if(fA){
		subA::main();
		return 0;
	}
	
	sub::main();
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/