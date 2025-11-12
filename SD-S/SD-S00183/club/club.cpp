#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return x;
}
int a[100010][3],p[100010],d[100010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd();
	while(t--)
	{
		int n=rd(),cnt[3]={0},tot=0,ov=3,ans=0;
		for(int i=1;i<=n;i++)
			a[i][0]=rd(),
			a[i][1]=rd(),
			a[i][2]=rd();
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		{
			if(a[i][p[i]]<a[i][1])p[i]=1;
			if(a[i][p[i]]<a[i][2])p[i]=2;
			cnt[p[i]]++;
			ans+=a[i][p[i]];
		}
		for(int i=0;i<3;i++)
			if(cnt[i]>n/2)ov=i;
		if(ov==3){printf("%lld\n",ans);continue;}
		for(int i=1;i<=n;i++)
			if(p[i]==ov)
			{
				if(ov==0)
					d[tot++]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				else if(ov==1)
					d[tot++]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				else
					d[tot++]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
			}
		sort(d,d+tot);
		for(int de=0;cnt[ov]-de>n/2;de++)
			ans-=d[de];
		printf("%lld\n",ans);
	}
	return 0;
}
