#include<bits/stdc++.h>
using namespace std;
int n,a[110],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3) cout<<0;return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int z=j;z<=n;z++)
			{
				if(i!=j&&j!=z&&i!=z)
				{
					if(a[i]+a[j]+a[z]>2*(max(a[i],max(a[j],a[z]))))
					{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
