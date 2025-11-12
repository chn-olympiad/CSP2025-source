//康铱宸-SN-J00308-西安滨河学校 
#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int m,n,a[105];//n行m列 
bool cmp(int xxx,int yyy)
{
	return xxx > yyy;
}
int ch(int x,int y)
{
	if (y % 2 == 1)
	{
		return (y-1) * n + x;
	}
	else
	{
		return y * n - (x-1);
	}
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		x = a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	int k;
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i] == x)
		{
			k = i;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			int x = ch(i,j);
			if (x == k)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0; 
}
