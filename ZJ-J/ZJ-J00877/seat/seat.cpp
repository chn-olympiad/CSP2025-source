#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,m,a[n*m],max=-1,g=1,k[n*m],d,h,z,y,x,b;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	
	}
	z=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int x=0;x<n*m;x++)
		{
			if(a[i]>a[x])
			{
				y=a[i];
				a[i]=a[x];
				a[x]=y;
			}
		}
	}
	for(int x=0;x<m*n;x++)
		{
		if(a[x]==z)
		{
			b=x+1;
		}
		}
	if(b%n==0)
	{
		h=b/n;
		if(h%2==1)
		{
			cout<<h<<" "<<n;
		}
		else
		{
			cout<<h<<" "<<"1";
		}
	}
	else
	{
		h=b/n+1;
		if(h%2==1)
		{
			cout<<h<<" "<<b%n;
		}
		else
		{
			cout<<h<<" "<<n-b%n+1;
		}
	}
	return 0;
}
