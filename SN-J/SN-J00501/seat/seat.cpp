#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[15][15];
int seat[15][15];
int a[105];
int R;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i == 1) R = a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt = 0;
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			p[i][j] = a[++cnt];
		}
	}
	for(int i = 1;i<=m;i++)
	{
		if(i % 2 != 0) 
		{
			for(int j = 1;j<=n;j++)		
				seat[i][j] = p[i][j]; 
		}	
		else
		{
			for(int j = n;j>=1;j--)
			{
				seat[i][j] = p[i][n-j+1];
			}
		}
	}
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(seat[i][j] == R) cout<<i<<" "<<j;
			}
		}
		return 0;
}
