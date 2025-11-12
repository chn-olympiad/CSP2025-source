#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int u,v,w;
	bool operator<(const edge &o)const{
		return w<o.w;
	}
}e[1000005];
int a[15][10005];
int fa[10015],c[15];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		fa[u]=v;
	}
}
bool build(int x,int tmp){
	return (tmp>>(x-1))&1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	bool flagA=true;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flagA=false;
		bool flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) flag=true;
		}
		if(!flag) flagA=false;
	}
	sort(e+1,e+1+m);
	
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		ll ans=0;
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)==find(v)) continue;
			ans+=e[i].w;
			join(u,v);
		}
		cout<<ans<<'\n';
		return 0;
	}
	vector<edge> e2;
	for(int i=1;i<=n;i++) fa[i]=i;
	ll ans=0;
	int maxw=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		e2.push_back(e[i]);
		ans+=e[i].w;
		maxw=max(maxw,e[i].w);
		join(u,v);
	}
	for(int tmp=1;tmp<(1<<k);tmp++){
		ll res=0;
		vector<edge> e3=e2;
		for(int i=1;i<=k;i++) if(build(i,tmp)){
			res+=c[i];
			for(int j=1;j<=n;j++) if(a[i][j]<=maxw) e3.push_back((edge){n+i,j,a[i][j]});
		}
		int len=e3.size();
		sort(e3.begin(),e3.end());
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=0;i<len;i++){
			if(find(e3[i].u)!=find(e3[i].v)){
				res+=e3[i].w;
				if(res>=ans) break;
				///if(tmp==1) cout<<e3[i].u<<' '<<e3[i].v<<' '<<e3[i].w<<'\n';
				join(e3[i].u,e3[i].v);
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
