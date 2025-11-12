#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

#define v first
#define id second

int T;
int n;
bool st1[N] = {0}, st2[N] = {0};
int a1[N], a2[N], a3[N];

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

int res = 0, ans1 = 0;
void dfs1(int u)
{
	if ( u > n )
	{
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if ( st1[i] ) cnt1 ++;
			if ( st2[i] ) cnt2 ++;
		}	
		if ( cnt1 > n / 2 || cnt2 > n / 2 ) return ;
		for (int i = 1; i <= n; i ++ )
		{
			if ( st1[i] ) res += a1[i];
			if ( st2[i] ) res += a2[i];
		}
		ans1 = max(ans1, res);
		res = 0;
		return ;
	}
	
	st1[u] = 1;
	st2[u] = 0;
	dfs1(u + 1);
	st1[u] = 0;
	st2[u] = 1;
	dfs1(u + 1);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = read();
	
	while ( T -- )
	{
		n = read();
		bool flagA = 1, flagB = 1;
		for (int i = 1; i <= n; i ++ )
		{
			a1[i] = read(), a2[i] = read(), a3[i] = read();
			if ( a2[i] != 0 ) flagA = 0;
			if ( a3[i] != 0 ) flagA = flagB = 0;
		}
		
		if ( n == 2 )
		{
			int ans = 0;
			ans = max(a1[1] + a2[2], ans);
			ans = max(a1[1] + a3[2], ans);
			ans = max(a2[1] + a1[2], ans);
			ans = max(a2[1] + a1[2], ans);
			ans = max(a3[1] + a1[2], ans);
			ans = max(a3[1] + a2[2], ans);
			write(ans);
			return 0;
		}
		
		if ( flagA )
		{
			priority_queue<int> q;
			int ans = 0;
			for (int i = 1; i <= n; i ++ ) q.push(a1[i]);
			for (int i = 1; i <= n / 2; i ++ )
				ans += q.top(), q.pop();
			write(ans);
			return 0;
		}
		if ( flagB )
		{
			dfs1(1);
			write(ans1);
			memset(st1, 0, sizeof st1);
			memset(st2, 0, sizeof st2);
			return 0;
		}
		else
		{
			priority_queue<int> q;
			int ans = 0;
			for (int i = 1; i <= n; i ++ )
			{
				q.push(a1[i]);
				q.push(a2[i]);
				q.push(a3[i]);
				ans += q.top();
				while ( !q.empty() )
					q.pop();
			}
			return 0;
		}
	}
	return 0;
}
