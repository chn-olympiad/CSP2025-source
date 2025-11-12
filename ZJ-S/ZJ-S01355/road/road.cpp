#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
struct node{
	int u,v,w;
	bool operator<(node o)const{
		return w<o.w;
	}
}a[N];
int n,m,k,fa[N],cnt,ans,s[12][N],c[12],d[N];
vector<pair<int,int>> g[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void dij(int st){
	memset(d,0x3f,sizeof d);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
	int sum=0;
	d[st]=0;
	q.push({0,st});
	while(!q.empty()){
		auto f=q.top();
		int u=f.second;q.pop();
		if(d[u]!=f.first) continue;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
int32_t main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		a[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		int fx=get(u),fy=get(v);
		if(fx!=fy){
			fa[fx]=fy;
			cnt++;
			ans+=a[i].w;
		}
		if(cnt==n-1) break;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int x=a[1].u,y=a[1].v,st,sum=c[i];
		if(s[i][x]<s[i][y]) st=x;
		else st=y;
		dij(st);
		for(int j=1;j<=n;j++) sum+=min(s[i][j],d[j]);
		ans=min(ans,sum);
	}
	cout<<ans;
}