#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5, M = (1 << 20) + 5;
int n, m, a[N], xsum[N];
vector<int> vec[M];
vector<pair<int, int> > ran;

int main()
{
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		xsum[i] = xsum[i - 1] ^ a[i];
	}
	for (int i = n; i >= 0; -- i)
	{
		vec[xsum[i] ^ m].push_back(i + 1);
	}
	
	ran.reserve(n);
	for (int i = 1; i <= n; ++ i)
	{
		for (; 2 <= vec[xsum[i]].size() && vec[xsum[i]][vec[xsum[i]].size() - 2] <= i; vec[xsum[i]].pop_back());
		if (1 <= vec[xsum[i]].size() && vec[xsum[i]].back() <= i)
		{
			ran.push_back(pair<int, int>(vec[xsum[i]].back(), i));
			vec[xsum[i]].pop_back();
		}
	}
	
	sort(ran.begin(), ran.end(), [](const pair<int, int> &pr1, const pair<int, int> &pr2)
	{
		return pr1.second < pr2.second;
	});
	
	int las = -0x3f3f3f3f, ans = 0;
	for (pair<int, int> i : ran)
	{
		if (las < i.first)
		{
			++ ans;
			las = i.second;
		}
	}
	
	cout << ans << endl;
	return 0;
}
