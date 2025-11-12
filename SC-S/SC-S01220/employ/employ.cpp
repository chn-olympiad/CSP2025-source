#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 505, mod = 998244353;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
		  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
	  write(x / 10);
	putchar(x % 10 + '0');
}
int n, m, flagA = 1;
int p[N];
int dp[20][20][(1 << 18) + 1];
char s[N];
int c[N];
inline void getadd(int &x, int y){
	x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i){
		c[i] = read();
		flagA &= (s[i] == '1');
	}
	if(n <= 10){
		for(int i = 1; i <= n; ++i)
		  p[i] = i;
		int ans = 0;
		while(1){
			int lim = 0, sum = 0;
			for(int i = 1; i <= n; ++i){
				if(lim >= c[p[i]]){
					++lim;
					continue;
				}
				if(s[i] == '1')
				  ++sum;
				else
				  ++lim;
			}
			ans += (sum >= m);
			if(!next_permutation(p + 1, p + n + 1))
			  break;
		}
		write(ans);
		return 0;
	}
	if(n <= 18){
		// dp[i][j][S]
		dp[0][0][0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int S = 0; S < (1 << n); ++S){
				for(int k = 1; k <= n; ++k){
					if((S >> (k - 1)) & 1)
					  continue;
					if(s[i] == '0'){
						for(int j = 0; j < i; ++j)
						  getadd(dp[i][j + 1][S | (1 << (k - 1))], dp[i - 1][j][S]);
					}
					else{
						for(int j = c[k]; j < i; ++j)
						  getadd(dp[i][j + 1][S | (1 << (k - 1))], dp[i - 1][j][S]);
						for(int j = 0; j < c[k]; ++j)
						  getadd(dp[i][j][S | (1 << (k - 1))], dp[i - 1][j][S]);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i <= n - m; ++i)
		  getadd(ans, dp[n][i][(1 << n) - 1]);
		write(ans);
		return 0;
	}
	if(m == n){
		for(int i = 1; i <= n; ++i)
		  flagA &= (c[i] > 0);
		if(flagA){
			int ans = 1;
			for(int i = 1; i <= n; ++i)
			  ans = 1ll * ans * i % mod;
			write(ans); 
		}
		else
		  write(0);
		return 0;
	}
	for(int i = 1; i <= n; ++i)
	  flagA &= (c[i] > 0);
	if(flagA){	
		int ans = 1;
		for(int i = 2; i <= n; ++i)
		  ans = 1ll * ans * i % mod;
		write(ans);
		return 0;
	}
	int num = 0;
	for(int i = 1; i <= n; ++i)
	  num += s[i] == '1';
	if(num < m){
		puts("0");
		return 0;
	}
	puts("1"); 
	return 0;
}