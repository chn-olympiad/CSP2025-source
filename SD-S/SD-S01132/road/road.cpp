#include<bits/stdc++.h> 
using namespace std;
vector <array<int,2> > gra[1000010];
bool vis[100010];
vector <array<int,2> >prim[1000010];
vector <array<int,2> >aa[1000010];
long long vi[10][100010];
bool vis2[100010];
int num[20];
long long n,m,k,asn,ans=0,cnt=0;
void hy(){
	for(int i=1;i<=n;i++){
		aa[i].clear();
		for(auto ll:prim[i]){
			aa[i].push_back(ll);
		}
	}
	return ;
}
void plu(int i){
	asn+=vi[i][0];
	cnt++;
	for(int j=1;j<=n;j++){
		aa[j].push_back({n+i,vi[i][j]});
		aa[n+i].push_back({j,vi[i][j]});
	}
	return ;
}
void pri(){
	vector <int> vis0(100010);
	priority_queue <array<int,3>,vector<array<int,3> >,greater<array<int,3> > >q;
	q.push({0,1,0});
	int p=0;
	while(!q.empty()&&p<n+cnt+1){
		int w=q.top()[0];
		int v=q.top()[1];
		int fa=q.top()[2];
		q.pop(); 
		if(vis0[v]){
			continue;
		}
		asn+=w;
		p++;
		vis0[v]=1;
		for(auto k:aa[v]){
			q.push({k[1],k[0],v});
		}
//		cout<<asn<<" "<<w<<" "<<v<<' '<<fa<<"\n";
	}
}
void dfs(int sum){
	if(sum==k+1){
//		memset(vis,0,sizeof vis);
		asn=0,cnt=0;
		hy();
		for(int i=1;i<=k;i++){
			if(num[i]){
				plu(i);
			}
		}
		pri();
		ans=min(ans,asn);
//		cout<<asn<<"\n";
		return ;
	}
	num[sum]=0;
	dfs(sum+1);
	num[sum]=1;
	dfs(sum+1);
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].push_back({v,w});
		gra[v].push_back({u,w});
	} 
	priority_queue <array<int,3>,vector<array<int,3> >,greater<array<int,3> > >q;
	q.push({0,1,0});
	int p=0;
	while(!q.empty()&&p<n){
		int w=q.top()[0];
		int v=q.top()[1];
		int fa=q.top()[2];
		q.pop(); 
		if(vis[v]){
			continue;
		}
		ans+=w;
		p++;
		vis[v]=1;
		prim[fa].push_back({v,w});
		prim[v].push_back({fa,w});
		for(auto k:gra[v]){
			q.push({k[1],k[0],v});
		}
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>vi[i][j];
		}
	}
	dfs(1);
	cout<<ans<<"\n";
//	for(int i=0;i<prim.size();i++){
//		cout<<prim[i][0]<<' '<<prim[i][1]<<" "<<prim[i][2]<<"\n";
//	}
}
