#include<iostream>
#include<algorithm>
using namespace std;
int a[10005],seat[105][105];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,i,j,x=1;
	cin>>n>>m; 
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
    int R=a[1];
	sort(a+1,a+n*m,cmp);
	for(j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(i=1;i<=n;i++,x++)
			{
				seat[i][j]=a[x];
			}
		}
		else
		{
			for(i=n;i>=1;i--,x++)
			{
				seat[i][j]=a[x];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(seat[i][j]==R) cout<<j<<" "<<i;
			break; 
		}
	}
	return 0;
}
