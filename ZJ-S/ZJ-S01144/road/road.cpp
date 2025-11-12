#include<bits/stdc++.h>
using namespace std;
int fa[10010];
long long ans;
int fd(int x){
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}
struct ikun{
	int u,v;
	long long w;
};
bool cmp(ikun a,ikun b){
	return a.w<b.w;
}
vector<ikun>road;
struct d114{
	int u,w;
};
vector<d114>mp;
void solve(){
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		road.push_back({u,v,w});
	}
	
	long long w[15][1010];
	long long cw[15];
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>cw[i];
		if(cw[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
			if(w[i][j]!=0)flag=0;
		}
	}
	
	//zui xiao tree
	//int cv=0;
	sort(road.begin(),road.end(),cmp);
	for(int i=0;i<road.size();i++){
		if(fd(road[i].u)!=fd(road[i].v)){
			ans+=road[i].w;
			for(int j=1;j<=k;j++){
				
			}
			fa[road[i].v]=road[i].u;
		}
	}
	if(flag)cout<<0;
	else cout<<ans;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
