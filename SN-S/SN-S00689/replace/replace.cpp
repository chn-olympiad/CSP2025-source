#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5, M = 5e6 + 5;
int n, q, len[N];
string s[N][2], t[2];

#define uns unsigned
#define i64 long long
constexpr uns i64 base = 131;
uns i64 bsp[M], has[N][2], has1[M], has2[M];
uns i64 query(int l, int r, uns i64 *htb)
{
	if (l > r)
	{
		return 0;
	}
	return htb[r] - htb[l - 1] * bsp[r - l + 1];
}

int main()
{
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	bsp[0] = 1;
	for (int i = 1; i < M; ++ i)
	{
		bsp[i] = bsp[i - 1] * base;
	}
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; ++ i)
	{
		cin >> s[i][0] >> s[i][1];
		
		len[i] = s[i][0].size();
		for (int j = 0; j < len[i]; ++ j)
		{
			has[i][0] = has[i][0] * base + s[i][0][j];
			has[i][1] = has[i][1] * base + s[i][1][j];
		}
	}
	
	for (int _ = 0; _ < q; ++ _)
	{
		cin >> t[0] >> t[1];
		
		if (t[0].size() != t[1].size())
		{
			cout << "0\n";
			continue;
		}
		
		int tlen = t[0].size();
		for (int i = 0; i < tlen; ++ i)
		{
			has1[i] = has1[i - 1] * base + t[0][i];
			has2[i] = has2[i - 1] * base + t[1][i];
		}
		
		int ans = 0;
		for (int i = 0; i < tlen; ++ i)
		{
			for (int j = 1; j <= n; ++ j)
			{
				if (i + len[j] - 1 < tlen)
				{
					if (query(0, i - 1, has1) == query(0, i - 1, has2))
					{
						if (query(i + len[j], tlen - 1, has1) == query(i + len[j], tlen - 1, has2))
						{
							if (query(i, i + len[j] - 1, has1) == has[j][0] && query(i, i + len[j] - 1, has2) == has[j][1])
							{
								++ ans;
							}
						}
					}
				}
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}
