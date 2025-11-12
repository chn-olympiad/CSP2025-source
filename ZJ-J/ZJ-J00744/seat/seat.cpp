#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105],b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int s=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][j]=a[++x];
				if(b[i][j]==s)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				b[i][j]=a[++x];
				if(b[i][j]==s)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
}