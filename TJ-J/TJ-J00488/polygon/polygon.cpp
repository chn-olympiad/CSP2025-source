#include<bits/stdc++.h>
using namespace std;
int  n,a[10000005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[2]+a[1])
		{
			cout<<1;
			return 0;
		}
	}
	int sum=0,maxx=-1,cnt=0;
	if(n==4)
	{
		sum+=a[1]+a[2]+a[3];
		maxx=max(a[1],max(a[2],a[3]));
		if(sum>maxx*2)
		{
			cnt++;
		}
		sum=0,maxx=-1;
		sum+=a[1]+a[2]+a[4];
		maxx=max(a[1],max(a[2],a[4]));
		if(sum>maxx*2)
		{
			cnt++;
		}
		sum=0,maxx=-1;
		sum+=a[2]+a[3]+a[4];
		maxx=max(a[2],max(a[3],a[4]));
		if(sum>maxx*2)
		{
			cnt++;
		}
		sum=0,maxx=-1;
		sum+=a[1]+a[4]+a[3];
		maxx=max(a[1],max(a[4],a[3]));
		if(sum>maxx*2)
		{
			cnt++;
		}
		sum=0,maxx=-1;
		sum=a[1]+a[2]+a[3]+a[4];
		maxx=max(max(a[1],a[2]),max(a[3],a[4]));
		cout<<cnt;
		return 0;
	}
	return 0;
}
