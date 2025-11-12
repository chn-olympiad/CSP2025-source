#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long n,a[5005],ans,mod=998244353;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-2;i++)
	{
		for(int k=i+1;k<n;k++)
		{
			long long sum=a[k];
			for(int o=n;o>k;o--)
			{
				for(int j=o;j>k;j--)
				{
					sum+=a[j];
					if(i==2) cout<<sum;
					if(sum>a[i])
					{
						ans+=(j-k);
						ans%=mod;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}