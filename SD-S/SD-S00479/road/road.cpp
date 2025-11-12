#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=2e6+1000,M2=2e4+100;
lint n,m,k;
struct stu{
	lint u,v,w;
}lu[M1];
lint uu,vv,ww;
lint fa[M1];
lint find(lint x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]); 
}
void merge(lint x,lint y)
{
	lint rx=find(x);
	lint ry=find(y);
	if(rx!=ry) fa[ry]=rx;
}
bool cmp(stu a,stu b)
{
	return a.w<b.w;
}
lint c[20],cc[20][M2];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0)
	{
		for(lint i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&lu[i].u,&lu[i].v,&lu[i].w);
		}
		sort(lu+1,lu+m+1,cmp);
		for(lint i=1;i<=n;i++) fa[i]=i;
		lint sum=0,op=0;
		for(lint i=1;i<=m;i++)
		{
			lint opu=find(lu[i].u);
			lint opv=find(lu[i].v);
			if(opu==opv) continue;
			merge(opu,opv);
			sum+=lu[i].w;
			op++;
			if(op==n-1) break;
		}
		printf("%lld\n",sum);
	}
	else
	{
		for(lint i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&uu,&vv,&ww);
		}
		for(lint i=1;i<=k;i++)
		{
			scanf("%lld",&c[i]);
			bool o=0;
			if(c[i]==0) o=1;
			for(lint j=1;j<=n;j++)
			{
				scanf("%lld",&cc[i][j]);
				if(cc[i][j]!=0) o=0;
			}
			if(o==1)
			{
				printf("0\n");
				return 0;
			}
		} 
	}
	return 0;
}
