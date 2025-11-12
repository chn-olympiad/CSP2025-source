//首先看到数据范围考虑枚举最大值
//接下来我们需要在前i-1个数里面选一些数使得和>2*l_i
//考虑正难则反，计算和<=2*l_i的方案数
//这个可以直接DP预处理
//因为我们第二维只需要开到10^4即可 
//5e7应该是稳过的了
//算空间400MB左右，可以通过
//刚才突然发现还要保证m >= 3
//但是我们是升序排好序的
//所以发现只要满足第二个条件，选的数个数一定是大于等于3的
//但是其实柿子可以移项，这样j只需要开5000了 
//每次直接2^{i-1}-f之和即可 
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define N 5005
#define mod 998244353

int n, a[N], f[N][N], ans;

int qpow(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)ans = ans * a % mod;
		a = a * a % mod, b >>= 1; 
	}
	return ans % mod;
} 

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 5000; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= a[i])f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
		}
	for(int i = 3; i <= n; i++)
	{
		ans = (ans + qpow(2ll, i - 1)) % mod;
		for(int j = 0; j <= a[i]; j++)
			ans = ((ans - f[i - 1][j]) % mod + mod) % mod;
	}
	cout << ans;
	return 0;
} 
