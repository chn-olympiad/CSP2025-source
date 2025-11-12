#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N = 1e5 + 10;
const int mod = 1e9 + 7, base = 233;
const double eps = 1e-8;
ll n, ans, a[N][4], cnt[4], b[N];
priority_queue<ll> q;
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
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
inline void work(int op){
	int op1, op2, sum = cnt[op] - n / 2;
	if(op == 1) op1 = 2, op2 = 3;
	if(op == 2) op1 = 1, op2 = 3;
	if(op == 3) op1 = 1, op2 = 2;
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; ++ i) if(b[i] == op) q.push(-min(a[i][op] - a[i][op1], a[i][op] - a[i][op2]));
	while(sum --) ans += q.top(), q.pop();
}
inline void solve(){
	n = read(), ans = 0;
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= 3; ++ j) a[i][j] = read();
	for(int i = 1; i <= n; ++ i){
		ll maxn = -1;
		for(int j = 1; j <= 3; ++ j) if(a[i][j] > maxn) maxn = a[i][j], b[i] = j;
		++ cnt[b[i]], ans += maxn;
	}
	if(cnt[1] > n / 2) work(1);
	else if(cnt[2] > n / 2) work(2);
	else if(cnt[3] > n / 2) work(3);
	write(ans), putchar('\n'); 
}
signed main(){
	Freopen();
	int T = 1;
	T = read();
	while(T --) solve();
	return 0;
}

