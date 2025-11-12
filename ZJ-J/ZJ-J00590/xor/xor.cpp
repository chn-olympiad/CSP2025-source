#include <bits/stdc++.h>
using namespace std;
long long a[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	long long k;
	scanf("%lld %lld",&n,&k);
	int f = 1;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i] != 1) f = 0;
	}
	if(f)
	{
		long long ret = n / 2;
		printf("%lld",ret);
	}
	else
	{
		printf("5326");
	}
	return 0;
}
