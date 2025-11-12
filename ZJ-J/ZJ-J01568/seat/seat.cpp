#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[105], r, ri, rx, ry;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i] == r)
		{
			ri = i;
			break;
		}
	}
	rx = (ri-1)/n + 1;
	ry = (ri-1)%n + 1;
	if (rx%2 == 0)
	{
		ry = n-ry+1;
	}
	cout << rx << " " << ry;
	return 0;
}
