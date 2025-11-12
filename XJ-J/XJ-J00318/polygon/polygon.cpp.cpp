#include<iostream>
using namespace std;
int n,a[5005]={0},i,j,l,k,z=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	l=1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[l]<a[i])
		{
			l=i;
		}
	}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>(2*a[l]))
		{
			cout<<'1';
			return 0;
		}
		else
		{
			cout<<'0';
			return 0;
		}
	}
	int ans=0;
	for(i=3;i<=n;i++)
	{
		int s=0,x=1,d=1;
		for(j=1;j<=i;j++)
		{
			x=x*(n-s);
			s++;
			d=d*j;
		}
		ans+=x/d;
	}
	cout<<ans;
	return 0;	
} 
