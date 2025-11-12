#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q;
string s1[N], s2[N];
void solve()
{
	string t1, t2;
	cin >> t1 >> t2;
	if (t1.size() != t2.size())
	{
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s1[i].size() > t1.size()) continue;
		if (t1.find(s1[i]) == -1) continue;
		int l = t1.find(s1[i]);
		int len = s1[i].size();
		string t = t1.substr(0, l) + s2[i] + t1.substr(l + len);
		if (t == t2) ans++;
	}
	cout << ans << endl;
	return;
}

const int L = 1e7 + 10;
int cnt[L];
struct Node
{
	int l, r;
};
vector <Node> g[L];
void solve2()
{
	string t1, t2;
	cin >> t1 >> t2;
	if (t1.size() != t2.size())
	{
		cout << 0 << endl;
		return;
	}
	int x = t1.find("b"), y = t2.find("b");
	int len = y - x;
	len += 5000000;
	if (cnt[len] == 0)
	{
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	int l = x, r = t1.size() - x - 1;
	for (int i = 0; i < g[len].size(); i++)
	{
		int l2 = g[len][i].l, r2 = g[len][i].r;
		if (l2 <= l && r2 <= r) ans++;
	}
	cout << ans << endl;
	return;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	if (q == 1 || n <= 1000)
	{
		while(q--)
			solve();
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = s1[i].find("b"), y = s2[i].find("b");
		int len = y - x;
		len += 5000000;
		cnt[len]++;
		g[len].push_back({x, s1[i].size() - x - 1});
	}
	while(q--)
		solve2();
	return 0;
}
