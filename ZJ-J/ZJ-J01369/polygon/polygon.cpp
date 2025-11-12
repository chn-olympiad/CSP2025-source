#include<bits/stdc++.h>
#define mod 998244353 
using namespace std;
long long n,a[5005],s[50005];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	s[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=a[i]+1;j<5002;++j)
			ans=(long long)(ans+s[j])%998244353;
		s[5001]=(long long)(s[5001]*2)%998244353;
		for(int j=5001-a[i];j<5001;++j)
			s[5001]=(long long)(s[5001]+s[j])%998244353;
		for(int j=5000;j>=a[i];--j)
			s[j]=(long long)(s[j]+s[j-a[i]])%998244353;
	}
	printf("%lld",ans);
	return 0;
}
