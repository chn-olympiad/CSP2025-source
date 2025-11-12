#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e17;
int n,m,M,cntm,cntn,k;
struct node{
	int u,v,w;
}g[1000005],e[1000005],cpy[1000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int c[20];
int a[15][100005];
bool used[1000005];
int fa[100005],siz[100005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	if(siz[fx]<siz[fy])
		swap(fx,fy);
	siz[fx]+=siz[fy],fa[fy]=fx;
	return 1;
}
void kruskal1(){
	for(int i=0;i<=n*2;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
		used[i]=merge(g[i].u,g[i].v);
}
int kruskal2(){
	int res=0;
	for(int i=0;i<=cntn*2;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=cntm;i++)
		if(merge(e[i].u,e[i].v))
			res+=e[i].w;
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(g+1,g+m+1,cmp);
//	for(int i=1;i<=m;i++)
//		cout<<g[i].u<<' '<<g[i].v<<' '<<g[i].w<<'\n';
	kruskal1();
	for(int i=1;i<=m;i++)
		if(used[i]){
			e[++M]=g[i],cpy[M]=e[M];
		}
	int S=1<<k,ans=inf;
	for(int T=0;T<S;T++){
		for(int i=1;i<=M;i++)
			e[i]=cpy[i];
		cntm=M,cntn=n;
		int res=0;
		for(int i=0;i<k;i++){
			if(T&(1<<i)){
				res+=c[i+1];
				cntn++;
				for(int j=1;j<=n;j++){
					e[++cntm].u=cntn;
					e[cntm].v=j;
					e[cntm].w=a[i+1][j];
				}
			}
		}
		sort(e+1,e+cntm+1,cmp);
		res+=kruskal2();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
