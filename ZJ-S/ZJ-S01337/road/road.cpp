#include<bits/stdc++.h>
//#define int long long
#define PII pair<int,int>
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
struct Edge{
	int u,v,w;
	bool used;
};
vector<Edge>edg,tmp;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int fa[20005],a[15][10005],c[15],siz,n,m,k;
long long ans=INF,res=0;
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
inline long long kruskal(){
	int tot=0;
	long long ret=0;
	for(int i=1;i<=siz;++i)fa[i]=i;
	sort(edg.begin(),edg.end(),cmp);
	for(Edge &ed:edg){
		int u=ed.u,v=ed.v,w=ed.w;
		if(getfa(u)==getfa(v))continue;
		++tot,fa[getfa(u)]=getfa(v),ret+=w,ed.used=1;
		if(tot>=siz-1)break;
	}
	return ret;
}
void dfs(int x){
	if(x>k){
		edg=tmp,ans=min(ans,res+kruskal());
		return;
	}
	dfs(x+1);
	++siz,res+=c[x];
	for(int i=1;i<=n;++i)tmp.push_back({siz,i,a[x][i],0});
	dfs(x+1);
	for(int i=1;i<=n;++i)tmp.pop_back();
	--siz,res-=c[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),siz=n;
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		edg.push_back({u,v,w,0});
	}kruskal();
	for(Edge ed:edg)if(ed.used==1)tmp.push_back(ed);
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

