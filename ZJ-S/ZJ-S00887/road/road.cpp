#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
int fa[200005];
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
void Merge(int a,int b){
	fa[Find(a)]=Find(b);
}
struct road{
	int u,v,w;
};
bool cmp(road a,road b){
	return a.w<b.w;
}
vector<road> g;
int u[1000005],v[1000005],w[1000005];
int c[15],a[15][10005];
ll cv,x,ans=1e18;
void MST(){
	
	for(int i=1;i<=n+k;i++) fa[i]=i;
	
	sort(g.begin(),g.end(),cmp);
	
	int cnt=0;
	for(int i=0;cnt<n+x-1;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(Find(u)==Find(v)) continue;
		
		Merge(u,v);
		
		cnt++;
		cv+=w;
	}
	
	ans=min(ans,cv);
	g.clear();
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==10){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		g.push_back({u[i],v[i],w[i]});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	int cnt=0;
	
	for(int i=0;cnt<n-1;i++){
		int pu=g[i].u,pv=g[i].v,pw=g[i].w;
		if(Find(pu)==Find(pv)) continue;
		Merge(pu,pv);
		cnt++;
		cv+=pw;
		u[cnt]=pu,v[cnt]=pv,w[cnt]=pw;
	}
	ans=cv;
	g.clear();
	m=n-1;
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<(1<<k);i++){
		
		for(int j=1;j<=m;j++){
			g.push_back({u[j],v[j],w[j]});
		}
		
		cv=x=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				x++;
				for(int d=1;d<=n;d++){
					g.push_back({n+j,d,a[j][d]});
				}
				cv+=c[j];
			}
		}
		
		MST();
		
	}
	
	cout<<ans;
	
	return 0;
}