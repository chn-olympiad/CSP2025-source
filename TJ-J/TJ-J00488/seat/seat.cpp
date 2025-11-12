#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			x=i;
		}
	}
	int p=1;
	int mp[n][m];
	for(int k=1;k<=m;k++)
	{
		if(k%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				mp[i][k]=p;
				p++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				mp[i][k]=p;
				p++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==x)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
