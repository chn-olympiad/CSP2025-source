#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
int a[10000][10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> x >> y >> z;
		int t = max(x,y);
		x = min(x,y);
		y = t;
		a[x][y] = z;
		//cout << x << ' ' << y << endl;
	}
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for (int i = 1;i <= k;i++)
	{
		int actz = 0,csc[100000];
		cin >> actz;
		for (int j = 1;j <= n;j++)
		{
			cin >> csc[j];
		}
		for (int j = 1;j <= n;j++)
		{
			for (int k = j + 1;k <= n;k++)
			{
				if (a[j][k] == 0) a[j][k] = csc[j] + csc[k];
				else a[j][k] = min(a[j][k],(csc[j] + csc[k]));
			} 
		}
	}
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
	int sum = 0;
	for (int i = n;i >= 2;i--)
	{
		int minn = 1e9;
		for (int j = i - 1;j >= 1;j--)
		{
			minn = min(minn,a[j][i]);
			//cout << j << ' ' << i << endl;
		}
		sum += minn;
	}
	cout << sum;
	return 0;
}
