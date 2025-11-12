#include<bits/stdc++.h>
using namespace std;
long long m=998244353;
long long n,a[10000],ans,c[10000],b[10000][10],dp[10000],t,tt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=max(a[i],t);
	}
	sort(a+1,a+n+1);
	tt=a[1]+a[2];
	for(int i=1;i<=n;i++)
	{
	//	cout<<i<<"\n";
		c[i]=c[i-1]+a[i];
		for(int j=c[i]-a[i];j>=a[i]+1;j--)
		{
			dp[i]+=b[j][3]+b[j][2]+b[j][0];
	//		cout<<j<<" "<<dp[i]<<" "<<b[j][3]<<' '<<b[j][2]<<' '<<b[j][0]<<"\n";
		}
	//		cout<<"\n";
		for(int j=c[i]-a[i];j>=a[i]+1;j--)
			b[j+a[i]][3]=b[j][3]+b[j][2]+b[j][0];
		for(int j=a[i];j>=tt;j--)
			b[j+a[i]][0]=b[j][3]+b[j][2]+b[j][0];
		for(int j=1;j<=t*2;j++)
			b[j+a[i]][2]=b[j+a[i]][2]+b[j][1];
		b[a[i]][1]++;
		ans=ans+dp[i];
	}
	cout<<ans;
	return 0;
}
