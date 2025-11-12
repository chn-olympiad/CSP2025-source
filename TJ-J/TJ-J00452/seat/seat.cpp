#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int main ()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	int q=0,c=0,b[10][10],z=0;
	cin >> n >> m;
	int a[100]={0};
	for (int i=1;i<=n*m;i++)
		cin >> a[i];
	q=a[1];
	sort(a+1,a+(n*m+1),cmp);
	for (int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				z++;
				b[i][j]=a[z];
				if (b[i][j]==q)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				z++;
				b[i][j]=a[z];
				if (b[i][j]==q)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
