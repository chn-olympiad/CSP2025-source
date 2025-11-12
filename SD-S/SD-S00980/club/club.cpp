#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int a[maxn+10][5],b[maxn+10],cnt[maxn+10],d[maxn+10];
int m,mx,n,t;
long long sumn;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		sumn=0;
		for(i=1;i<=n;++i)
		{
			b[i]=1;
			for(j=1;j<=3;++j)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][b[i]])
					b[i]=j;
			}
			++cnt[b[i]];
			sumn+=a[i][b[i]];
		}
		mx=1;
		for(i=1;i<=3;++i)
			if(cnt[i]>cnt[mx])
				mx=i;
		if(cnt[mx]<=(n>>1))
		{
			printf("%lld\n",sumn);
			continue;
		}
		m=0;
		for(i=1;i<=n;++i)
		{
			if(b[i]==mx)
			{
				d[++m]=a[i][mx]-a[i][mx%3+1];
				d[m]=min(d[m],a[i][mx]-a[i][(mx+1)%3+1]);
			}
		}
		sort(d+1,d+m+1);
		for(i=1;i<=cnt[mx]-(n>>1);++i)
			sumn-=d[i];
		printf("%lld\n",sumn);
	}
	return 0;
}
