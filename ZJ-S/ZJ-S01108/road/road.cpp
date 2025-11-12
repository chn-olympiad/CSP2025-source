#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int u,v,w;
};
edge e[1100005];
int n,m,k,cnt,fre;
ll ans;
int fa[10015], c[15];
int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
bool comp(edge p,edge q){
	return p.w<q.w;
}
void kus(){
	cnt=0;
	sort(e+1,e+1+m,comp);
	for(int i=1; i<=m; i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		fa[fu] = fv;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1+fre) break;
	}
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	if(k==0){
	  kus();
	  return 0;
	} 
	fre=0;
	for(int i=1; i<=k; i++){
		int id=n+i;
		fa[id]=id;
		cin>>c[i];
		if(c[i]==0) fre++;
		for(int j=1; j<=n; j++){
			int w;
			scanf("%d",&w);
			if(c[i]==0){
				e[++m].u=id;
				e[m].v=j;
				e[m].w=w;
			}
		}
	}
	kus();
	return 0;
}