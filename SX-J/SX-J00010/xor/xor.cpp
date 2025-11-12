#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 10;
int a[MAXN], s[MAXN];
int n, k;
bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i-1] ^ a[i];
	vector<pair<int,int> > ans;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
			if ((s[j] ^ s[i-1]) == k)
				ans.push_back(make_pair(i, j));
		if (a[i] == k)
			ans.push_back(make_pair(i, i));
	}

	sort(ans.begin(), ans.end(), cmp);
	ll res = 0;
	int lst = -1;
	for (int i = 0; i < ans.size(); i++)
	{
		if (lst < ans[i].first)
			res++, lst = ans[i].second;
	}
	cout << res << endl;
	return 0;
}