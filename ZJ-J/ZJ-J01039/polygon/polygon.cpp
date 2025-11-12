#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], ans = 0;
bool vis[5005];
void dfs(int m, vector<int> v)
{
	if (v.size() >= 3)
	{
		for (int i = 0;i < v.size();i++)
		{
			cout << v[i] << ' ';
		}
		cout << "\n";
	}
	if (m == n)
	{
		return ;
	}
	
	for (int i = m;i <= n;i++)
	{
		if (!vis[i])
		{
			v.push_back(i);
			vis[i] = true;
			dfs(m + 1, v);
			v.pop_back();
			vis[i] = false;
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	vector<int> v;
	dfs(1, v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
