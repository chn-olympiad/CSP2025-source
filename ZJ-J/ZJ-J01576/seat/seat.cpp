#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; i++)
	{
		int x;
		scanf("%d", &x);
		v.push_back(x);
		if (i == 0) a1 = x;
	}
	sort(v.begin(), v.end());
	int l = 1, h = 1;
	for (int i = n * m - 1; i >= 0; i--)
	{
		if (v[i] == a1) break;
		if (l & 1)
		{
			h++;
			if (h > n)
			{
				h = n;
				l++;
			}
		}
		else
		{
			h--;
			if (h < 1)
			{
				h = 1;
				l++;
			}
		}
	}
	printf("%d %d\n", l, h);
	return 0;
}
