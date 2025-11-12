#include <iostream>
#include <string>
using namespace std;
string s[200010][3];
int cur[200010];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		while (cur[i] < s[i][1].size())
		{
			if (s[i][1][cur[i]] == s[i][2][cur[i]]) cur[i]++;
			else break;
		}
		if (cur[i] == s[i][1].size()) cur[i] = 0;
	}
	while (q--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int c = 0;
		while (c < s1.size())
		{
			if (s1[c] == s2[c]) c++;
			else break;
		}
		if (c == s1.size()) c = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int begin = c - cur[i];
			if (begin < 0) continue;
			int end = begin + s[i][1].size() - 1;
			if (end >= s1.size()) continue;
			if (s1.substr(begin, end - begin + 1) == s[i][1])
			{
				string ss = s1.substr(0, begin);
				ss = ss + s[i][2];
				ss = ss + s1.substr(end + 1, s1.size() - end - 1);
				if (ss == s2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
