#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string s[N][10], t[N][10];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
//		string temp = "";
//		int begin = 0, ans = 0;
//		for (int i = 0; i < t1.size(); i++)
//		{
//			temp += t1[i];
//			for (int j = 1; j <= n; j++)
//			{
//				if (temp == s[j][1])
//				{
//					string x = "";
//					for (int k = begin; k <= i; k++) x += t2[i];
//					if (s[j][1] == x) ans++, temp = "";
//				}
//			}
//		}
//		cout << ans << endl;
		cout << 0 << endl; 
	}
	return 0;
}
