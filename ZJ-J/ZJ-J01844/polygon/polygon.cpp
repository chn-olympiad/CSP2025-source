#include<bits/stdc++.h>
using namespace std;
const long long p=998244353ll;
long long n,a[5001],ans;
void dfs(long long x,long long maxa,long long sum)
{
	if(x>n) 
	{
		if((maxa<<1)<sum) ans++;
		return;
	}
	dfs(x+1,max(maxa,a[x]),sum+a[x]);
	dfs(x+1,maxa,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0,0);
	printf("%lld\n",ans%p);
	return 0;
}