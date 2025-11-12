#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node
{
	int a, b, c;
}s[100005];
int ans = 0;
int n;
void dfs(int sum, int x, int a, int b, int c)
{
//	cout << x << " " << sum << endl;
//	if (x == 1 && sum == 0) cout << a << b << c << 1 << endl;
//	else if (x == 2 && sum == 4) cout << a << b <<c << 11 << endl;
//	else if (x == 3 && sum == 8) cout << a << b << c <<111 << endl;
//	else if (x == 4 && sum == 13) cout << a << b<< c << 1111 << endl;
	if (x == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	if (a != n / 2)
	{
		dfs(sum + s[x].a, x + 1, a + 1, b, c);
	}
//	else cout << sum << " " << x << " " << a << " " << b << " " << c << endl;
	if (b != n / 2)
	{
		dfs(sum + s[x].b, x + 1, a, b + 1, c);
	}
//	else cout << sum << " " << x << " " << a << " " << b << " " << c << endl;
	if (c != n / 2)
	{
		dfs(sum + s[x].c, x + 1, a, b, c + 1);
	}
//	else cout << sum << " " << x << " " << a << " " << b << " " << c << endl;
}

bool cmp(Node x, Node y)
{
	return x.a > y.a;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
//		memset(s, 0, sizeof(s));
		bool an, bn, cn;
		an = bn = cn = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].a >>s[i].b >>s[i].c;
			an = an || s[i].a;
			bn = bn || s[i].b;
			cn = cn || s[i].c;
		}
		if ((!cn) && (!bn))
		{
			sort(s + 1, s + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
			{
				ans += s[i].a;
			}
		}
		else dfs(0, 1, 0, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
