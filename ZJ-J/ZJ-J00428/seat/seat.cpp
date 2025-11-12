#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i==1)
			x=b[i];
	}
	int t=1;
	sort(b+1,b+n*m+1);
	reverse(b+1,b+n*m+1);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=b[t];
				t++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[j][i]=b[t];
				t++;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
