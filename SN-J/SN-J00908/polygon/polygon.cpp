#include <bits/stdc++.h>
using namespace std;
const int MAXN=5001;
int n,a[MAXN],ans,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=-0x3f;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
		sum+=a[i];
	}
	if(sum>2*maxx)
	{
		ans++;
	}
	for(int i=1;i<=n;i++)
	{
		int bj=a[i];
		a[i]=0;
		sum-=bj;
		maxx=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>maxx)
			{
				maxx=a[j];
			}
		}
		if(sum>2*maxx)
		{
			ans++;
		}
		for(int j=1;j<=n;j++)
		{
			int cj=a[j];
			a[j]=0;
			sum-=cj;
			maxx=0;
			for(int k=1;k<=n;k++)
			{
				if(a[k]>maxx)
				{
					maxx=a[k];
				}
			}
			if(sum>2*maxx)
			{
				ans++;
			}
			a[j]=cj;
		}
		a[i]=bj;
	}
	cout<<ans;
	return 0;
}
