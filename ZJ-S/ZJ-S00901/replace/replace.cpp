#include<bits/stdc++.h>
using namespace std;

int n, q, ans;
string s[200005], t[200005], x, y;

int solve()
{
	if (x.size() != y.size()) return 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 0;
		while (1)
		{
			if (x.find(s[i], l) == string::npos) break;
			string z = x;
			int num = x.find(s[i], l);
			for (int j = num; j <= num + s[i].size() - 1; j++) z[j] = t[i][j - num];
			l = num + 1;
			if (z == y) ans++;
			//cout << i << " " << l << " " << x << " " << y << " " << z << " " << ans << endl;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i] >> t[i];
	while (q--)
	{
		ans = 0;
		cin >> x >> y;
		cout << solve() << endl;
	}
}