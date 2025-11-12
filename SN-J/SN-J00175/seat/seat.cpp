#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,R,p;
	cin>>m>>n;
	int a[m*n];
	int c[m*n];
	for(int i=0;i<m*n;i++) cin>>a[i];
	R=a[1];
	for(int i=0;i<m*n;i++)
	{
		int max=a[i];
		for(int j=0;j<m*n;j++)
		{
			if(a[j]>max) max=a[j];
		}
		c[i]=max;
		for(int k=0;k<m*n;k++)
		{
			if(a[k]==max) a[k]-=a[k];
		}
	}
	for(int i=0;i<m*n;i++)
	{
		if(c[i]==R) p=i;
	}
	if(p==1) 
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(p%2==1) 
	{
		if(p%n==0) 
		{
			cout<<p/n<<" "<<n;
			return 0;
		}
		else 
		{
			cout<<p/n+1<<" "<<p%n;
			return 0;
		}
	}
	if(p%2==0)
	{
		if(p%n==0) 
		{
			cout<<p/n<<" "<<1;
			return 0;
		}
		else 
		{
			cout<<p/n+1<<" "<<n-p%n+1;
			return 0;
		}
	}
	return 0;
}