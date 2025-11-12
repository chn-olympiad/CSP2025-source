#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100002]{-1},s[12][100002],c[102];
int vis[8002][8002];
int ans=0;
int get(int x){
	if(fa[x]==x)	return x;
	else return fa[x]=get(fa[x]);
}
struct edge{
	int u,v,w;
}a[100002];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		vis[a[i].u][a[i].v]=i;
		vis[a[i].v][a[i].u]=i;
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>s[i][j];
		}
		for(int j=1;j<=n;++j){
			for(int p=1;p<=n;++p)
			{
				if(j!=p&&vis[j][p]==0)
				{
					m++;
					a[m].u=j;
					a[m].v=p;
					a[m].w=c[i]+s[i][j]+s[i][p];
				}
				else
					if(j!=p)
					{
						a[vis[j][p]].w=min(a[vis[j][p]].w,c[i]+s[i][j]+s[i][p]);
					}
			}
		}
	}
	for(int i=1;i<=n;++i)
		fa[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		int x=a[i].u,y=a[i].v;
		if(get(x)!=get(y))
		{
			fa[get(x)]=get(y);
			ans+=a[i].w;	
		}
	}
	cout<<ans;
	return 0;
}
