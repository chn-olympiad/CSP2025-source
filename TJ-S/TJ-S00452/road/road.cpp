#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+7;
int n,m,k;
vector<pair<int,int> > u[N];
int c[N];
bool vis[N];
int f[N];
bool ch[N];
priority_queue<pair<int,int> > q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		u[a].push_back({b,c});
		u[b].push_back({a,c});
	}
	for(int i=1;i<=k;++i){
		int cost;
		cin>>cost;
		c[n+i]=cost;
		for(int j=1;j<=n;++j){
			int a;
			cin>>a;
			u[n+i].push_back({j,a});
			u[j].push_back({n+i,a});
		}
	}
	for(int i=1;i<=n+k;++i)f[i]=1e18+7;
	f[n]=0;
	q.push({0,n});
	while(!q.empty()){
		int cur=q.top().second;
		int pre=-q.top().first;
		q.pop();
		if(vis[cur]){
			continue;
		}
		vis[cur]=true;
		for(int i=0;i<u[cur].size();++i){
			int t=u[cur][i].first;
			if(f[t]>pre+u[cur][i].second){
				f[t]=pre+u[cur][i].second;
				ch[cur]=true;
				q.push({-f[t],t});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=f[i];
	}
	for(int i=1;i<=k;++i){
		ans+=(ch[n+i])*c[i];
	}
	cout<<ans;
	return 0;
}
