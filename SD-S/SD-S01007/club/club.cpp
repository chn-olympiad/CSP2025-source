#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
template<typename T>void cmax(T &x, T y){x = max(x, y);}
template<typename T>void cmin(T &x, T y){x = min(x, y);}
using pr = array<int, 3>;
const int N = 2e5 + 5;
int n, a[N][3], cnt[3], p[N], w[N], v[N]; bool vis[N];
void Solve(){
	cin >> n;
	For(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
	cnt[0] = cnt[1] = cnt[2] = 0;
	int preans = 0;
	For(i, 1, n){
		int mx = 0, pos = -1;
		For(j, 0, 2) if(a[i][j] > mx) mx = a[i][j], pos = j;
		preans += mx; ++cnt[pos];
	}
	if(max({cnt[0], cnt[1], cnt[2]}) <= n / 2) return cout << preans << '\n', void();
	int ans = 0;
	iota(p + 1, p + n + 1, 1);
	For(op, 0, 2){
		For(i, 1, n){
			int mx = 0;
			For(j, 0, 2) if(j != op) cmax(mx, a[i][j]);
			w[i] = a[i][op] - mx; v[i] = mx;
		}
		sort(p + 1, p + n + 1, [&](int i, int j){return w[i] > w[j];});
		int sum = 0;
		For(i, 1, n / 2) sum += a[p[i]][op];
		For(i, n / 2 + 1, n) sum += v[p[i]];
		cmax(ans, sum);
	}
	cout << ans << '\n';
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1; cin >> T;
	while(T--) Solve();
	return 0;
}
