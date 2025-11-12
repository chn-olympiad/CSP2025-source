#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, q;
string s[N], t[N], u, v;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (register int i = 1;i <= n; i = -~i)
	{
		cin >> s[i] >> t[i];
	}
	while (q --)
	{
		cin >> u >> v;
		int cnt = 0, ss = u.size(), cnt2 = 0;
		for (register int i = 0;i < ss;i = -~i)
		{
			for (register int j = i;j < ss; j = -~j)
			{
				string c, cc;
				bool f = 0;
				for (register int k = 0;k < i; k = -~k)
				{
					if (u[k] != v[k]){f = 1;break;}
					//cout << u[k];
				}
				//cout << "\n";
				for (register int k = j + 1;k < ss; k = -~k)
				{
					if (u[k] != v[k]){f = 1;break;}
				}
				
				if (f){continue;}++ cnt2;
				//cout << i << " " << j << "\n";
				for (register int k = i;k <= j; k = -~k) c.push_back(u[k]);
				for (register int k = i;k <= j; k = -~k) cc.push_back(v[k]);
				for (register int k = 1;k <= n; k = -~k)
				{
					if (c == s[k] && cc == t[k])
					{
						++ cnt;
					}
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
