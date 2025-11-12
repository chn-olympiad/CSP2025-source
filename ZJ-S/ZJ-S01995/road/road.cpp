#include<bits/stdc++.h>//wo cao ni ma!!!!!!!!!!!!!!!!!!!wei shen me yao ka wo chang!!!!!!!!!!!!!!!!!!!!!!!!!
#define min(a,b) (a<b?a:b)
using namespace std;
int n,m,k,fa[11451],t,d[11][11451];
long long ans;
bool p[11]={1};
struct node{
	int u,v,w,id;
}b[1001451],c[214514];
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
inline long long ck(){
	long long ans=0,gg=0;
	for(register int i=1;i<=n+10;i++)fa[i]=i;
	for(register int i=1;i<=k;i++){
		if(!p[i])continue;
		ans+=d[i][0];gg++;
	}
	for(register int i=1,tot=0;i<=t&&tot<n+gg-1;i++){
		if(!p[b[i].id])continue;
		int fx=find(b[i].u),fy=find(b[i].v);
		if(fx==fy)continue;
		tot++;fa[fx]=fy;ans+=b[i].w;
	}
	return ans;
}
inline void dfs(int dep){
	if(dep>k){
		ans=min(ans,ck());
		return;
	}
	p[dep]=0;
	dfs(dep+1);
	p[dep]=1;
	dfs(dep+1);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(register int i=1;i<=n;i++)fa[i]=i;
	for(register int i=1;i<=m;i++)cin>>b[i].u>>b[i].v>>b[i].w;
	sort(b+1,b+m+1,cmp);
	for(register int i=1;i<=m&&t<n-1;i++){
		int fx=find(b[i].u),fy=find(b[i].v);
		if(fx==fy)continue;
		c[++t]=b[i];fa[fx]=fy;ans+=b[i].w;
	}
	t=n-1;
	for(register int i=1;i<=k;i++)for(register int j=0;j<=n;j++)cin>>d[i][j];
	for(register int i=1;i<n;i++)b[i]=c[i];
	for(register int i=1;i<=k;i++)for(register int j=1;j<=n;j++)b[++t]={n+i,j,d[i][j],i};
	sort(b+1,b+t+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
