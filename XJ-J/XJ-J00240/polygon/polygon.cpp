#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010],ans=0,maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	for(long long i=2;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(long long l=0;l<=n-2;l++)
	{
		for(long long r=l+2;r<=n;r++)
		{
			maxx=-1;
			for(long long i=l;i<=r;i++)
			{
				maxx=max(maxx,a[i]);
			}
			maxx*=2;
			if(b[r]-b[l]>maxx)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
