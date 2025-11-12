#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,a[5005],s[25000005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	m=a[1];s[a[1]]=1;
	for(int i=2,sum;i<=n;i++)
	{
		sum=0;
		for(int i=a[i]+1;i<=m;i++)
			sum+=s[i],sum%=mod;
		i>2?ans+=sum,ans%=mod:0;
		for(int j=m;j;j--)
			s[j+a[i]]+=s[j];
		m+=a[i];
	}
	printf("%d",ans);
	return 0;
}
