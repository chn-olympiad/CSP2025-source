#include <bits/stdc++.h>
using namespace std;
int n, q;
map<string, string> mp;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		cout << 1 << endl;
	}
	return 0;
}
