#include<bits/stdc++.h>
using namespace std;
int a[300];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,ai=-1,c,r;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	int t;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m-1;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	for(int i=1;i<=n*m;i++)
	{
		if(a1==a[i])
		{
			ai=i;
		}
	}
	
	if(ai%n==0) c=ai/n;
	else c=ai/n+1;
	if(c%2!=0)
	{
		if(ai%n==0)
		{
			r=n;
		}
		else
		{
			r=ai%n;
		}
	}
	else
	{
		if(ai%n==0)
		{
			r=1;
		}
		else
		{
			r=n-ai%n+1;
		}
	}
	cout<<c<<" "<<r;
	
	return 0;
}
 
