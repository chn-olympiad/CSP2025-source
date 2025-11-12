#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
int n, q, ans;
string s[N][2], t1, t2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			string tmp = t1;
			bool f = 1;
			for (int i = 0; i < t1.length() - s[j][0].length(); i++)
			{
				for (int k = 0; k < s[j][0].length(); k++)
				{
					if (s[j][0][k] != t1[i + k])
					{
						f = 0;
						break;
					}
				}
				if (!f)
				{
					continue;
				}
				for (int k = 0; k < s[j][1].length(); k++)
				{
					t1[i + k] = s[j][1][k];
				}
				ans += (t1 == t2);
				for (int k = 0; k < s[j][0].length(); k++)
				{
					t1[i + k] = s[j][0][k];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
