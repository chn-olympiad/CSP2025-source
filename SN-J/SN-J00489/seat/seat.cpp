#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[101]={0};
int z;
int c(int x)
{
	if((x+n)/n>n)
	{
		return (x+n)/n-n;
	}
	else
	{
		return (x+n)/n;
	}
}
int r(int x)
{
	if(((x+2)/n)%2==1)
	{
		if(x%n==0)
		{
			return n;
		}
		return x%n;
	}
	else
	{
		if(x%n==0)
		{
			return 1;
		}
		return n+1-x%n;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	z=a[1];
	for(int i=1;i<m*n;i++)
	{
		for(int j=i+1;j<=m*n;j++)
		{
			if(a[j]>a[i])
			{
				int l=a[j];
				a[j]=a[i];
				a[i]=l;
			}
		}
	}
	int b;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==z)
		{
			b=i;
			break;
		}
	}
	cout<<c(b)<<" "<<r(b);
	return 0;
}
