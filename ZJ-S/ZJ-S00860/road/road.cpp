#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e4+5;
const int maxm=1e6+5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &rhs) const {
		return w<rhs.w;
	}
}G[maxm<<1];
int fa[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int c[20];
int a[20][maxn];
long long res;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i) cin>>G[i].u>>G[i].v>>G[i].w;
	bool all_have_z=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		bool have_z=0;
		for(int j=1;j<=c[i];++j) cin>>a[i][j],have_z|=(a[i][j]==0);		
		all_have_z&=have_z;
	}
	if(k==0){
		sort(G+1,G+m+1);
		for(int i=1;i<=m;++i){
			int u=G[i].u,v=G[i].v,w=G[i].w;
			int uu=find(u),vv=find(v);
			if(uu==vv) continue;
			fa[uu]=vv;
			res+=w;
		}	
	}else if(all_have_z&&*max_element(c+1,c+k+1)==0){
		for(int i=1;i<=k;++i){
			int pos=min_element(a[i]+1,a[i]+n+1)-a[i];
			assert(a[i][pos]==0);
			for(int j=1;j<=n;++j)
				G[++m]=Edge{pos,j,a[i][j]};
		}
			
		sort(G+1,G+m+1);
		for(int i=1;i<=m;++i){
			int u=G[i].u,v=G[i].v,w=G[i].w;
			int uu=find(u),vv=find(v);
			if(uu==vv) continue;
			fa[uu]=vv;
			res+=w;
		}
	}else{
		 
	}
	cout<<res;
}
