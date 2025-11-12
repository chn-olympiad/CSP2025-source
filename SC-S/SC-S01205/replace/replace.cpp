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

const int N = 2e5 + 10, P = 13331;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = 1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int n, q, sum, ans, len;
ULL hs[N][3], p[2010];
string t[3], s[N][3];
vec<ULL> ht[3];
map<ULL, vec<ULL>> mp;

namespace sub15{
	ULL query(vec<ULL> &a, int l, int r){
		if(!l) return a[r];
		return a[r] - a[l - 1] * p[r - l + 1];
	}
	
	void main(){
		p[0] = 1;
		rep(i, 1, 2000) p[i] = p[i - 1] * P;
		
		while(q --){
			ans = 0;
			cin >> t[1] >> t[2];
			len = t[1].size();
			ht[1].resize(t[1].size() + 1, 0);
			ht[2].resize(t[2].size() + 1, 0);
			ht[1][0] = (int)t[1][0];
			ht[2][0] = (int)t[2][0];
			
			rep(i, 1, t[1].size() - 1){
				ht[1][i] = ht[1][i - 1] * P + (int)t[1][i];
				ht[2][i] = ht[2][i - 1] * P + (int)t[2][i];
			}
			
			int l = 0, r = len - 1;
			while(t[1][l] == t[2][l]) l ++;
			l --;
			while(t[1][r] == t[2][r]) r --;
			r ++;
//			cout << l << " " << r << "\n";
			rep(i, 0, l + 1){
				rep(j, r - 1, len - 1){
					ULL val = query(ht[1], i, j), val2 = query(ht[2], i, j);
//					cout << i << " " << j << " " << val << " " << val2 << "\n";
					if(!mp.count(val)){
						continue;
					}
					
					for(auto x : mp[val]){
						if(x == val2) ans ++;
					}
				}
			}
			
			cout << ans << "\n";
		}
	}
}

signed main(){
# ifndef LOCAL
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
# endif
//	freopen("replace.in", "r", stdin);
//	freopen("my.out", "w", stdout)
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	
	rep(i, 1, n){
		cin >> s[i][1] >> s[i][2];
		len = s[i][1].size();
		sum += 2 * len;
		hs[i][1] = (int)s[i][1][0];
		hs[i][2] = (int)s[i][2][0];
		
		rep(j, 1, s[i][1].size() - 1){
			hs[i][1] = hs[i][1] * P + (int)s[i][1][j];
			hs[i][2] = hs[i][2] * P + (int)s[i][2][j];
		}
		
//		cout << i << " " << hs[i][1] << " " << hs[i][2] << "\n";
		mp[hs[i][1]].pb(hs[i][2]);
	}
	
	if(sum <= 2000){
		sub15::main();
		return 0;
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0
*/