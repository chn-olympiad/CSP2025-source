// employ

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 505;

int n, m;
char s[N];
int c[N];
int p[N];

signed main()
{
	freopen("employ.in" , "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> s[i];
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	
	int ans = 0;
	do
	{
		int cnt = 0;
		int res = 0;
		for (int i = 1; i <= n; i ++)
		{
			int u = p[i];
			if (s[i] == '0')
			{
				cnt ++;
			}
			else
			{
				if (cnt >= c[u])
				{
					cnt ++;
					continue;
				}
				res ++;
				if (res >= m)
					break;
			}
		}
		if (res >= m)
			ans ++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << '\n';
	
	return 0;
}
