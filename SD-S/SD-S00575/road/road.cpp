#include<bits/stdc++.h>
using namespace std;
bool isa=1;
int n,m,k,tmp1,tmp2,tmp3,nwm,ans,totans=2025111355;
struct edge{
	int u,v,w;
}e[1001538],pre[1111554];
int a[15][10041];
int c[15];
int father[10046];
bool vis[16];
int Find(int u){
	if(father[u]==u)return u;
	return father[u]=Find(father[u]);
}
void Union(int u,int v){
	u=Find(u);
	v=Find(v);
	if(u==v)return;
	father[u]=father[v];
	return;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void chk(){
	ans=0;
	for(int i=1;i<=k;i++)ans+=(int)(vis[i])*c[i];
	nwm=m;
	for(int i=1;i<=m;i++)pre[i]=e[i];
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=k;i++){
		if(!vis[i])continue;
		father[n+i]=(n+i);
		for(int ii=1;ii<=n;ii++)pre[nwm+ii]={ii,n+i,a[i][ii]};
		nwm+=n;
	}
	sort(pre+1,pre+nwm+1,cmp);
	for(int i=1;i<=nwm;i++){
		if(Find(pre[i].u)==Find(pre[i].v))continue;
		Union(pre[i].u,pre[i].v);
		ans+=pre[i].w;
	}
	totans=min(totans,ans);
	return;
}
void dfs(int x,int sel){
	if(x>k){
		chk();
		return;
	}
	vis[x]=1;
	dfs(x+1,sel+1);
	vis[x]=0;
	dfs(x+1,sel);
	return;
}
void svk0(){
	ans=0;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++){
		if(Find(e[i].u)==Find(e[i].v))continue;
		Union(e[i].u,e[i].v);
		ans+=e[i].w;
	}
	cout<<ans<<endl;
	return;
}
void sva(){
	memset(vis,1,sizeof(vis));
	chk();
	cout<<ans<<endl;
	return;
}
void svk5(){
	dfs(1,0);
	cout<<totans<<endl;
	return;
}
void svall(){
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>tmp1>>tmp2>>tmp3;
		e[i].u=tmp1;
		e[i].v=tmp2;
		e[i].w=tmp3;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])isa=0;
		for(int ii=1;ii<=n;ii++)cin>>a[i][ii];
	}
	if(k==0)svk0();
	else if(isa)sva();
	else if(k<=5)svk5();
	else svall();
	return 0;
}
/*































*/
