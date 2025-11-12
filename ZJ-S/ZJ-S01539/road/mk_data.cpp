#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N = 1e6 + 10;
const int mod = 1e9 + 7, base = 233;
const double eps = 1e-8;

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
	freopen("road6.in", "w", stdout);
}
inline void solve(){
	int n = 5, m = 20, k = 5;
	cout << n << ' ' << m << ' ' << k << '\n';
	srand(time(0));
	for(int i = 2; i <= n; ++ i) cout << i << ' ' << rand() % (i - 1) + 1 << ' ' << rand() % 100 << '\n';
	for(int i = 1; i <= m - n + 1; ++ i){
		int u = rand() % n + 1, v = rand() % n + 1, w = rand() % 100;
		while(u == v) v = rand() % n + 1;
		cout << u << ' ' << v << ' ' << w << '\n';
	}
	for(int i = 1; i <= k; ++ i){
		cout << rand() % 100 << ' ';
		for(int j = 1; j <= n; ++ j) cout << rand() % 100 << ' ';
		cout << endl;
	}
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}

