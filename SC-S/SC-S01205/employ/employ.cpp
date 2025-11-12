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

const int N = 5e2 + 10, mod = 998244353;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = 1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int n, m;
int c[N];

char s[N];

bool fA = true;

namespace sub12{
	int ans;
	int order[N];
	bitset<N> used;
	
	bool check(){
		int cnt = 0;
		rep(i, 1, n){
			if(cnt >= c[order[i]] || s[i] == '0') cnt ++;
		}
		
		return n - cnt >= m;
	}
	
	void dfs(int k){
		if(k == n + 1){
			ans += check();
			return;
		}
		
		rep(i, 1, n){
			if(used[i]) continue;
			used[i] = true;
			order[k] = i;
			dfs(k + 1);
			used[i] = false;
		}
	}
	
	void main(){
		dfs(1);
		cout << ans;
	}
}

namespace subA{
	LL ans;
	
	void main(){
		ans = 1;
		rep(i, 2, n) ans = ans * i % mod;
		cout << ans;
	}
}

namespace sub15{
	void main(){
		cout << "0";
	}
}

namespace subm1{
	int pos;
	LL ans, cnt;
	
	void main(){
		rep(i, 1, n){
			if(s[i] == '1'){
				pos = i;
				break;
			}
		}
		
		rep(i, 1, n){
			if(c[i] >= pos) cnt ++;
		}
		
		ans = 1;
		rep(i, 2, n - 1) ans = ans * i % mod;
		cout << ans * cnt % mod;
	}
}

signed main(){
# ifndef LOCAL
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
# endif
//	freopen("employ2.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int now = 0;
	cin >> n >> m >> s + 1;
	
	rep(i, 1, n){
		cin >> c[i];
		if(s[i] == '0') fA = false;
		else now ++;
	}
	
	if(now < m){
		cout << "0";
		return 0;
	}
	
	if(n <= 10){
		sub12::main();
		return 0;
	}
	
	if(m == 1){
		subm1::main();
		return 0;
	}
	
	if(fA){
		subA::main();
		return 0;
	}
	
	if(m == n){
		sub15::main();
		return 0;
	}
	
	return 0;
}