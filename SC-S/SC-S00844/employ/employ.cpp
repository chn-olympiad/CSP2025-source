#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9'){(c == '-') && (st = -1); c = getchar();}
	while(c >= '0' && c <= '9'){s = (s << 3) + (s << 1) + (c ^ 48); c = getchar();}
	x = s * st;
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
//#define int long long
#define LL long long
#define PII pair<int, int>
const int Mod = 998244353;
LL f[15][1005][15];
int a[15], c[15];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	read(n), read(m);
	for(int i = 1; i <= n; ++i){
		char ch = getchar();
		while(ch < '0' || ch > '1') ch = getchar();
		a[i] = ch - 48;
	}
	for(int i = 1; i <= n; ++i){
		read(c[i]);
	}
	int S = (1 << n) - 1;
	f[0][0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= S; ++j){
			if(__builtin_popcount(j) != i) continue;
			for(int k = 1; k <= n; ++k){
				if((1 << k - 1 & j) == 0) continue;
				for(int l = 0; l <= i; ++l){
					if(a[i] != 0){
						if(l < c[k]) f[i][j][l] = (f[i][j][l] + f[i - 1][j ^ (1 << k - 1)][l]) % Mod;
						else if(l > 0) f[i][j][l] = (f[i][j][l] + (f[i - 1][j ^ (1 << k - 1)][l - 1])) % Mod;
					}
					else{
						if(l > 0) f[i][j][l] = (f[i][j][l] + f[i - 1][j ^ (1 << k - 1)][l - 1]) % Mod;
					}
					
				}
			}
		}
	}
	/*
	for(int i = 1; i <= 3; ++i){
		for(int j = 0; j <= S; ++j){
			if(__builtin_popcount(j) != i) continue;
			for(int k = 0; k <= i; ++k){
				cerr << j << ' ' << i << ' ' << k << ' ' << f[i][j][k] << '\n';
			}
		}
	}
	*/
	LL ans = 0;
	for(int i = 0; i <= n - m; ++i){
		ans = (ans + f[n][S][i]) % Mod;
	}
	write(ans);
	return 0;
}
