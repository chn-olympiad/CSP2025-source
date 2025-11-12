#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
string a[N], b[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
		
	while (q--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		
		int ans = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (s1.find(a[i]) == string::npos || s2.find(b[i]) == string::npos)
				continue;
			
			if (s1.find(a[i]) != s2.find(b[i]))
				continue;
				
			int l1 = s1.find(a[i]), l2 = s2.find(b[i]);
			string str1 = s1.substr(0, l1), str2 = s2.substr(0, l2);
			
			if (str1 != str2)
				continue;
				
			int len1 = a[i].size(), len2 = b[i].size(), ln1 = s1.size(), ln2 = s2.size();
			str1 = s1.substr(l1 + len1, ln1 - l1 - len1), str2 = s2.substr(l2 + len2, ln2 - l2 - len2);
			
			if (str1 == str2)
				ans++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}