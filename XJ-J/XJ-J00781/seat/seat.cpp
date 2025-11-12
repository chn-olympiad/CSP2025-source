#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,a[15][15],b,d[105],j,i,z;
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>d[i];
	}
	b=d[1];
	sort(d+1,d+c+1);
	for(z=1;z<=m/2;z+=2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][z]=d[c-j+1];
			}	
		}
		if(m%2!=0&&z==m/2)
		{
			continue;
		}
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=n;j++)
			{
				a[i][z+1]=d[c-j+1];
			}
		}
	}
	a[1][1]=d[c];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==b)
			{
				cout<<i<<' '<<j;
				break;
			}
		}
		if(a[i][j]==b)
		{
			break;
		}
	}
	return 0;
}
