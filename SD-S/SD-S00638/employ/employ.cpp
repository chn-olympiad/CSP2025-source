#include<bits/stdc++.h>
#define int long long
#define ll long long
#define PII pair<int, int>
#define Kg putchar(' ')
#define Ed putchar('\n')
bool __begin__;
using namespace std;
const ll N = 510, inf = 1e9, INF = 1e18, p = 998244353;
template<class T> inline void read(T &x){x = 0;int f = 1;char ch = getchar();for(; ch < '0' || ch > '9'; ch = getchar()){if(ch == '-'){f = -1;}}for(; ch >= '0' && ch <= '9'; ch = getchar()){x = (x << 3) + (x << 1) + (ch ^ 48);}x *= f;}
template<class T> inline void print(T x){if(x < 0){putchar('-'), print(-x);}else if(x < 10){putchar(x ^ 48);}else{print(x / 10), putchar((x % 10) ^ 48);}}
int n, m;
char s[N];
int c[N];
int dp[1000010][20];
int ans;
void solve1(){
	dp[0][0] = 1;
	for(int i = 0; i < 1 << n; i++){
		int su = 0;
		for(int j = 1; j <= n; j++) su += (i >> (j - 1) & 1);
		for(int j = 1; j <= n; j++){
			if(i >> (j - 1) & 1) continue;
			for(int k = 0; k <= su; k++){
				(dp[i | (1 << (j - 1))][k + (su - k < c[j] && s[su + 1] == '1')] += dp[i][k]) %= p;
			}
		}
	}
	for(int i = m; i <= n; i++) (ans += dp[(1 << n) - 1][i]) %= p;
	print(ans);
}
void solve2(){
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			print(0);
			return;
		}
	}
	ans = 1;
	for(int i = 1; i <= n; i++) (ans *= i) %= p;
	print(ans);
}
bool __end__;
signed main(){
//	printf("%dMB", (int)(&__begin__ - &__end__) >> 20);
//	freopen("employ3.in", "r", stdin);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n), read(m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) read(c[i]);
	if(n <= 18) solve1();
	else if(m == n) solve2();
	else solve1();
//	else if(m == 1) solve3();
	return 0;
}
/*
19 19
1111111111111111111
1 2 3 4 5 2 1 4 2 3 4 2 4 2 2 4 1 1 13
*/
