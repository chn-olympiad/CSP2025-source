#include<iostream>
using namespace std;
int n,m,c,a[100],x,y,z;
int sum=0,sum1=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]<a[i+1])
		{
			int c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
		if(i>1&&a[i]>a[i-1])
		{
			c=a[i-1];
			a[i-1]=a[i];
			a[i]=c;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			y=i;
		}
	}
	sum+=(y-1)/n+1;
	int z=(y-1)/n+1;
		if(z%2==0)
		{
			sum1+=n-(y%n)+1;
		}
		else
		{
			sum1+=(y-1)%n+1;
		}
	cout<<sum<<" "<<sum1;
	return 0;
}
