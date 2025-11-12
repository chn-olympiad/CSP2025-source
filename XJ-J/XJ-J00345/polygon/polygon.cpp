#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[1000000000];
	int cnt=0,c,b;
	cin>>n;
	for(int d=1;d<=n;d++)
	{
		cin>>a[d];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int t=j+1;t<=n;t++)
			{
				c=a[i]+a[j]+a[t];
				if(a[i]>=a[j])
				{
					b=a[i];
				}
				else
				{
					b=a[j];
				}
				if(b<a[t])
				{
					b=a[t];
				}
				if(c>b)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
}
