#include <bits/stdc++.h>
using namespace std;
int n,sum,ma,num,a[5005],e;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
				{
					sum+=max(i,max(j,k))-2;
					for(int q=1;q<=max(i,max(j,k));q++)
					{
						num+=a[q];
					}
					for(int t=max(i,max(j,k));t<=n;t++)
					{
						if(a[t]*2<num)
						{
							sum++;
						}
						else
						{
							break;
						}
						if(t==n)
						{
							e++;
						}
					}
				}
			}
		}
	}
	cout<<sum-e;
	return 0;
}
