#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define inf INT_MAX
#define fi first
#define se second
const int maxn=1e4+20,maxm=1e6+5;
using pii=pair<int,int>;

int n,m,k,ans=inf,now,a[maxn],cnt;



struct node{
	vector<pii>e;
	int d=inf,last_dis=inf,last_d=inf;
}v[maxn];

priority_queue<pii,vector<pii>,greater<pii>> pq1;

void clean(int cnt){
	for(int i=1;i<=cnt+2;i++){
		v[i].d=v[i].last_d=v[i].last_dis=inf;
	}
	now=0;
}

void dj(){
	if(now>ans) return;
	pq1.push({0,1});
	while(pq1.size()){
		auto p=pq1.top();
		pq1.pop();
		if(v[p.se].d==inf){
			v[p.se].d=p.fi;
			if(v[p.se].last_dis!=inf) now+=v[p.se].last_dis;
			for(auto x:v[p.se].e){
				if(v[x.se].d==inf){
				if(x.fi+p.fi<v[x.se].last_d||v[x.se].last_dis>x.fi){
					v[x.se].last_d=x.fi+p.fi;
					v[x.se].last_dis=x.fi;
				}
				pq1.push({x.fi+p.fi,x.se});					
				}
			}
		}
	}
	ans=min(now,ans);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	cnt=n;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].e.push_back({z,y});
		v[y].e.push_back({z,x});
	}
	dj();
	for(int i=1;i<=k;i++){
		clean(cnt);
		int c;
		cin>>c;
		now=0;
		now+=c;
		cnt++;
		for(int j=1;j<=n;j++){
			cin>>a[i];
			v[cnt].e.push_back({a[i],j});
			v[j].e.push_back({a[i],cnt});
			
		}
		dj();
	}
	cout<<ans;
	return 0;
}