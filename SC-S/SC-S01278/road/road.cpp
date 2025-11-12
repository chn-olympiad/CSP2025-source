#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1200005;
struct edge{int u,v,w;}E[M];
int n,m,k,kk[N],cnt;
long long ans;
vector<int>ve[M];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
void kruskal(){
	stable_sort(E+1,E+cnt+1,[](edge i,edge j){return i.w<j.w;});
	for(int i=1;i<=cnt;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)!=find(v))merge(u,v),ans+=w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,E[++cnt]={u,v,w};
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>kk[j];
			if(kk[j]==0)c=j;
		}
		for(int j=1;j<=n;j++){
			if(c==j)continue;
			E[++cnt]={c,j,kk[j]};
		}
	}
	kruskal();
	cout<<ans;
	return 0;
} 