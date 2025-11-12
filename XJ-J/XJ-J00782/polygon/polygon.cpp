#include<iostream>
using namespace std;
int a[5000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int z=j+1;z<=n;z++)
			{
				int maxx=max(a[i],a[j]);
				maxx=max(maxx,a[z]);
				if(a[i]+a[j]+a[z]>2*maxx)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans; 
	return 0;
}
