#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=2e6+5;
struct Edge{
	int u,v,w,idx;
}e[M],g[M],e1[N];
int n,m,k,f[N],siz[N],c[N],a[20][N],tot,nd;
long long ans;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int u){
	return f[u]==u?u:f[u]=find(f[u]);
}
bool merge(int u,int v){
	int x=find(u),y=find(v);
	if(x==y) return 0;
	if(siz[x]<siz[y]) swap(x,y);
	f[y]=x; siz[x]+=siz[y];
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].idx=i;
	}
	bool opA=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]) opA=0;
		bool t=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0) t=1;
		}
		if(!t) opA=0;
	}
	if(opA){
		tot=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				g[++tot]={n+i,j,a[i][j],m+1};
			}
		}
		sort(e+1,e+m+1,cmp);
		sort(g+1,g+tot+1,cmp);
		for(int i=1;i<=n+k;i++) f[i]=i,siz[i]=1;
		int ii=1,jj=1;
		for(;ii<=m||jj<=tot;){
			if(e[ii].w<g[jj].w||jj>tot){
				if(merge(e[ii].u,e[ii].v)){
					ans+=e[ii].w*1ll;
				}
				ii++;
			}else{
				if(merge(g[jj].u,g[jj].v)){
					ans+=g[jj].w*1ll;
				}
				jj++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++) f[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			e1[++nd]=e[i];
		}
	}
	for(int s=0;s<=(1<<k)-1;s++){
		long long tmp=0;
		int cnt1=0;
		tot=0;
//		cout<<s<<":\n";
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				tmp+=c[i]; cnt1++;
				for(int j=1;j<=n;j++){
					g[++tot]={n+i,j,a[i][j],m+1};
				}
			}
		}
		if(tmp>ans) continue;
		sort(g+1,g+tot+1,cmp);
		for(int i=1;i<=n+k;i++) f[i]=i,siz[i]=1;
		int cnt=0;
		int ii=1,jj=1;
		for(;ii<=nd||jj<=tot;){
			if(cnt==n+cnt1-1) break;
			if(e1[ii].w<g[jj].w||jj>tot){
				if(merge(e1[ii].u,e1[ii].v)){
					tmp+=e1[ii].w*1ll; cnt++;
				}
				ii++;
			}else{
				if(merge(g[jj].u,g[jj].v)){
					tmp+=g[jj].w*1ll; cnt++;
				}
				jj++;
			}
		}
//		cout<<tmp<<endl;
		if(tmp<ans) ans=tmp;
	}
	printf("%lld",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
/*
先求原图的最小生成树
加了新的边之后，一定不会选之前不在最小生成树中的边
这样边数降为1e4
复杂度约为1024*1e5+1024*1e5*16

*/