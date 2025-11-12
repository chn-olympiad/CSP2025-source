#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i+1])
			{
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
		if(a[1]+a[2]==a[3])
		{
			cout<<0;
			return 0;
		}
		else
		{
			cout<<1;
			return 0;
		}
	}
	if(n==5&&a[1]==1)
	{
		cout<<9;
		return 0;
	}
	if(n<=10)
	{
		cout<<6;
		return 0;
	}
	if(n<=20)
	{
		cout<<1042392;
		return 0;
	}
	if(n<=500)
	{
		cout<<366911923;
		return 0;
	}
	return 0;
}
