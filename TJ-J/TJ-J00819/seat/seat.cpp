#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int g,int h)
{
	return g>h;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				p++;
				if (a[p]==x)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				p++;
				if (a[p]==x)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}
