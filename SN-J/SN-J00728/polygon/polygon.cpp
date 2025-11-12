#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,sum,ans;
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
			sum=0;
			maxn=0;
			cout<<i<<" "<<j<<endl;
			for(int k=i;k<=j;k++)
			{
				sum+=a[k];
				if(a[k]>maxn)
				{
					maxn=a[k];
				}
			}
			if((2*maxn)<sum)
			{
				ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
