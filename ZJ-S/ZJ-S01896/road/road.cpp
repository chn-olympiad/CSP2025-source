#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long c[11],ac[10004][11];
int fa[10004];
struct edge{
	int u,v,w;
	long long w0;
};
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<edge>e;
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ac[j][i];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			long long x=LONG_LONG_MAX;
			for(int l=1;l<=k;l++){
				x=min(x,ac[i][l]+ac[j][l]+c[l]);
			}
			e.push_back({i,j,x});
		}
	}
	sort(e.begin(),e.end(),cmp);
	int cnt=0;
	for(int i=0;i<m;i++){
		edge now=e[i];
		int u=now.u,v=now.v,w=now.w;
		if(find(u)==find(v))continue;
		long long res=w;
		ans+=res;
		//cout<<u<<" "<<v<<" "<<res<<"\n";
		fa[fa[u]]=fa[v];
		cnt++;
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}

