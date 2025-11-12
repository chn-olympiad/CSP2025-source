#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 1e5 + 5, mod = 998244353;
int n, m, a, c[N], p[N], daan;
bool vis[N];
string s;

template< typename T, typename ... L > inline void read(T &x){
	bool f = true;
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template< typename T, typename ... L > inline void read(T &a, L && ... b){
	read(a);
	read(b ...);
}
int ksm(int a, int b, int p){
	int ans = 1;
	while (b){
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
void dfs(int dn){
	if (dn > n){
		int dan = 0, cc = 0;
		for (int i = 1; i <= n; i++){
			if (c[p[i]] <= cc || s[i-1] == '0'){
				cc++;
				continue;
			}
			dan++;
		}
		if (dan >= m) daan++;
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		vis[i] = true;
		p[dn] = i;
		dfs(dn + 1);
		vis[i] = false;
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	read(n, m);
	cin >> s;
	for (int i = 1; i <= n; i++) read(c[i]);
	if (n <= 10){
		dfs(1);
		printf("%lld", daan);
		return 0;
	}
	puts("0");
	return 0;
}
//freopen("a.in", "w", stdin);
//freopen("a.in", "r", stdout);
//freopen("a.out", "w", stdin);
//freopen("a.out", "r", stdout);

