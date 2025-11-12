#include <bits/stdc++.h>

using namespace std;

#define ui unsigned long long

inline int read ()
{
	int x = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9')
		w = (ch == '-' ? -1 : w), ch = getchar ();
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar (); 
	return x * w;
}

const int N = 2e5 + 7, M = 5e6 + 7, B = 998244853, C = 998244353;

int n, q, cnt, num, lrt[N], rrt[N], a[M][26], f[N];

string s, t;

vector <int> vec1[M], vec2[M]; 

map <pair <ui, ui> , int> mp;

signed main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	n = read (), q = read ();
	for (int i = 1; i <= n; ++ i)
	{
		cin >> s >> t;
		int l = 0, r = s.size () - 1;
		while (l < s.size () && s[l] == t[l])
			++ l;
		while (r >= 0 && s[r] == t[r])
			-- r;
		if (l == s.size ())
			continue;
		ui h1 = 0, h2 = 0;
		for (int j = l; j <= r; ++ j)
		{
			h1 = h1 * B + s[j];
			h2 = h2 * C + t[j];
		}
		int x = 0;
		if (mp.find ({h1, h2}) == mp.end ())
			mp[{h1, h2}] = x = ++ cnt, lrt[cnt] = ++ num, rrt[cnt] = ++ num;
		else
			x = mp[{h1, h2}];
		int p = lrt[x];
		for (int i = l - 1; i >= 0; -- i)
		{
			int ch = s[i] - 'a';
			if (!a[p][ch])
				a[p][ch] = ++ num;
			p = a[p][ch];
		}
		vec1[p].push_back (i);
		p = rrt[x];
		for (int i = r + 1; i < s.size (); ++ i)
		{
			int ch = s[i] - 'a';
			if (!a[p][ch])
				a[p][ch] = ++ num;
			p = a[p][ch];
		}
		vec2[p].push_back (i);
	}
	for (int _ = 1; _ <= q; ++ _)
	{
		int res = 0;
		cin >> s >> t;
		if (s.size () != t.size ())
		{
			cout << 0 << '\n';
			continue;
		}
		int l = 0, r = s.size () - 1;
		while (l < s.size () && s[l] == t[l])
			++ l;
		while (r >= 0 && s[r] == t[r])
			-- r;
		ui h1 = 0, h2 = 0;
		for (int j = l; j <= r; ++ j)
		{
			h1 = h1 * B + s[j];
			h2 = h2 * C + t[j];
		}
		if (mp.find ({h1, h2}) == mp.end ())
		{
			cout << 0 << '\n';
			continue;
		}
		
		int x = mp[{h1, h2}];
		int p = lrt[x];
		for (int tmp : vec1[p])
			++ f[tmp];
		for (int i = l - 1; i >= 0; -- i)
		{
			int ch = s[i] - 'a';
			if (!a[p][ch])
				break;
			p = a[p][ch];
			for (int tmp : vec1[p])
				++ f[tmp];
		}
		
		p = rrt[x];
		for (int tmp : vec2[p])
			res += f[tmp];
		for (int i = r + 1; i < s.size (); ++ i)
		{
			int ch = s[i] - 'a';
			if (!a[p][ch])
				break;
			p = a[p][ch];
			for (int tmp : vec2[p])
				res += f[tmp];
		}
		
		p = lrt[x];
		for (int tmp : vec1[p])
			f[tmp] = 0;
		for (int i = l - 1; i >= 0; -- i)
		{
			int ch = s[i] - 'a';
			if (!a[p][ch])
				break;
			p = a[p][ch];
			for (int tmp : vec1[p])
				f[tmp] = 0;
		}
		
		cout << res << '\n';
	}
	return 0;
}
