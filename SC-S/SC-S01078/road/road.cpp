#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
struct edge{
	int u,v,w;
	edge(int uu,int vv,int ww){
		u=uu; v=vv; w=ww;
	}
};
vector<edge> v;
int n,m,k,fa[maxn],a[maxn],w[maxn][maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return find(fa[x]);
}
int cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(w,0x3f,sizeof(w));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww; cin>>uu>>vv>>ww;
		v.push_back(edge(uu,vv,ww));
		w[uu][vv]=min(w[uu][vv],ww); w[vv][uu]=min(w[vv][uu],ww);
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		int c; cin>>c;
		for(int j=1;j<=n;j++) cin>>a[i];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]+a[k]+c<w[j][k]) v.push_back(edge(j,k,a[j]+a[k]+c));
			}
		}
	}	
	for(int i=1;i<=n;i++) fa[i]=i;
	int tot=0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		int fu=find(v[i].u),fv=find(v[i].v);
		if(fu!=fv){
			ans+=v[i].w; fa[fu]=fv; tot++;
			if(tot==n-1) break;
		}
	}
	cout<<ans;
	return 0;
}