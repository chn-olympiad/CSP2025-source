#include <bits/stdc++.h>
using namespace std;
int a[11][11],b[105];
bool ans(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n * m;i++)
	{
		cin >> b[i];
	}
	int s = b[0],add1 = 1,x = 1,y = 1;
	sort(b,b + (n * m - 1),ans);
	for(int i = 0;i < n * m;i++)
	{
		a[x][y] = b[i];
		if(b[i] == s)
		{
			cout << y << ' ' << x;
		}
		x += add1;
		if(x == 0 && add1 == -1)
		{
			add1 = 1;
			y++;
			x++;
		}
		if(x == n + 1 && add1 == 1)
		{
			add1 = -1;
			y++;
			x--;
		}
	}
	return 0;
}
