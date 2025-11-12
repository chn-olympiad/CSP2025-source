#include<iostream>
using namespace std;
int l[5005],a[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		a[i]=i;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int x=i+1;x<=n;x++)
		{
			for(int y=x+1;y<=n;y++)
			{
				if(a[i]>=a[x]&&a[i]>=a[y])
				{
					if(a[x]+a[y]>a[i])
					{
						sum++;
					}
				}
				if(a[x]>=a[i]&&a[x]>=a[y])
				{
					if(a[i]+a[y]>a[x])
					{
						sum++;
					}
				}
				if(a[y]>=a[x]&&a[y]>=a[i])
				{
					if(a[x]+a[i]>a[y])
					{
						sum++;
					}
				}
			}
		}
	}
	cout<<sum%998244353;
	return 0;
 } 
