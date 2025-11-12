#include <bits/stdc++.h>
using namespace std;

long long n, q;
map<string, string> m;
string a, b;

bool fin(string x, string y)
{
	for (int i = 0; i < x.size() - y.size() + 1; i++)
	{
		if (x.substr(i, y.size()) == y) return 1;
	}
	return 0;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	string s = "12345697", ss = "1234";
//	cout << fin(s, ss);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> a >> b;
//		cout << a << b << endl;
		m[a] = b;
	}
	while(q--)
	{
		cin >> a >> b;
		long long ans = 0;
		for (auto x : m)
		{
			if (fin(a, x.first))
			{ 
				string s1 = a.substr(0, a.find(x.first));
				string s2 = a.substr(a.find(x.first) + x.first.size(), a.size() - a.find(x.first) + x.first.size());
				string s3 = b.substr(0, a.find(x.first));
				string s4 = b.substr(a.find(x.first) + x.first.size(), a.size() - a.find(x.first) + x.first.size());
				if (s1 == s3 && s2 == s4 && x.second == b.substr(a.find(x.first), x.first.size())) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
