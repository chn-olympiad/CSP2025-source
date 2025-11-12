#include<bits/stdc++.h>
using namespace std;
const int N=1500000;
struct node{
	int fs,se,td;
}e[N],e1[N];
int fa[N],val[25];
long long res=1e18;
int n,k;
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void kruskal(int cs);
bool cmp(node a,node b){
	return a.td<b.td;
}
int cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+10;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].fs,v=e[i].se,w=e[i].td;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		e1[++cnt]=e[i];
		fa[fv]=fu;
		ans+=w;
	}
	res=min(res,ans);
//	cout<<ans<<"\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<e1[i].fs<<" "<<e1[i].se<<" "<<e1[i].td<<"\n";
//	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e1[++cnt]={i+n,j,w};
		}
	}
	sort(e1+1,e1+cnt+1,cmp);
	
	for(int i=1;i<(1<<k);i++){
		kruskal(i);
	}
	cout<<res;
	return 0;
}
void kruskal(int cs){
	long long ans=0;
	for(int i=1;i<=n+10;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=e1[i].fs,v=e1[i].se,w=e1[i].td;
		if(u>n&&((1<<(u-n-1))&cs)==0) continue;
//		if(u>n) cout<<u-n<<"***"<<cs<<"   ";
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fv]=fu;
		ans+=w;
	}
	for(int i=1;i<=n;i++) if(find(i)!=find(1)) return;
	for(int i=1;i<=k;i++){
		if((1<<(i-1)&cs)) ans+=val[i];
	}
//	cout<<cs<<" "<<ans<<"\n";
	res=min(res,ans);
}
