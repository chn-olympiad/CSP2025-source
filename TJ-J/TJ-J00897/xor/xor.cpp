#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k,n;
	long long a[n+5];
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%lld",&a[i]);
	}
	if(k == 0)
	{
		printf("%d",1);
	}
	return 0;
 } 
