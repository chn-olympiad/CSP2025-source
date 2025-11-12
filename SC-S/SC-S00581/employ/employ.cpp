#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,cnt[510],ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld\n",&n,&m);
	for(long long i=1;i<=n;++i)
	{
		char x=getchar();
		cnt[i]=cnt[i-1]+x-'0';
	}
	if(cnt[n]<m)
		printf("0\n");
	else if(cnt[n]==n)
	{
		ans=1;
		for(long long i=1;i<=n;++i)
			ans=ans*i%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
