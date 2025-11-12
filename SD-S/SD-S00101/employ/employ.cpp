#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
typedef unsigned long long ull;
typedef long long ll;
const ull N=20,pwN=(1ull<<18)+10,md=998244353;
ull n,m,ans;
char s[N];
ull c[N];
ull f[pwN][N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%llu%llu%s",&n,&m,s+1);
	for(ull i(1);i<=n;++i) scanf("%llu",&c[i]);
	f[0][0]=1;
	for(ull w(0);w<1ull<<n;++w)
	{
		ull cnt=0;
		for(ull x=w;x;x&=x-1) ++cnt;
		for(ull k(0);k<=n;++k)
		{
//			printf("%llu;%llu: %llu\n",w,k,f[w][k]);
			for(ull p(1);p<=n;++p)
			{
				if((w>>(p-1))&1) continue;
				if(cnt-k>=c[p]||s[cnt+1]=='0') (f[w|(1ull<<(p-1))][k]+=f[w][k])%=md;
				else (f[w|(1ull<<(p-1))][k+1]+=f[w][k])%=md;
			}
		}
	}
	for(ull i(m);i<=n;++i) (ans+=f[(1ull<<n)-1][i])%=md;
	printf("%llu",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// gan jue ke yi you hua cheng n^3 : w(0,2^n) => cnt(0,n)
