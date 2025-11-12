#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;
inline int read()
{
	int s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
const int mod = 998244353;
int n, m, jc[503];
char ch[503];
int s[503];
int a[503], ans = 0, cnt, ct;
int c[503], t[503];
inline void solve1()
{
	cnt = 0;
	for(int i = 1;i <= n;++ i)
	{
		if(s[i]) a[++ cnt] = i;
	}
	for(int i = 1;i <= n;++ i) ++ t[c[i]];
	for(int i = 1;i <= n;++ i) t[i] += t[i - 1];
	ans = jc[n - cnt];
	for(int i = 1;i <= cnt;++ i)
	{
		if(t[a[i] - 1] == 0)
		{
			ans = 0;
			break;
		}
		ans = (ll)ans * t[a[i] - 1] % mod;
		for(int j = a[i];j <= n;++ j) -- t[j];
	}
	ans = (jc[n] - ans + mod);
	if(ans >= mod) ans -= mod;
	cout << ans << '\n';
}
inline void solve2()
{
	for(int i = 1;i <= n;++ i)
	{
		if(s[i] == 0 || c[i] == 0) return (void)puts("0");
	}
	cout << jc[n] << '\n';
}
int f[500004][19];
inline int C(int x)
{
	ct = 0;
	while(x) ct += (x & 1), x >>= 1;
	return ct;
}
inline void solve0()
{
	f[0][0] = 1;for(int i = 1;i <= n;++ i) f[0][i] = 0;
	int N = (1 << n);
	for(int i = 1;i < N;++ i)
	{
		cnt = C(i);
		for(int j = 1;j <= n;++ j)
		{
			if(i & (1 << (j - 1)))
			{
				for(int k = 0;k < cnt;++ k)
				{
					if(c[j] <= cnt - 1 - k)
					{
						f[i][k] += f[i ^ (1 << (j - 1))][k];
						if(f[i][k] >= mod) f[i][k] -= mod;
						continue;
					}
					f[i][k + s[cnt]] += f[i ^ (1 << (j - 1))][k];
					if(f[i][k + s[cnt]] >= mod) f[i][k + s[cnt]] -= mod;
				}
			}
		}
	}
	ans = 0;
	for(int i = m;i <= n;++ i)
	{
		ans += f[N - 1][i];
		if(ans >= mod) ans -= mod;
	}
	cout << ans << '\n';
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read(), jc[0] = 1;
	for(int i = 1;i <= n;++ i) jc[i] = (ll)i * jc[i - 1] % mod;
	scanf("%s", ch + 1);
	for(int i = 1;i <= n;++ i) c[i] = read();
	for(int i = 1;i <= n;++ i) s[i] = (ch[i] == 49);
	if(n <= 18) return solve0(), 0;
	if(m == 1) return solve1(), 0;
	if(n == m) return solve2(), 0;
	cnt = 0;
	for(int i = 1;i <= n;++ i) cnt += s[i];
	if(cnt < m) return puts("0"), 0;
	return 0;
}
