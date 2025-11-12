#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], p[500005], cnt0, cnt1;
vector<pair<int, int> > w;

inline void solveA()
{
	if (k == 0)
	{
		printf("%d\n", n >> 1);
	}
	else if (k == 1)
	{
		printf("%d\n", n);
	}
	else
	{
		printf("0\n");
	}
	return ;
}

inline void solveB()
{
	int l = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] ^ p[l] == k)
		{
			ans++;
			l = i;
		}
	}
	printf("%d\n", ans);
	return ;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = p[i - 1] ^ a[i];
		cnt0 += a[i] == 0;
		cnt1 += a[i] == 1;
	}
	if (cnt1 == n)
	{
		solveA();
		return 0;
	}
	else if (cnt1 + cnt0 == n)
	{
		solveB();
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[i] ^ p[j] == k)
			{
				w.push_back({i, j});
			}
		}
	}
	sort(w.begin(), w.end());
	int l = 0, ans = 0;
	for (int i = 1; i <= w.size(); i++)
	{
		if (w[i].second > l)
		{
			ans++;
			l = w[i].first;
		}
	}
	printf("%d\n", ans);
	return 0;
}
