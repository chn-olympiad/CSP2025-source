#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define int long long

const int N = 510, MOD = 998244353;

int n, k;
int s[N], c[N], id[11];

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while ( c < '0' || c > '9' )
	{
		if ( c == '-' )
			f = -1;
		c = getchar();
	}
	while ( c >= '0' && c <= '9' )
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if ( x < 0 ) putchar('-'), x = -x;
	if ( x > 9 ) write(x / 10);
	putchar(x % 10 + '0');
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = read(), k = read();
	
	bool flagA = 1;
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%1d", &s[i]);
		if ( s[i] != 1 )
			flagA = 0;
	}
	for (int i = 1; i <= n; i ++ )
		c[i] = read();
		
	if ( flagA )
	{
		int fac = 1;
		for (int i = 1; i <= n; i ++ )
			fac = (fac % MOD * i % MOD) % MOD;
		write(fac);
		return 0;
	}	
		
	for (int i = 1; i <= n; i ++ ) id[i] = i;
	if ( n <= 10 )
	{
		int ans = 0;
		do
		{
			int cnt = 0, t = 0;
			for (int i = 1; i <= n; i ++ )
			{
				if ( cnt >= c[id[i]] ) continue;
				if ( s[i] == 0 ) cnt ++;
				if ( s[i] == 1 ) t ++;
			}
			if ( t == k )
				ans = (ans + 1) % MOD;
		} while ( next_permutation(id + 1, id + n + 1));
		write(ans);
		return 0;
	}

	return 0;
}
