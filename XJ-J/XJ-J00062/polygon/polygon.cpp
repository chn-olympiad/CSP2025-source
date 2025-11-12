#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,minn=-1;
int a[1100];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>minn) minn=a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		if(a[i]+a[i+1]+a[i+2]>=minn*2)
		{
			if(a[i+2]>=n)
			{
				cnt++;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}
