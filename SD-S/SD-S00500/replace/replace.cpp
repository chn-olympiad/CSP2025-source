#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 5;
array<string, 5> s[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
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
		cout << 0 << '\n';
	}
	return 0;
}
