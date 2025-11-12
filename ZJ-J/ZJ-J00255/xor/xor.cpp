#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long n,k,a[1000005],vis[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int MAX=0;
	for(int o=1;o<=n;o++)
	{
		int ans=0;
		for(int i=1;i<o;i++)
		{
			int sum=0;
			for(int j=i;j<o;j++)
			{
				sum^=a[j];
				if(sum==k)
				{
					i=i+j-1;
					ans++;
					break;
				}
			}
		}
		for(int i=o;i<=n;i++)
		{
			int sum=0;
			for(int j=i;j<=n;j++)
			{
				sum^=a[j];
				if(sum==k)
				{
					i=i+j-1;
					ans++;
					break;
				}
			}
		}
		MAX=max(MAX,ans);
	}
	cout<<MAX;
	return 0;
}