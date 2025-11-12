#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
string a[N][2];
int n, q;
void solve()
{
	int ans = 0;
	string s1, s2;
	cin >> s1 >> s2;
	queue<string> q;
	q.push(s1);
	while(!q.empty())
	{
		string f = q.front(); q.pop();
		if(f == s2) 
		{
			ans ++;
			continue;
		}
		for(int i = 1; i <= n; i ++)
		{
			int t = 0;
			while((t = f.find(a[i][0], t)) != EOF)
			{
				string ns = f.substr(0, t) + a[i][1] + f.substr(t + a[i][0].size());
				q.push(ns);
				t += a[i][1].size();
			}
		}
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> a[i][0] >> a[i][1];
	for(int i = 1; i <= q; i ++) solve();
	return 0;
}

