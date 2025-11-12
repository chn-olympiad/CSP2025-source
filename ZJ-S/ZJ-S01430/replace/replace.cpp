#include <bits/stdc++.h>
using namespace std;

int n, q;
string s1[20003], s2[20003];
int l1[200003];

string sub(string x, int st, int l)
{
	string ans = "";
	for(int i = st; i < st + l; i++)
	{
		ans = ans + x[i];
	}
	return ans;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
		l1[i] = s1[i].length();
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		int l = t1.length();
		if (l != t2.length())
		{
			cout << "0\n";
			continue;
		}
		int cnt = 0;
		for(int i = 0; i < l; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if (i + l1[j] <= l)
				{
					if (sub(t1, i, l1[j]) == s1[j])
					{
						if (sub(t1, 0, i) + s2[j] + sub(t1, i + l1[j], l - i - l1[j]) == t2)
						{
							cnt++;
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
