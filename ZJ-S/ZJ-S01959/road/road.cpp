#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int c[15];
int a[15][100500];
int f[10005];
int vis[15];

//vector< pair  <int , int > > e[10005];
struct w{
	int u,v,w;
};
bool operator < (w a,w b){
	return a.w>b.w;
}
int fnd(int x){ 
	if(x==f[x]) return x;
	return f[x]=fnd(f[x]);
}
vector<w>e;
void solve(){
	priority_queue<w>q;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<n+1;i++) f[i]=i;
	while(!q.empty()){
		int u=fnd(q.top().u),v=fnd(q.top().v),w=q.top().w;
		q.pop();
		if(u==v) continue;
		ans+=w;
		f[u]=v;
	}
	cout<<ans;
	return ;
}

void check(){
	for(int i=1;i<n+k+1;i++) f[i]=i;
	long long sum=0;
	priority_queue<w>q;
	for(int i=1;i<k+1;i++){
		if(!vis[i]) continue;
		sum+=c[i];
		for(int u=1;u<n+1;u++){
			q.push({u,i+n,a[i][u]});
		}
	}
	for(int i=0;i<e.size();i++) q.push(e[i]);
	while(!q.empty()){
	//	cout<<"*";
		w x=q.top();
		q.pop();
		int u=fnd(x.u),v=fnd(x.v),w=x.w;
		if(u==v) continue;
		sum+=w;
		f[u]=v;
	}
	ans=min(ans,sum);
}
void dfs(int now){
	if(now==n+1){
		check();
		return ;
	}
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
}
priority_queue<w>q;
void solve3(){
	ans=0;
	for(int i=0;i<e.size();i++) q.push(e[i]);
	for(int i=1;i<k+1;i++){
		for(int j=1;j<n+1;j++){
			q.push({i+n,j,a[i][j]});
		}
	}
	for(int i=1;i<n+k+1;i++) f[i]=i;
	while(!q.empty()){
		int u=fnd(q.top().u),v=fnd(q.top().v),w=q.top().w;
		q.pop();
		if(u==v) continue;
	//	cout<<u<<' '<<v<<' '<<w<<endl;
		f[u]=v;
		ans+=w;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve();
		return 0;
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	long long xx=0,zz=0;
	for(int i=1;i<k+1;i++){
		cin>>c[i];
		for(int j=1;j<n+1;j++){
			cin>>a[i][j];
			zz+=a[i][j];
		}
		xx+=c[i];
	}
	if(k<=5){
		ans=1e18;
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(xx==0 && zz==0){
		cout<<0;
		return 0;
	}
	if(xx=0){
		solve3();
		return 0;
	}
	ans=1e18;
	dfs(1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
