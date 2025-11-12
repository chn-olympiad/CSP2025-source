#include <bits/stdc++.h>
using namespace std;
#define ll long long//注意long long 开够没
const int M=2e6+10,N=2e4+10;
struct node
{
	int u,v,w;
}bi[M],c[N];
bool cmp(node x,node y){return x.w<y.w;}
int n,zn,m,k,cc[N],fa[N],vis[N];
ll ans=1e18,res;
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void kru(int lx)
{
	int cnt=0; 
	for(int i=1;i<=m;i++)
	{
		int u=bi[i].u,v=bi[i].v,w=bi[i].w;
		if(u>=n+1&&!vis[u])continue;//不能用 
		int f1=find(u),f2=find(v);
		if(f1!=f2)
		{
			fa[f2]=f1;
			res+=w;
			cnt++;
			if(lx)c[cnt]=bi[i];
		} 
		if(cnt==zn-1||res>ans)break;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>bi[i].u>>bi[i].v>>bi[i].w;
	sort(bi+1,bi+m+1,cmp);
	zn=n; 
	for(int i=1;i<=n;i++)fa[i]=i;
	kru(1);
	ans=res; //不考虑乡镇的答案 
	for(int i=1;i<=n-1;i++)bi[i]=c[i];//只保留可能成为最小的边 
	m=n-1;
	for(int i=1;i<=k;i++)
	{
		cin>>cc[i];
		for(int j=1;j<=n;j++)
		{
			bi[++m].u=i+n,bi[m].v=j;
			cin>>bi[m].w;
		}	
	}
	sort(bi+1,bi+m+1,cmp);//将可能的边排序 
	for(int s=0;s<(1<<k);s++)//枚举选的乡镇 
	{
		res=0;zn=n;
		for(int i=1;i<=k;i++)
		{
			if((s>>(i-1))&1)vis[n+i]=1,res+=cc[i],fa[n+i]=n+i,zn++;
			else vis[n+i]=0;
		}
		for(int i=1;i<=n;i++)fa[i]=i;
		kru(0);
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}