#include<iostream>
using namespace std;
long long a[15][15];
int b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,d=0,x,y,k;
	cin>>n>>m;
	k=m*n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			b[c]++;
			if(d==0)
			{
				b[c]=1;
				d=c;
			}
			if(c>d)
			{
				b[d]++;
			}
		}
	}
	if(b[d]<n)
	{
		y=n-b[d]+1;
	}
	else
	{
		if(b[d]%n==0)
		{
			y=b[d]/n;
		}
		else
		{
			y=b[d]/n+1;
		}
	}
	if(y%2==0)
	{
		x=4-b[d]/n-1;
	}
	else
	{
		if(b[d]%n==0)
		{
			x=b[d]/n+1;
		}
		else
		{
			x=b[d]/n-1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
