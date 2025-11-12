#include<bits/stdc++.h>>
using namespace std;

const int MAXN = 2e5+7;
int n, q;
string ss[MAXN][4];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >>ss[i][1] >>ss[i][2];
	}
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < ss[i][1].length(); j++)
//		{
//			cout << ss[i][1][j] << ' ';
//		}
//		cout << endl;
//		for (int j = 0; j < ss[i][2].length(); j++)
//		{
//			cout << ss[i][2][j] << ' ';
//		}
//	}
	while (q--)
	{
		bool flag;
		long long ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		
		if (t1.length() != t2.length())
		{
			cout << 0 << endl;
			continue;
		}
		
		for (int i = 1; i <= n; i++)
		{
			string s1 = ss[i][1];
			string s2 = ss[i][2];
			if (t1.find(s1) == -1 || t2.find(s2) == -1)
			{
				continue;
			}
			int s1i = s1.find('b');
			int s2i = s2.find('b');
			int t1i = t1.find('b');
			int t2i = t2.find('b');
			if (s2i - s1i != t2i - t1i)
			{
				continue;
			}
			ans++;
		}
		cout << ans << endl;
	}
	
	
	
	return 0;
} 

/*
5 2
aaaba abaaa
aaaaabaa aaabaaaa
aaab baaa
aaaaaaaaabaa aaaaabaaaaaa
aaaabaa aaaaaba
aaaaaabaaaaaaaa aaabaaaaaaaaaaa
aaabaaaaaa aaaaabaaaa
*/
