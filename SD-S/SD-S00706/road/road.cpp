#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
struct edge
{
	int u,v,w,fl;
}e[1000505],f[1055][10505],h[10005][15];
///e用于暂存生成树,f[0]存放原图树边，h存放乡镇的边 ,f[i]存状态为i时的可用边 
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int fa[10505],val[15],pc[1055];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int i,j,l,n,m,k,fu,fv,cnt=0,cnm;
	long long ans=0,sum;
	cin>>n>>m>>k;
	for(i=1;i<=1024;i++) pc[i]=pc[i/2]+i%2;
	for(i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,e[i].fl=0;
	for(i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		fu=find(e[i].u);
		fv=find(e[i].v);
		if(fu!=fv)
		{
			e[i].fl=1;
			cnt++;
			ans+=e[i].w;
			f[0][cnt]=e[i];
			fa[fu]=fv;
		}
		if(cnt==n-1) break;
	}
//	cout<<ans;
	//////////////////////////////////////
	for(i=1;i<=k;i++)
	{
		cin>>val[i];
		for(j=1;j<=n;j++)
		{
			h[j][i].u=n+i,h[j][i].v=j;
			cin>>h[j][i].w;
		}
	}
	for(i=1;i<(1<<k);i++)
	{
		int x=i-lowbit(i);
//		cout<<i<<" "<<x<<'\n';
		for(j=1;j<=n+k;j++) fa[j]=j;
		cnt=cnm=sum=0;
		for(j=1;j<=n+pc[x]-1;j++) e[++cnm]=f[x][j];
		for(j=1;j<=k;j++) if(i&(1<<(j-1))) sum+=val[j];
		for(j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				for(l=1;l<=n;l++) e[++cnm]=h[l][j];
				break;
			}
		}
		sort(e+1,e+cnm+1,cmp);
		for(j=1;j<=cnm;j++)
		{
			fu=find(e[j].u);
			fv=find(e[j].v);
			if(fu!=fv)
			{
				cnt++;
				sum+=e[j].w;
				f[i][cnt]=e[j];
				fa[fu]=fv;
			}
			if(cnt==n+pc[i]-1) break;
		} 
		ans=min(ans,sum);
	}
	cout<<ans;
}
