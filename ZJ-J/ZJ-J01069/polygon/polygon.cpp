#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long ff(int x)
{
	if(x%6==0)
		sum=x/6%998244353*(x-1)%998244353*(x-2)%998244353;
	else if((x-1)%6==0)
		sum=x%998244353*((x-1)/6)%998244353*(x-2)%998244353;
	else if((x-2)%6==0)
		sum=x%998244353*((x-2)/6)%998244353*(x-1)%998244353;
	else if(x%2==0&&(x-1)%3==0)
		sum=(x/2)%998244353*((x-1)/3)%998244353*(x-2)%998244353;
	else if(x%2==0&&(x-2)%3==0)
		sum=(x/2)%998244353*((x-2)/3)%998244353*(x-1)%998244353;
	else if(x%3==0&&(x-1)%2==0)
		sum=(x/3)%998244353*((x-1)/2)%998244353*(x-2)%998244353;
	else if(x%3==0&&(x-2)%2==0)
		sum=(x/3)%998244353*((x-2)/2)%998244353*(x-1)%998244353;
	else if((x-1)%3==0&&(x-2)%2==0)
		sum=((x-1)/3)%998244353*((x-2)/2)%998244353*x%998244353;
	else
		sum=((x-2)/3)%998244353*((x-1)/2)%998244353*x%998244353;
	for(int i=1;i<=x-3;i++)
	{
		sum=sum*2%998244353;
	}
	return sum;
}
void f(int x,int y[],int z[],int xx)
{
	if(xx==x+1)
	{
		long long sum1=0;
		int maxx=0,k=0;
		for(int i=1;i<=x;i++)
		{
			if(z[i]==1)
			{
				maxx=max(maxx,y[i]);
				sum1=sum1+y[i];
				k++;
			}
		}
		if(k>=3&&sum1>maxx*2)
		{
			sum++;
		}
		if(sum>998244353)
			sum=sum%998244353;
	}
	else
	{
		z[xx]=1;
		f(x,y,z,xx+1);
		z[xx]=0;
		f(x,y,z,xx+1);
	}
}
int a[10000],b[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
			flag=1;
	}
	if(flag==0)
	{
		cout<<ff(n);
		return 0;
	}
	f(n,a,b,1);
	cout<<sum;
	return 0;
}
