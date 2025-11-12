#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],a1;
	cin>>n>>m;
	int seat[m+10][n+10];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	int x=0,y=1,z=2;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;i<=n;j++)
		{
			if(i%2!=0)
			{
				for(int k=x*n+1;k<=y*n;k++)
			    	seat[i][j]=a[k];
			}
			else
			{
				for(int l=z*n;l>=y*n+1;l--)
				    seat[i][j]=a[l];
			}
		}
		x+=2;y+=2;z+=2;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(seat[i][j]==a1)
			    cout<<i<<' '<<j;
    	}
    }
	return 0;
}
