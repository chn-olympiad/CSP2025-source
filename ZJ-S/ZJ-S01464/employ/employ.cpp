#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505 , MOD = 998244353;
const int V = 1050;
int n , m , a[N] , cnt[N] , pre[N] , f[N][N];
int fac[V] , c[V][V];
string s;
void Init(const int n = V - 5)
{
	fac[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		fac[i] = (ll)fac[i - 1] * i % MOD;
	for(int i = 0 ; i <= n ; i++)
	{
		c[i][0] = c[i][i] = 1;
		for(int j = 1 ; j < i ; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}
}
inline void add(int &x , const int &y){if((x += y) >= MOD)x -= MOD;}
namespace BF
{
	const int N = 20 , S = 1 << 18;
	int f[S][N];
	void Solve()
	{
		f[0][0] = 1;
		int U = ((1 << n) - 1);
		for(int s = 0 ; s + 1 < (1 << n) ; s++)
		{
			int m = __builtin_popcount(s);
			if(::s[m + 1] == '1')
			{
				for(int i = 0 ; i < n ; i++)
					if(~s >> i & 1)
					{
						for(int j = 0 ; j < a[i + 1] ; j++)
							add(f[s | 1 << i][j] , f[s][j]);
						for(int j = a[i + 1] ; j <= m ; j++)
							add(f[s | 1 << i][j + 1] , f[s][j]);
					}
			}
			else
			{
				for(int i = 0 ; i < n ; i++)
					if(~s >> i & 1)
						for(int j = 0 ; j <= m ; j++)
							add(f[s | 1 << i][j + 1] , f[s][j]);
			}
		}
		int ans = 0;
		for(int i = 0 ; i <= n - m ; i++)
			add(ans , f[U][i]);
		cout << ans << "\n";
		return ;
	}
}
namespace M1
{
	void Solve()
	{
		ll ret = 1 , c[2] = {};
		for(int i = 1 ; i <= n ; i++)
		{
			c[s[i] - '0']++;
			if(s[i] == '1')
			{
				int x = pre[i - 1] , y = c[1];
				// cerr << i << ' ' << x << ',' << y << " " << ret << "\n";
				if(x < y)
				{
					ret = 0;
					break ;
				}
				else
				{
					ret = ret * (x - y + 1) % MOD;
					// cerr << "  * " << (x - y + 1) << "\n";
				}
			}
		}
		// cerr << "  * " << c[0] << "!\n";
		ret = (ll)ret * fac[c[0]] % MOD;
		// cerr << fac[n] << " - " << ret << "\n";
		cout << (fac[n] - ret + MOD) % MOD << "\n";
		return ;
	}
}
namespace MN // depend on S1
{
	void Solve()
	{
		int mn = n;
		for(int i = 1 ; i <= n ; i++)
			mn = min(mn , a[i]);
		if(count(s.begin() , s.end() , '1') == n &&	mn > 0)
			cout << fac[n] << "\n";
		else cout << "0\n";
		return ;
	}
}
namespace S1
{
	int f[N][N];
	inline int F(int n , int m){return m == 0 ? 1 : c[m + n][n];}
	void Solve()
	{
		int ans = 0;
		f[0][0] = fac[cnt[0]];
		for(int i = 0 ; i <= n ; i++)
		{
			if(i < n)
			{
				for(int j = i ; j < pre[i] ; j++)
				{
					for(int k = 0 ; k <= cnt[i + 1] ; k++)
					{
						int t = cnt[i + 1] - k;
						add(f[i + 1][j + k + 1] , (ll)f[i][j] * fac[cnt[i + 1]] % MOD
							* F(j , k) % MOD * F(pre[i] - j - 1 , t) % MOD);
					}
				}
			}
			if(i <= n - m)// bu lu = i
			{
				int j = pre[i] , k = n - pre[i];
				// cerr << i << ':' << f[i][j] << '*' << fac[k] << '*' << F(j , k) << '\n';
				add(ans , (ll)f[i][j] * fac[k] % MOD * F(j , k) % MOD);
				// int j = pre[i] , k = cnt[i + 1];
				// add(f[i + 1][j + k] , (ll)f[i][j] * F(j , k) % MOD);
			}
		}
		cout << ans << "\n";
		return ;
	}
}
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	Init();
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	pre[0] = cnt[0];
	for(int i = 1 ; i <= n ; i++)
		pre[i] = pre[i - 1] + cnt[i];
	// S1::Solve();
	// BF::Solve();
	if(count(s.begin() , s.end() , '1') == n)
		S1::Solve();
	else if(n <= 18)BF::Solve();
	else if(m == 1)M1::Solve();
	else if(m == n)MN::Solve();
	return 0;
}