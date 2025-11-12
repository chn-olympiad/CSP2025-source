#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef array<ll,3> ar; 
const int N=1e5+5;
int n,m,k,c[15],v[15];
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
vector<ar> g;
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<N;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g.push_back({z,x,y});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			g.push_back({x+c[i],i+n,j});
		}
	}
	sort(g.begin(),g.end());
	int gs=g.size();
	for(int i=0;i<gs;i++){
		int fu=find(g[i][1]),fv=find(g[i][2]);
		if(fu!=fv){
			ans+=g[i][0];
			if(g[i][1]>n&&v[g[i][1]-n]==0){
				v[g[i][1]-n]=1;
			} 
			if(g[i][1]>n&&v[g[i][1]-n]==1){
				ans-=c[g[i][1]-n];
			}
			if(g[i][2]>n&&v[g[i][2]-n]==0){
				v[g[i][2]-n]=1;
			} 
			if(g[i][2]>n&&v[g[i][2]-n]==1){
				ans-=c[g[i][2]-n];
			}
			f[fu]=fv;
		}
	}
	cout<<ans;
	return 0;
}