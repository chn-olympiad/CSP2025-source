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

const int N = 1e5 + 10;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = 1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int T, n, ans, mx1, mx2;
int a[N][5], c[N], cnt[5];

vec<int> res[5];

void solve(){
	ans = 0;
	mem(cnt, 0);
	rep(i, 1, 3) res[i].clear();
	
	cin >> n;
	
	rep(i, 1, n){
		mx1 = 0, mx2 = 0;
		rep(j, 1, 3){
			cin >> a[i][j];
			mx1 = max(mx1, a[i][j]);
		}
		
		rep(j, 1, 3){
			if(a[i][j] == mx1){
				cnt[j] ++;
				res[j].pb(i);
				break;
			}
		}
		
		sort(a[i] + 1, a[i] + 1 + 3, greater<int>());
		mx2 = a[i][2];
		c[i] = mx1 - mx2;
		ans += mx1;
	}
	
	rep(i, 1, 3){
		if(cnt[i] > n / 2){
			priority_queue<int, vec<int>, greater<int>> heap;
			while(!heap.empty()) heap.pop();
			each1(x, res[i]){
				heap.push(c[x]);
			}
			
			while(cnt[i] > n / 2){
				cnt[i] --;
				ans -= heap.top();
				heap.pop();
			}
		}
	}
	
	cout << ans << "\n";
}

signed main(){
# ifndef LOCAL
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
# endif
//	freopen("club5.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while(T --){
		solve();
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/