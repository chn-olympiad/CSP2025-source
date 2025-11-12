#include<bits/stdc++.h>
using namespace std;
int x,y,a[105],n,m,w[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			w[i][j]=a[n*m-(i-1)*n-j+1];
		}
		for(int j=n;j>=1;j--)
		{
			w[i+1][j]=a[n*m-i*n-n+j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(w[i][j]==x)
			{
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
} 
