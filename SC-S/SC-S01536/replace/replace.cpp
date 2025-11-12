#include "bits/stdc++.h"
using namespace std;

#define int long long
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);

vector<string> s[2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	file(replace);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++ i) 
	{
		string x, y;
		cin >> x >> y;
		s[0].push_back(x), s[1].push_back(y);
	}
	
	for (int i = 1; i <= m; ++ i)
	{
		string x, y;
		cin >> x >> y;
		int l = 0, r = x.size() - 1;
		while (x[l] == y[l]) ++ l;
		while (x[r] == y[r]) -- r;
		
		int cnt = 0;
		for (int j = 0; j < n; ++ j) 
		{
			if (s[0][j].size() < r - l + 1) continue;
			int fx = x.find(s[0][j]), fy = y.find(s[1][j]);
			if (fx == x.npos || fy == y.npos) continue;
			if (fx != fy) continue;
			if (fx > l || fx + s[0][j].size() - 1 < r) continue;
			
			cnt ++;
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}