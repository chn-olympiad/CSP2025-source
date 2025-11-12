#include <iostream>
#include <cstdio>
using namespace std;
string rep[200005][2];
int l[200005];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string tmp;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> rep[i][1] >> rep[i][2];
		l[i] = rep[i][1].length();
	}
	while (q--)
	{
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j + l[i] - 1 < t1.length(); j++)
			{
				if (t1.substr(j, l[i]) == rep[i][1])
				{
					tmp = t1.substr(0, j) + rep[i][2] + t1.substr(j + l[i], t1.length() - j - l[i] + 1);
//					cout << tmp << " " << t1 << "\n";
					if (tmp == t2)
					{
						ans++;
					}
				}
			}
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

