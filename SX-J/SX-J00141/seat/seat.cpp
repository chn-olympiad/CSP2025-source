#include <bits/stdc++.h>
using namespace std;
int a[105],b[105],seat[15][15],c[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int cnt=n*m;
	for(int i = 1;i <= cnt;i++)
	{
		cin >>a[i];
	}
	int ans=a[1];
	sort(a+1,a+cnt+1);
	for(int i = 1;i <=cnt;i++)
	{
		b[i]=a[cnt-(i-1)];
	}
	int sum=1;
	for(int j = 1;j <= m;j++)
	{
		if(j%2==1)
		{
			for(int i = 1;i <= n;i++)
			{
				seat[i][j]=b[sum];
				sum++;
			}
		}
		else
		{
			for(int i = n;i >=1 ;i--)
			{
				seat[i][j]=b[sum];
				sum++;
			}
		}
	}
	for(int i = 1;i <=n;i++)
	{
		for(int j=1;j <=m;j++)
		{
			if(seat[i][j]==ans)
			{
				cout <<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}