#include <bits/stdc++.h>
using namespace std;
long long a[5555];
long long ret = 0;
long long n;
const long long P = 998244353;
void dfs(int id,long long sum,long long mx,long long cnt)
{
	if(id == n + 1)
	{
		if(sum > mx * 2 && cnt >= 3)
		{
			ret++;
			ret = ret % P;
		}
		return ;
	}
	dfs(id + 1,sum + a[id],max(mx,a[id]),cnt + 1);
	dfs(id + 1,sum,mx,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	long long mxxx = 0;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		mxxx = max(mxxx,a[i]);
	}
	if(n < 3)
	{
		printf("0");
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ret);
	return 0;
}
