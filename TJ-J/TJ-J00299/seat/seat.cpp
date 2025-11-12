#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int zwb[102][102];
	cin>>n>>m;
	int xm;
	int a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xm = a[1];
	sort(a+1,a+m*n+1);
	int jsq = 1; 
	for(int i=m;i>0;i--)
	{
		if(m%2==1)
		{
			if(i%2==m%2)
			{
				for(int j=n;j>0;j--)
				{
					zwb[j][i]=a[jsq];
					jsq++;
				}
			}
			if(i%2!=m%2)
			{
				for(int j=1;j<=n;j++)
				{
					zwb[j][i]=a[jsq];
					jsq++;
				}
			}
		}
		if(m%2==0)
		{
			if(i%2==m%2)
			{
				for(int j=1;j<=n;j++)
				{
					zwb[j][i]=a[jsq];
					jsq++;
				}
			}
			if(i%2!=m%2)
			{
				for(int j=n;j>0;j--)
				{
					zwb[j][i]=a[jsq];
					jsq++;
				}
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(zwb[i][j]==xm)
			{
			cout<<j<<" "<<i;
			}	
		}
	}

	
	
	return 0;
} 
