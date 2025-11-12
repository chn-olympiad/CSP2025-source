//SN-J00015 QIAOYUXIAO
#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110][110],c[110];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		c[i]=a[n*m-i+1];
	}
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][j]=c[(j-1)*m+i];
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				b[i][j]=c[(j-1)*m+n-i+1];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==x)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

