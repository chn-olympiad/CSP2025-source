#include<bits/stdc++.h>
using namespace std;
int n,a[9999],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int maxx=max(a[i],max(a[i+1],a[i+2])),sum1=a[i]+a[i+1]+a[i+2];
		if(maxx*2>sum1) sum++;
		for(int j=i+3;j<=n;j++)
		{
			int sum2=sum1;
			for(int k=j+i;k<=n;k++)
			{
				sum2+=a[i];
				maxx=max(a[i],maxx);
				if(maxx*2>sum1)
				{
					sum++;
				}
			}

		}
	}
	cout<<sum*2;
	return 0;
}