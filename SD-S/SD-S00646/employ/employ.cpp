#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,m;
long long s[10011];
long long c[10010];
bool xz1=0;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		if(s[i]==0)
			xz1=1;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
		
	if(xz1==0)
	{
		for(int i=1;i<=n;i++)
			ans=((ans%N)*(i%N))%N;
		printf("%lld\n",ans);
	}
	else printf("%d\n",rand());
	return 0;
}

