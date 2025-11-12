#include<bits/stdc++.h>
using namespace std;
int a[5001],n,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[n];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int r=j+1;r<=n;r++)
			{
				if(a[i]+a[j]+a[r]>max(a[i],max(a[j],a[r])))
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
