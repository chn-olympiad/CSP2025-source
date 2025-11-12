//SN-J00740 王宇泽 西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		
	}
	int b = a[1];
	int pai;
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i] > a[i-1])
		{
			int s=a[i];
			a[i]=a[i-1];
			a[i-1]=s;
		}
	}
	
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i]==b)
			{
				pai=i;
			}
	}
	int x=1,y=1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (i % 2 ==1)
			{
				y--;
				if (y !=m)
				{
					x++;
				}
			}
			if (i % 2 == 0)
			{
				y++;
			}
		}
	}
	cout << x << " " << y;
}









