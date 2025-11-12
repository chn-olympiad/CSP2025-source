#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
template<typename T>void cmax(T &x, T y){x = max(x, y);}
template<typename T>void cmin(T &x, T y){x = min(x, y);}
const int N = 505, mod = 998344353;
void Add(int &x, int y){x += y; if(x >= mod) x -= mod;}
void Sub(int &x, int y){x += mod - y; if(x >= mod) x -= mod;}
int n, m, pre[N], sum[N], c[N], dp[19][1 << 18];
string s;
void solve_special(){
	if(m == n){
		For(i, 1, n) if(s[i] == '0') cout << 0 << '\n', exit(0);
		For(i, 1, n) if(c[i] == 0) cout << 0 << '\n', exit(0);
		int ans = 1;
		For(i, 1, n) ans = ans * i % mod;
		cout << ans << '\n'; exit(0);
	}
}
void Solve(){
	cin >> n >> m >> s; s = ' ' + s;
	For(i, 1, n) pre[i] = pre[i - 1] + s[i] - '0';
	For(i, 1, n) cin >> c[i], pre[c[i]]++;
	For(i, 1, n) pre[i] = pre[i - 1] + c[i];
	For(i, 1, n) sum[i] = sum[i - 1] + s[i] - '0';
	if(n > 18) solve_special();
	int ans = 0; int U = (1 << n) - 1;
	dp[0][0] = 1;
	For(i, 0, n) For(S, 0, U){
		int val = dp[i][S];
		if(!val) continue;
		int rk = __builtin_popcount(S);
		For(j, 1, n) if(!((S >> j - 1) & 1)){
			int T = S | (1 << j - 1);
			if(s[rk + 1] == '0') Add(dp[i + 1][T], dp[i][S]);
			else{
				if(c[j] <= i) Add(dp[i + 1][T], dp[i][S]);
				else Add(dp[i][T], dp[i][S]);
			}
		}
	}
	For(i, m, n) Add(ans, dp[n - i][U]);
	cout << ans << '\n';
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1; //cin >> T;
	while(T--) Solve();
	return 0;
}

