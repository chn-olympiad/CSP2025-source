#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int maxa=0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(a[i][j]>maxa)
			{
				maxa=a[i][j];
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			maxa=a[1][1];
		}
	}
	cout<<a[n][m];
	return 0;
}
