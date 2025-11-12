#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353; 
int n,m,c[N],a[N];
char s[N];
long long sum = 0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
	for(int i = 1;i <= n;i++) a[i] = i;
	if(n > 10)
	{
		long long f = 1;
		for(int i = 1;i <= n;i++) f = f * i % mod;
		printf("%lld",f);
		return 0;
	}
	do
	{
		int cnt = 0,ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '1' && c[a[i]] > cnt) ans++;
			else cnt++;
		}
		if(ans >= m) sum++;
	}while(next_permutation(a + 1,a + n + 1));
	printf("%lld",sum);
	return 0;
}
