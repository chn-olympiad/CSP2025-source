#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int maxn,sum;
int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				maxn=max(maxn,a[k]);
				sum+=a[k];
			}
			if(maxn*2<sum)
			{
				ans++;
			}
			maxn=0;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}
