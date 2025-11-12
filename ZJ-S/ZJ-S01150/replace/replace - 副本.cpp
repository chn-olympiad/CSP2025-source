#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
string t1[MAXN], t2[MAXN];
int cnt = 0, n, q;
map <string, bool> vis;
string change(string s, string be, string to_be)
{
	int cur = 0, x = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == be[0])
		{
			cur++;
			x = i;
			//cout << x << endl;
		}
		else if (s[i] == be[cur++])
		{
			//cout << i << " " << s[i] << endl;
			if (cur - 1 == be.size())
				break;
		}
		else cur = 0, x = -1;
		
	}
	if (x == -1) return "#";
	cur = 0;
	for (int i = x; cur < be.size(); i++)
	{
		s[i] = to_be[cur++];
	}
	return s;
}
bool same(string s1, string s2)
{
	if (s1.size() != s2.size()) return 0;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != s2[i])
			return 0;
	return 1;
}
void dfs(string s1, string s2)
{
	if (same(s1, s2))
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		string cs1 = change(s1, t1[i], t2[i]);
		string cs2 = change(s1, t2[i], t1[i]);
		if (cs1[0] != '#' && !vis[cs1])
		{
			vis[cs1] = 1;
			//cout << cs1 << endl;
			dfs(cs1, s2);
		}
		if (cs2[0] != '#' && !vis[cs2])
		{
			vis[cs2] = 1;
			//cout << cs2 << endl;
			dfs(cs2, s2);
		}
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> t1[i] >> t2[i];
	
	while (q--)
	{
		vis.clear();
		string s1, s2;
		cin >> s1 >> s2;
		cnt = 0;
		dfs(s1, s2);
		cout << cnt << endl;
	}
	return 0;
}
