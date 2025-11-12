#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0,l=1;
	for(i=1;i<=m;i++)
	{
		if(l)
		{
			for(j=1;j<=n;j++)
			{
				if(a[++cnt]==f)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
			l=0;
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				if(a[++cnt]==f)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
			l=1;
		}
	}
	return 0;
} 
