#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, M = 1e7 + 5;

int n, q, delta = 5e6;
int d[N];
string s[N][2];
vector<int> tr[M];
map<int, int> mp;

int calc(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'b') return i;
	return ((int)s.size() - 1);
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	if (n <= 100 && q <= 100)
	{
		while (q--)
		{
			string st, ed;
			cin >> st >> ed;
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j + s[i][0].size() - 1 < st.size(); j++)
				{
					string now = st.substr(j, s[i][0].size()), now2 = ed.substr(j, s[i][0].size());
					if (!(now == s[i][0] && now2 == s[i][1])) continue;
					bool flag = 1;
					for (int k = 0; k < st.size(); k++)
					{
						if (k < j || k > j + s[i][0].size() - 1)
						{
							if (st[k] != ed[k])
							{
								flag = 0;
								break;
							}
						}
					}
					if (flag) ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	else // B
	{
		for (int i = 1; i <= n; i++)
		{
			int x1 = calc(s[i][0]), x2 = calc(s[i][1]);
			d[i] = x1 - x2 + delta;
			mp[d[i]] = 1;
			tr[d[i]].push_back(i);
		}
		while (q--)
		{
			string st, ed;
			cin >> st >> ed;
			int ans = 0;
			int x1 = calc(st), x2 = calc(ed), x3 = (int)(st.size()) - x1 - 1, x4 = (int)(st.size()) - x2 - 1;
			int dd = x1 - x2 + delta;
			if (mp.count(dd))
			{
				for (int tmp : tr[dd])
				{
					int y1 = calc(s[tmp][0]), y2 = calc(s[tmp][1]), y3 = (int)(s[tmp][0].size()) - y1 - 1, y4 = (int)(s[tmp][1].size()) - y2 - 1;
					if (x1 >= y1 && x2 >= y2 && x3 >= y3 && x4 >= y4) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
