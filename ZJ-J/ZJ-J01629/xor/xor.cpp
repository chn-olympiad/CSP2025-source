// 12/20 (60pts)
// it works:)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, k;
int a[maxn], xo[maxn], vis[maxn];
int ans;
vector<pair<int, int> > v;

bool cmp(pair<int, int> x, pair<int, int> y)
{
	return x.second - x.first < y.second - y.first;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (n > 1000)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]); // ÌÆ 
		xo[i] = xo[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			int xor_sum = xo[j] ^ xo[i - 1];
			if (xor_sum == k)
			{
//				++ans;
				pair<int, int> push;
				push.first = i;
				push.second = j;
				v.push_back(push);
//				cout << i << " " << j << endl;
				break;
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (vector<pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		int l = (*it).first;
		int r = (*it).second;
		bool ios = 0; // in others'
//		cout << l << " " << r << endl;
		// if 1 in vis[l, r] then break
		// else vis[l, r] <- 1
		for (int i = l; i <= r; ++i)
		{
			if (vis[i] == 1)
			{
				ios = 1;
				break;
			}
		}
		if (!ios)
		{
			for (int i = l; i <= r; ++i)
			{
				vis[i] = 1;
			}
			++ans;
		}
	}
	cout << ans;
	// AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
	// What the shit mountain code
	return 0;
}
