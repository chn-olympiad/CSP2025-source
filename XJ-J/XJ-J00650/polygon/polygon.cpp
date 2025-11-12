#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	long long ans=0,ns=0,sum=0;
	int i,j,a[5005],n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	for(i=1;i<=n;i++)
	{
		int s=0;
		for(j=i;j<=n;j++)
		{
			ns++;
			sum+=a[j];
			if(sum<=a[j]*2&&j!=i&&ns>=3)
			{
				sum-=a[j];
				ns--;
			}
			else if(ns>=3&&j!=i)
			{
				ans++;
				if(ans>=998244353)
				{
					ans=ans%998244353;
				}
			}
		}
	}
	cout<<ans--;
	return 0;
}
