#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
struct nn{
	int to,val,id;
};
vector<nn> a[N];
int c[20],p[20][N],d[N],x[N],y[N],z[N];
queue<int> q;
int ans=0;
vector<int> h;
bool vis[N],viss[1000010];
bool cmp(int xx,int yy){
	return z[xx]<z[yy];
}
void topu(){
	ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			q.push(i);
			vis[i]=1;
		}
	}
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].to;
			if(vis[v]) continue;
			ans+=a[u][i].val;
			cnt++;
			viss[a[u][i].id]=1;
			d[v]--;
			if(d[v]==1){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!viss[i]){
			h.push_back(i);
		}
	}
	sort(h.begin(),h.end(),cmp);
	int tot=0;
	for(int i=0;i<h.size();i++){
		int ii=h[i];
		if(!vis[x[ii]]||!vis[y[ii]]){
			vis[x[ii]]=vis[y[ii]]=1;
			ans+=z[ii];
			tot++;
		}
		if(tot==n-cnt-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		x[i]=u;
		y[i]=v;
		z[i]=w;
		d[u]++;
		d[v]++;
		a[u].push_back({v,w,i});
		a[v].push_back({u,w,i});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			if(p[i][j]!=0) f=1;
		}
	}
	if(k==0) f=1;
	if(f==0){
		cout<<0;
		return 0;
	}
	if(k==0){
		topu();
		cout<<ans;
		return 0;
	}
	int mn=1e9;
	for(int i=1;i<=k;i++){
		int sum=c[i];
		for(int j=1;j<=n;j++){
			if(i!=j) sum+=p[i][j];
		}	
		mn=min(sum,mn);
	}
	cout<<mn;
	return 0;
}

