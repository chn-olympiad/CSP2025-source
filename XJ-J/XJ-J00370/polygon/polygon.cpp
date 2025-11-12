#include<iostream>
using namespace std;
int n,a[5005]={0};
long long s;
int f(int x,int sum,int maxi,int start)
{
	if(x==0)
	{
		if(sum>maxi*2)
		{
			s++;
			s=s%998244353;
		}
	}
	for(int i=start;i<=n;i++)
	{
		sum+=a[i];
		if(a[i]>maxi)
		{
			f(x-1,sum,a[i],i+1);
		}
		else
		{
			f(x-1,sum,maxi,i+1);
		}
		sum-=a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,maxs=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxs<a[i])
		{
			maxs=a[i];
		}
	}
	if(maxs==1)
	{
		cout<<n-2;
		return 0;
	}
	for(i=3;i<=n;i++)
	{
		f(i,0,0,1);
	}
	cout<<s;
	return 0;
}
