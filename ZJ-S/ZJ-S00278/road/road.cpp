#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
const int N=1e4+10;
struct node{
	int u,v,w;
}a[1000010],b[N],c[12][N],d[20*N],e[20*N];
long long ans;
int fa[N+10];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	return fa[x]!=x?fa[x]=find(fa[x]):x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv)
		{
			ans+=a[i].w;
		    b[++cnt]=a[i];
			fa[fv]=fu;
		}
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0].w;
		for(int j=1;j<=n;j++) 
		{
			c[i][j].u=n+i;c[i][j].v=j;
			cin>>c[i][j].w;
		}
		sort(c[i]+1,c[i]+n+1,cmp);
	}
	for(int s=1;s<(1<<k);s++)
    {
    	int cntnode=n,cntedge=cnt;
		long long res=0;int bo=0;
    	for(int i=1;i<=cnt;i++) e[i]=d[i]=b[i];
    	for(int i=1;i<=k;i++)
    	{
    		if((s&(1<<i-1))==0) continue;
    		cntnode++;res+=c[i][0].w;
    		if(res>=ans) 
    		{
    			bo=1;
    			break;
			}
    		int j=1,k=1,num=0;
    		for(;j<=n&&k<=cntedge;j++)
			{
				while(d[k].w<=c[i][j].w&&k<=cntedge) e[++num]=d[k++];
				e[++num]=c[i][j];
			}
			while(j<=n) e[++num]=c[i][j++];
			while(k<=cntedge) e[++num]=d[k++];
		    for(int j=1;j<=num;j++) d[j]=e[j];
			cntedge=num; 
		}
		if(bo) continue;
//		cout<<s<<":"<<'\n';
//		for(int i=1;i<=cntedge;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';cout<<'\n';
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int choose=0;
		for(int i=1;i<=cntedge;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv)
			{
				fa[fv]=fu;res+=e[i].w;
				if(res>=ans) break;
				choose++;
				if(choose==cntnode-1) break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}