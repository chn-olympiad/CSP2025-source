#include<bits/stdc++.h>
using namespace std;
int n,k,Max1,Max2[500005],pre[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",pre+i);
		pre[i]^=pre[i-1];
	}
	memset(Max2,-1,sizeof(Max2));
	for(int i=1;i<=n;++i)
	{
		f[i]=max(Max1,Max2[pre[i]]+1);
		Max1=max(f[i],Max1);
		Max2[pre[i]^k]=f[i];
	}
	printf("%d",f[n]);
	return 0;
}
