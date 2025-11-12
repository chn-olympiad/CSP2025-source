#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	if (x > y)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[1005];
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int t = a[1], p;
	sort (a + 1, a + n*m + 1, cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (t == a[i])
		{
			p = i;
		break;
		}
	}
	int c = (p - 1) / n + 1;
	cout << c << " " << (p - 1) % c + 1;
	return 0;
}
