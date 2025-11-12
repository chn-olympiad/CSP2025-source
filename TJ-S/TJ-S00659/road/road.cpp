#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=30005;
int n,m,k,c[21],vis[MAXN],cnt,ans;
struct node{
	int x,y,d;
	bool operator <(const node &X) const{
		if(X.d!=d) return X.d < d;
		return X.x>n;
	}
};
priority_queue<node> q;
vector<pair<int,int> > v[MAXN];

void dij(){
	int sz=v[1].size();
	for(int i=0;i<sz;i++){
		int y=v[1][i].first, d=v[1][i].second;
		if(y>n) d+=c[y-n];
		q.push({1,y,d});
	}
	vis[1]=1;
	cnt=1;
	while(cnt<n){
		int x=q.top().x, y=q.top().y, d=q.top().d;
		q.pop();
		if(vis[y]) continue;
		// ¸üÐÂ
		vis[y]=1;
		ans+=d;
		if(y<=n) cnt++;
		// ÐÂ±ß 
		x=y;
		int sz=v[x].size();
		for(int i=0;i<sz;i++){
			y=v[x][i].first, d=v[x][i].second;
			if(y>n) d+=c[y-n];
			q.push({x,y,d});
		}
	}
	cout << ans;
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int x,y,d;
		cin >> x >> y >> d;
		v[x].push_back({y,d});
		v[y].push_back({x,d});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			int d;
			cin >> d;
			v[j].push_back({i+n,d});
			v[i+n].push_back({j,d});
		}
	}
	dij();
//	cout << endl<<ans;
	
	
	return 0;
}
