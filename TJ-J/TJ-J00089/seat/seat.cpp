#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[200];
int b[20][20];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x = n*m;
	for (int i = 1; i <= x; i++)
	{
		cin >> a[i];
	}
	int t = a[1];
	sort(a+1,a+n+1,cmp);
	int cur = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cur++;
			if (j % 2 == 1)
			{
				//b[i][j] = a[cur];
				if (a[cur] == t)
				{
					cout << j << " " << i;
					return 0;
				}
			}
			else
			{
				//b[n-i+1][j] = a[cur];
				if (a[cur] == t)
				{
					cout << j << " " << n-i+1;
					return 0;
				}
			}
		}
	}
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		if (b[i][j] == t)
	//		{
	//			cout << j << " " << i;
	//			return 0;
	//		}
	//	}
	//}
	return 0;
}
