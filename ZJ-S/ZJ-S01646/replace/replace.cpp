#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 200010, base = 13331;

int n, q;
string s[2][N];
ULL h[2][N], p[N];
ULL g[2][N];

ULL get(ULL h[], int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i < N; i ++ ) p[i] = p[i - 1] * base;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> s[0][i] >> s[1][i];
		for (int j = 1; j <= s[0][i].size(); j ++ )
		{
			h[0][i] = h[0][i] * base + s[0][i][j - 1] - 'a' + 1;
			h[1][i] = h[1][i] * base + s[1][i][j - 1] - 'a' + 1;
		}
	}
	
	while (q -- )
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			puts("0");
			continue;
		}
		int l, r;
		for (int i = 0; i < t1.size(); i ++ )
		{
			g[0][i] = g[0][i - 1] * base + t1[i - 1] - 'a' + 1;
			g[1][i] = g[1][i - 1] * base + t2[i - 1] - 'a' + 1;
		}
		for (int i = 0; i < t1.size(); i ++ ) if (t1[i] != t2[i])
		{
			l = i + 1;
			break;
		}
		for (int i = t1.size() - 1; i >= 0; i -- ) if (t1[i] != t2[i])
		{
			r = i + 1;
			break;
		}
		int res = 0;
		for (int i = r; i <= t1.size(); i ++ )
			for (int j = 1; i <= n; i ++ )
				if (i - s[0][j].size() + 1 <= l)
					if (get(g[1], i - s[0][j].size() + 1, i) == h[1][j])
						res ++ ;
						
		cout << res << endl;
	}
	
	return 0;
}
