#include<bits/stdc++.h>
using namespace std;
int a[115];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,b[n][m];
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=2;i<=m+1;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			b[i-1][j]=a[j+(2*(i-1))-i/2];
		}
	}
	for(int i=2;i<=m+1;i+=2)
	{
		for(int j=n;j>=1;j--)
		{
			if(i<=m)
			{
				b[i][j]=a[i+j];
			}
		}
	}
	for(int i=2;i<=m+1;i=i+2)
	{
		for(int j=1;j<=n;++j)
		{
			if(b[i-1][j]==x)
			{
				cout<<i-1<<" "<<j<<endl;
				break;
			}
		}
		for(int j=n;j>=1;--j)
		{
			if(b[i][j]==x)
			{
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	return 0;
}