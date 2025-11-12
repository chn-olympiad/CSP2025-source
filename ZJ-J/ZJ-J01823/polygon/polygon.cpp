#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int mod = 998244353;

int a[N], sum[N];
int n;

long long ans = 0;

long long fac[N];

void init()
{
	fac[1] = 1ll;
	for (int i = 2; i <= 5000; i++)
		fac[i] = (1ll * fac[i - 1] * i % mod + mod) % mod;
}

long long ksm(long long a, int b)
{
	long long res = 1ll;
	
	while (b)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

int qu[N];
int l = 0;
int cnt = 0;

void dfs(int len, int x)
{
	if (x > n || l == len)
	{	
		if (l == len)
		{
			int num = 0;
			int mx = 0;
			
			for (int i = 1; i <= l; i++)
			{
				num += qu[i];
				mx = max(qu[i], mx);
			}
			
			if (num > mx * 2)
				cnt++;
		}
		
		return;
	}
	
	dfs(len, x + 1);
	l++, qu[l] = a[x];
	dfs(len, x + 1);
	l--;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + 1 + n);
	
	if (n <= 3)
	{
		if (n < 3)
			cout << 0;
		else if (a[3] < a[1] + a[2])
			cout << 1;
		else
			cout << 0;
		
		return 0;
	}
	
	else if (a[n] == 1)
	{
		init();
		
		long long ans = 0;
		for (int i = 3; i <= n; i++)
			ans = (ans + fac[n] * ksm((fac[i] * fac[n - i] % mod), mod - 2) % mod) % mod;
			
		cout << ans;
		return 0;
	}
	
	else if (n <= 20)
	{
		for (int i = 3; i <= n; i++)
			dfs(i, 1);
			
		cout << cnt;
		return 0;
	}
	
	return 0;
}