#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],now,ans,f[1000001],last,sum[1000001];
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		now=sum[i];
		if((f[now^k]!=0||now==k)&&last<=f[now^k])ans++,last=i;
		f[now]=i;
	}
	cout<<ans;
	return 0;
}

