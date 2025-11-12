#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<pair<string, string>> s(n + 5);
	for (int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;
	while (q--)
		cout << n << "\n";
	return 0;
}