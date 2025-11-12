#include <bits/stdc++.h>
using namespace std;
int n, q;
bool is_special = true;
int res1[200001], res2[200001];
pair<string, string> rp[200001];
int check_special(const string &str)
{
	int res = -1;
	int b_num = 0;
	for (int j = 0; j < str.size(); ++j)
		if (str[j] != 'a' && str[j] != 'b')
		{
			is_special = false;
			break;
		}
		else if (str[j] == 'b')
		{
			res = j;
			++b_num;
			if (b_num > 1)
			{
				is_special = false;
				break;
			}
		}
	if (b_num != 1)
		is_special = false;
	return res;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> rp[i].first >> rp[i].second;
	for (int i = 1; i <= n; ++i)
	{
		res1[i] = check_special(rp[i].first);
		if (!is_special)
			break;
		res2[i] = check_special(rp[i].second);
		if (!is_special)
			break;
	}
	for (int i = 1; i <= q; ++i)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << '\n';
			continue;
		}
		if (is_special)
		{
			int res_1 = check_special(t1);
			int res_2 = check_special(t2);
			if (is_special)
			{
				int ans = 0;
				for (int i = 1; i <= n; ++i)
					if (t1.size() >= rp[i].first.size())
						if (res_1 - res_2 == res1[i] - res2[i])
							++ans;
				cout << ans << '\n';
				continue;
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j)
		{
			size_t pos = 0;
			while (true)
			{
				pos = t1.find(rp[j].first, pos);
				if (pos == string::npos)
					break;
				string tt = t1;
				for (int k = pos; k <= pos + rp[j].first.size() - 1; ++k)
					tt[k] = rp[j].second[k - pos];
				if (tt == t2)
					++ans;
				++pos;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
