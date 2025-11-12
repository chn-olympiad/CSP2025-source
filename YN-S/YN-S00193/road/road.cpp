#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005,M=1000020,Inf=1e18;
struct edge{
	int u,v,w;
}e[M],re[N*20],pe[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N],tot,c[13],a[13][N],n,k,ans;
bool use[N];
int fd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
int check(){
	int tot2=0,cnt=0,res=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=tot;i++) re[i]=pe[i];
	for(int i=1;i<=k;i++){
		if(!use[i]) continue;
		res+=c[i];
		for(int j=1;j<=n;j++) tot2++,re[tot2+tot]={j,n+i,a[i][j]};
	}
	sort(re+1,re+(tot+tot2+1),cmp);
	for(int i=1;i<=tot+tot2;i++){
		int fd1=fd(re[i].u),fd2=fd(re[i].v);
		if(fd1==fd2) continue;
		fa[fd1]=fd2;res+=re[i].w;
	}
	return res;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,check());
		return;
	}
	use[x]=0;dfs(x+1);
	use[x]=1;dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m,u,v,w;ans=Inf;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fd1=fd(e[i].u),fd2=fd(e[i].v);
		if(fd1==fd2) continue;
		fa[fd1]=fd2;pe[++tot]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//16:20 finish ?~100
//有点卡线 5e7 常数大 自测卡满18.94s
//lsy 保佑我这题冲过去1s以内100pts