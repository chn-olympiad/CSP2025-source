#include<bits/stdc++.h>
using namespace std;
int mp[20][20];
int a[500];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+1+n*m);
	int now=n*m;
	for(int j=1; j<=n; j++)
	{
		if(j%2)
		{
			for(int i=1; i<=n; i++)
			{
				mp[i][j]=a[now];
				now--;
			}
		}
		else
		{
			for(int i=n; i>=1; i--)
			{
				mp[i][j]=a[now];
				now--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==p)
			{
				cout<<j<<" "<<i<<"\n";
			}
		}
	}
	return 0;
}
