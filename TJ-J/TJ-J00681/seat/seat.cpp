#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int num[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>num[i];
	}
	int ans=num[1];
	for(int i=1;i<=n;i++)
	{
		a[1][i]=num[i];
	}
	for(int j=2;j<=m*n;j++)
	{
		a[j][1]=num[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
