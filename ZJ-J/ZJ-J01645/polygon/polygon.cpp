#include<bits/stdc++.h>
using namespace std;
int a[5005];
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
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				int mx;
				mx=max(a[i],a[j]);
				mx=max(a[k],mx);
				if((a[i]+a[j]+a[k])>2*mx)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
}
