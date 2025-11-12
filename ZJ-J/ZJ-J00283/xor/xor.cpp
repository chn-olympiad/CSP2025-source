#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct node
{
	int be, en;
};
bool cmp(node a, node b)
{
	return a.en < b.en;
}
void solve(int n, int k)
{
	int lst = 1;
	vector<node> v;
	for (int i = 1; i <= n; i++)
		for (int j = i; j >= lst; j--)
			if ((a[i] ^ a[j - 1]) == k)
			{
				v.push_back({j, i}), lst = j;
				break;
			}
	sort(v.begin(), v.end(), cmp);
	int tmp = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++)
		if (tmp < v[i].be)
			tmp = v[i].en, cnt++;
	cout << cnt;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, cnt = 0, lst = 0, maxi = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxi = max(maxi, a[i]);
		a[i] ^= a[i - 1];
		if ((a[i] ^ a[lst]) == k)
			cnt++, lst = i;
	}
	if (maxi == 1 || maxi == 0)
		cout << cnt;
	else
		solve(n, k);
	return 0;
}
