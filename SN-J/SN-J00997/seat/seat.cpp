#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],b[1001][1001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	int g=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[g];
				g--;
				if(b[i][j]==s)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[g];
				g--;
				if(b[i][j]==s)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
