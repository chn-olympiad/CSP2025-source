#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x = 0, y = 0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		if (a[i] >= a[1]) cnt++;
	}
	while (cnt >= 2*n)
	{
		y += 2;
		cnt -= 2*n;
	}
	if (cnt > n)
	{
		y += 2;
		cnt -= n;
		x = n-cnt+1;
	}
	else
	{
		y++;
		x = cnt;
	}
	cout << y << " " << x;
	return 0;
}
