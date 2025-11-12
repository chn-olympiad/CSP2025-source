#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<string, int> vis;
	unordered_map<string, string> ch;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		vis[s1]++;
		ch[s1] = s2;
	}
	while (m--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		bool f = 0;
		int idx1 = 0, idx2 = 0;
		long long cnt = 0;
		for (int i = 0; i < s1.size(); i++)
			if (!f && s1[i] != s2[i])
				f = 1, idx1 = i;
		f = 0;
		for (int i = s1.size(); i >= 0; i--)
			if (!f && s1[i] != s2[i])
				f = 1, idx2 = i;
		for (int i = 0; i <= idx1; i++)
			for (int j = idx2; j < s1.size(); j++)
			{
				string s = s1.substr(i, j - i + 1);
				string t = s2.substr(i, j - i + 1);
				if (vis[s] && ch[s] == t)
					cnt += vis[s];
			}
		cout << cnt << '\n';
	}
	return 0;
}
