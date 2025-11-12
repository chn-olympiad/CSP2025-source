#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
ll n, q;
pair<string, string> s[maxn];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++)
	{
		cin >> s[i].first >> s[i].second;
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << "0\n";
			continue;
		}
		ll cnt = 0;
		for (ll i = 1; i <= n; i++)
		{
			ll at = t1.find(s[i].first);
			if (at == string::npos)
			{
				continue;
			}
			if (t1.substr(0, at) + s[i].second + t1.substr(at + s[i].second.size()) == t2)
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}