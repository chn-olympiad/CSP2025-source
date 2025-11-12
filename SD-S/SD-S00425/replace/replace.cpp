#include <bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
//#define int long long
int n, Q;
string s1[200005], s2[200005];
signed main()
{
    file("replace");
    cin >> n >> Q;
    for (int i = 1; i <= n; ++i)
    {
    	cin >> s1[i] >> s2[i];
	}
	string t, q;
	while (Q--)
	{
		cin >> t >> q;
		int ans = 0;
		string tmp = "";
		for (int i = 0; i < t.size(); ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (t[i] != s1[j][0] or t.size() < s1[j].size())
				{
					continue;
				}
				bool flag = 0;
				for (int k = 0; k < s1[j].size(); ++k)
				{
//						if (i == 0 and j == 1)
//						{
////							cout << "+";
//							cout << s1[j][k] << ' ' << t[i + k] << '\n';
//						}
					if (s1[j][k] != t[i + k] or i + k >= t.size())
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
//					cout << j << ' ';
					string x = tmp;
					x += s2[j];
//					cout << j << ' ' << x << ' ' << i << '\n';
					for (int k = i + s1[j].size(); k < t.size(); ++k)
					{
						x += t[k];
					}
					if (x == q)
					{
						ans++;
					}
				}
			}
			tmp += t[i];
		}
		cout << ans << '\n';
	}
    return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
