#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],h,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int a1 = a[1],d;
	sort(a+1,a+n*m+1);
	for (int i = n*m;i >= 1;i--)
	{
		h++;
		if (a[i] == a1)
		{
			d = h;
			break;
		}
	}
	int c = 0;
	if (d % m == 0)
	{
		c = d/m;
	}
	else
	{
		c = d/m+1;
	}
	for (int i = 1;i <= n*m;i++)
	{
		if (i == d)
			break;
		if (r == n)
			i++;
		if (i % n == 0 && (i / n) % 2 == 0)
		{
			r--;
		} 
		if (i % n == 0 && (i/n)% 2 != 0)
		{
			r++;
		}
		if (i%n!=0 && (i/n+1)% 2 == 0)
		{
			r--;
		}
		if (i%n!=0 && (i/n+1)% 2 != 0)
		{
			r++;
		}
	} 
	cout << c << ' ' << r;
	return 0;
} 
