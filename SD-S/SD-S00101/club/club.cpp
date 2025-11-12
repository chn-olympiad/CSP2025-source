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
const ull N=100010;
ull T,n,a[N][4],d[N],e[N];
ull ans;
ull c[4];
ull b[N];
ull tot;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%llu",&T);
	while(T--)
	{
		scanf("%llu",&n);ans=0;tot=0;
		for(ull i(1);i<=n;++i) scanf("%llu%llu%llu",&a[i][1],&a[i][2],&a[i][3]);
		c[1]=c[2]=c[3]=0;
		for(ull i(1);i<=n;++i)
		{
			d[i]=e[i]=0;
			a[i][0]=0;
			for(ull j(1);j<=3;++j) if(a[i][j]>=a[i][d[i]]) d[i]=j;
			for(ull j(1);j<=3;++j) if(j!=d[i]&&a[i][j]>=a[i][e[i]]) e[i]=j;
			++c[d[i]];ans+=a[i][d[i]];
		}
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)
		{
			printf("%llu\n",ans);
			continue;
		}
		ull p=1;
		if(c[2]>n/2) p=2;
		if(c[3]>n/2) p=3;
		for(ull i(1);i<=n;++i)
		{
			if(d[i]!=p) continue;
			++tot;
			b[tot]=a[i][d[i]]-a[i][e[i]];
		}
		std::sort(b+1,b+tot+1);
		for(ull i(1);i<=c[p]-n/2;++i) ans-=b[i];
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
