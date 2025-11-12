#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long;
const int N = 510;
const int mod = 998244353, base = 233;
const double eps = 1e-8;
ll n, m, sum, x, c[N], p[N], jc[N], divs[N], ans;
bool vis[N];
string s;
inline ll read(){
	ll x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * m;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void Freopen(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
}
inline ll ksm(ll x, ll y){
	ll ans = 1;
	while(y){
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
inline void init(){
	for(int i = jc[0] = 1; i <= n; ++ i) jc[i] = jc[i - 1] * i % mod;
	divs[n] = ksm(jc[n], mod - 2);
	for(int i = n - 1; i >= 0; -- i) divs[i] = divs[i + 1] * (i + 1) % mod;
}
inline bool check(){
	int ban = 0, cnt = 0;
	for(int i = 1; i <= n; ++ i){
		if(s[i] == '0' || ban >= c[p[i]]){
			++ ban;
			continue;
		}
		++ cnt;
	}
	return cnt >= m;
}
inline void dfs(int dep){
	if(dep > n) return ans += check(), void();
	for(int i = 1; i <= n; ++ i){
		if(vis[i]) continue;
		p[dep] = i, vis[i] = 1;
		dfs(dep + 1);
		vis[i] = 0;
	}
}
inline void solve(){
	n = read(), m = read();
	init();
	cin >> s, s = " " + s;
	for(int i = 1; i <= n; ++ i) sum += s[i] - 48;
	for(int i = 1; i <= n; ++ i) c[i] = read(), x += (c[i] > 0);
	if(sum < m) return write(0), void();
	if(m == 1) return write(x * jc[n - 1] % mod), void();
	if(m == n){
		if(x != n) write(0);
		else write(jc[n]);
		return;
	}
	if(sum == n){
		if(x >= m) write(jc[n]);
		else write(0);
		return;
	}
	if(n <= 10){
		dfs(1), write(ans);
		return;
	}
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}

