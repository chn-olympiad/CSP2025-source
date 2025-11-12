#include<bits/stdc++.h>
using namespace std;
int n,k,a[(1<<20)+17],x[500005],t;
long long sum;
int main()
{
//	system("fc xor6.ans xor.out");
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(a,-1,sizeof a);
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		x[i]^=x[i-1];
		if(a[x[i]^k]>=t) sum++,t=i;
		a[x[i]]=i;
	}
	printf("%lld",sum);
	return 0;
}
