//YangRuibin SN-S00408 TYZ
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],id[N],g[3],mxid,val[N],id2[N];
bool cmp(const int &x,const int &y)
{
	if(val[x]==-1&&val[y]==-1)
	{
		return x<y;
	}
	if(val[x]==-1)return 0;
	if(val[y]==-1)return 1;
	return val[x]-a[x][id[x]]>val[y]-a[y][id[y]];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)scanf("%d",a[i]+j);
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])id[i]=0,ans+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])id[i]=1,ans+=a[i][1];
			else id[i]=2,ans+=a[i][2];
		}
		g[0]=g[1]=g[2]=0;
		for(int i=1;i<=n;i++)++g[id[i]];
		if(g[0]>=g[1]&&g[0]>=g[2])mxid=0;
		else if(g[1]>=g[0]&&g[1]>=g[2])mxid=1;
		else mxid=2;
		if(g[mxid]<=n/2)
		{
			printf("%d\n",ans);continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(id[i]!=mxid)val[i]=-1;
			else if(id[i]==0)val[i]=max(a[i][1],a[i][2]);
			else if(id[i]==1)val[i]=max(a[i][0],a[i][2]);
			else val[i]=max(a[i][0],a[i][1]);
		}
		for(int i=1;i<=n;i++)id2[i]=i;
		sort(id2+1,id2+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(g[mxid]<=n/2)break;
			--g[mxid];
			ans=ans-a[id2[i]][mxid]+val[id2[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
