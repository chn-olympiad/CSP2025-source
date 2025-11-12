#include <bits/stdc++.h>

using namespace std;

int n,m,a[105],a1[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int aa = a[1];
	sort(a+1,a+n*m+1);
	int j = 1,w = 0;
	for(int i = n*m;i >= 1;i--)
	{
		if(a[i] == aa) w = j;
		a1[j++] = a[i];
	}
	int x=0,y=0;
	y = (w+n-1)/n;
	if(w%n == 0)
	{
		if(y%2==0) x=1;
		else x=n;
	}
	else
	{
		if(y%2==0)
		{
			x=n-w%n+1;
		}
		else x=w%n;
	}
	cout << y << " " << x;
	return 0;
}
