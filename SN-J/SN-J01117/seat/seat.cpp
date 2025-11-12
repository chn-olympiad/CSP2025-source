#include<bits/stdc++.h>
using namespace std;
long long a[105ll],b[105ll],n,h,m,cj,zw[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
	sort(a,a+m*n+1);
	int j=1;
	for(int i=m*n;i>=1;i--)
	{
		b[i]=a[j];
		j++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2==1)
				zw[j][i]=b[(i-1)*n+j];
			else
				zw[j][i]=b[(i-1)*n+(n-j+1)];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(zw[i][j]==cj)
			{
				cout<<j<<" "<<i;
				return 0;
			}	
		}
	}
}

