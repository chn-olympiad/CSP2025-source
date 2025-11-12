#include<bits/stdc++.h>
using namespace std;
int n,s=0;
int a[5010],b[5010]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		s=0;
		for(int j=i;j<=n;j++)
		{
			s+=a[j];
		}
		b[i]=s;
	}
	int ret=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		ret=0;
		for(int j=1;j<=i;j++)
		{
			ret+=a[j];
		}
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n+1;k++)
			{
				if(ret+b[j]-b[k]>a[k-1]*2)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans-2;
	return 0;
}
