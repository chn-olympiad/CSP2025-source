#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1300010,M=200000,W=10010;
struct node{
	int u,v,w;
}e[N],f[N],val[11][W],wx[N];
inline bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[M],qwq[20],a[11][W];
inline int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int tot=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	ll awa=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			f[++tot]=e[i];
			fa[x]=y;
			awa+=e[i].w;
		}
	}
	int s=m;
	for(int i=1;i<=k;i++){
		cin>>qwq[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			val[i][j]={i+n,j,a[i][j]};
		}
		sort(val[i]+1,val[i]+n+1,cmp);
	}
	ll ans=awa;
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=tot;j++)e[j]=f[j];
		int tmp=tot;
		ll res=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				res+=qwq[j];
				int l=1,r=1;
				int nt=0;
				while(l<=tmp&&r<=n){
					while(val[j][r].w<=e[l].w&&r<=n)wx[++nt]=val[j][r++];
					while(val[j][r].w>e[l].w&&l<=tmp)wx[++nt]=e[l++];
				}
				while(l<=tmp)wx[++nt]=e[l++];
				while(r<=n)wx[++nt]=val[j][r++];
				for(int d=1;d<=nt;d++)e[d]=wx[d];
				tmp=nt;
			}
		}
		for(int j=1;j<=tmp;j++){
			int x=find(e[j].u),y=find(e[j].v);
			if(x!=y){
				res+=e[j].w;
				fa[x]=y;
			}
			if(res>ans)break;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
