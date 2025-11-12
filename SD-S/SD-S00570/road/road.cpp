#include<bits/stdc++.h>
using namespace std;
int fa[1010];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int x=find(a),y=find(b);
	if(x==y) return;
	else fa[y]=x;
}
pair<int,pair<int,int> > e[1000010];
long long ans=0;
int c[23];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>e[i].second.first>>e[i].second.second>>e[i].first;
			fa[e[i].second.first]=e[i].second.first;
			fa[e[i].second.second]=e[i].second.second;
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++){
			int u=e[i].second.first;
			int v=e[i].second.second;
			if(find(u)!=find(v)){
				merge(u,v);
				ans+=e[i].first;
			}
		}
		cout<<ans<<'\n';
	
}
