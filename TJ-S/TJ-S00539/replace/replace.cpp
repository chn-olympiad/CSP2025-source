#include <bits/stdc++.h>
using namespace std;

string s[200005][2];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	while (q--)
	{
		long long cnt = 0;
		string s1, s2, x = "";
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++)
		{
			x += s1[i];
			string y = "";
			for (int j = i; j >= 0; j--)
			{
				y = x[j] + y;
				for (int k = 1; k <= n; k++)
				{
					if (y == s[k][0])
					{
						string x2 = "", z = "", ans;
						for (int ii = 0; ii < j; ii++) x2 += s1[ii];
						for (int ii = i + 1; ii < s1.length(); ii++) z += s1[ii];
						ans = x2 + s[k][1] + z;
						if (ans == s2) cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
