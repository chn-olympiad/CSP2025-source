#include<bits/stdc++.h>
using namespace std;
const int MXN = 200010;
const int inf = 2000000000;
int n,a[MXN][4],pos,ans,f[MXN],p[MXN],cnt,g[MXN];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		cnt=ans=pos=g[1]=g[2]=g[3]=0;
		scanf("%d",&n);
		#define a1 a[i][1]
		#define a2 a[i][2]
		#define a3 a[i][3]
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1>=a2&&a1>=a3) f[i]=1;
			else if(a2>=a1&&a2>=a3) f[i]=2;
			else f[i]=3;
			ans+=a[i][f[i]];
			g[f[i]]++;
		}
		if(g[1]*2>n) pos=1;
		if(g[2]*2>n) pos=2;
		if(g[3]*2>n) pos=3;
		if(!pos) 
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]!=pos) continue;
			p[++cnt]=inf;
			for(int j=1;j<=3;j++)
			{
				if(pos==j) continue;
				p[cnt]=min(p[cnt],a[i][pos]-a[i][j]);
			}
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt-n/2;i++) ans-=p[i];
		printf("%d\n",ans);
	}
	return 0;
}
