#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
ll n,m,k,a,b,c,ans,villagebuilt[15],villagebcost[15],villagercost[15][N],vis[N],dist[N];
struct node{
	ll to,dis;
	bool friend operator <(const node x,const node y){
		return x.dis>y.dis;
	}
}; 
vector<node>vec[N];
void prim(){
	ll cntvillage=0;
	priority_queue<node>q;
	q.push({1,0});
	while(q.size()){
		node u=q.top();
		q.pop();
		vis[u.to]=1;
		ans+=u.dis;
		cntvillage+=1;
		//cout<<u.to<<' '<<u.dis<<" "<<ans<<'\n';
		if(cntvillage==n) return;
		for(auto x:vec[u.to]){
			if(vis[x.to]) continue;
			if(dist[x.to]>x.dis){
				dist[x.to]=x.dis;
				//cout<<u.to<<" "<<x.to<<" "<<dist[x.to]<<":\n";
				q.push({x.to,dist[x.to]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a>>b>>c; 
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	for(ll i=1;i<=k;i++){
		cin>>villagebcost[i];
		ll spo=0;
		for(ll j=1;j<=n;j++){
			cin>>villagercost[i][j];
			if(villagercost[i][j]==0) spo=j;
		}
		for(ll j=1;j<=n;j++){
			if(j==spo) continue;
			vec[spo].push_back({j,villagercost[i][j]});
			vec[j].push_back({spo,villagercost[i][j]});
			//cout<<spo<<' '<<j<<" "<<villagercost[i][j]<<";\n";
		}
	}
	for(ll i=2;i<=n;i++) dist[i]=4e18;
	prim();
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
