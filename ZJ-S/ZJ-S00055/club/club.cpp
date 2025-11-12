#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int T, n, wos;
struct A
{
	int a, b, c;
}x[N];
A flag;
int cnt;
int ans;

void dfs(int i, int aa, int bb, int cc, int sum)
{
	if (aa > wos || bb > wos || cc > wos)
	{
		return ;
	}
	if (i == n + 1)
	{
		ans = max(ans, sum);
		return ;
	}
	if (flag.a ) dfs(i + 1, aa + 1, bb, cc, sum + x[i].a );
	if (flag.b ) dfs(i + 1, aa, bb + 1, cc, sum + x[i].b );
	if (flag.c ) dfs(i + 1, aa, bb, cc + 1, sum + x[i].c );
}

void K(int k)
{
	if (x[k].a != 0) flag.a = 1;
	if (x[k].b != 0) flag.b = 1;
	if (x[k].c != 0) flag.c = 1;
}

bool cmpa(A x, A y)
{
	return x.a > y.a ;
}

bool cmpb(A x, A y)
{
	return x.b > y.b ;
}

bool cmpc(A x, A y)
{
	return x.c > y.c ;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T --)
	{
		cin >> n;
		flag = {0, 0, 0};
		cnt = 0;
		wos = n / 2;
		for (int i = 1;i <= n; i ++)
		{
			cin >> x[i].a >> x[i].b >> x[i].c ;
			K(i);
		}
		ans = 0;
		cnt = (flag.a + flag.b + flag.c );
		if (cnt == 1)
		{
			if (flag.a)
			{
				sort(x + 1, x + 1 + n, cmpa);
				for (int i = 1;i <= wos; i ++)
				{
					ans += x[i].a ;
				}
			}
			if (flag.b)
			{
				sort(x + 1, x + 1 + n, cmpb);
				for (int i = 1;i <= wos; i ++)
				{
					ans += x[i].b ;
				}
			}
			if (flag.c)
			{
				sort(x + 1, x + 1 + n, cmpc);
				for (int i = 1;i <= wos; i ++)
				{
					ans += x[i].c ;
				}
			}
		}
		else dfs(1, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	
	return 0;
}
