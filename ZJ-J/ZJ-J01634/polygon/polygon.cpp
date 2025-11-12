#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0');ch = getchar();}
	return sum * p;
}
const int N = 5e3 + 10, MOD = 998244353, M = 5001;
int n, a[N], f[N][N];
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = re();
	for(int i = 1; i <= n; i++) a[i] = re();
	sort(a + 1, a + 1 + n);

	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{	
		for(int j = 0; j <= M; j++) f[i][j] = f[i - 1][j];
		for(int j = M - 1; j >= a[i]; j--) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % MOD;                                                 
		for(int j = M - a[i]; j <= M; j++) f[i][M] = (f[i][M] + f[i - 1][j]) % MOD;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = a[i] + 1; j <= M; j++) 
			ans = (ans + f[i - 1][j]) % MOD;
			
	cout << ans;                   
	return 0;                                
}
