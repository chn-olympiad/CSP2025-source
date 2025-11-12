#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,val;
};
int n,m,k,c[11],aans=INT_MAX;
vector<edge>aa;
vector<int>a[200005];
vector<edge>q;
vector<bool>v;
int f[200005];
int d[11][20005];
int findf(int val){
	if(f[val]==val)return val;
	return f[val]=findf(f[val]);
}
int query(int l,int r){
	return findf(l)==findf(r);
}
int merge(int l,int r){
	f[findf(l)]=findf(f[r]);
}
bool cmp(edge l,edge r){
	return l.val<r.val;
}
void dfs(){
//	cout<<v.size()<<'\n';
	if(v.size()-1<k){
		v.push_back(0);
		dfs();
		v.erase(v.end()-1);
		v.push_back(1);
		dfs();
		v.erase(v.end()-1);
		return;
	}
	for(int i=1;i<=n+k+1;i++){
		f[i]=i;
	}
	q=aa;
	int ans=0;
	for(int i=1;i<=k;i++){
		if(v[i]==1){
//			cout<<c[i]<<'\n';
			ans+=c[i];
			for(int j=1;j<=n;j++){
				edge e;
				e.from=n+i;
				e.to=j;
				e.val=d[i][j];
				q.push_back(e);
				swap(e.from,e.to);
				q.push_back(e);
			}
		}
	}
	sort(q.begin(),q.end(),cmp);
	int cnt=0;
	for(int i=0;i<q.size();i++){
		cnt++;
		if(query(q[i].from,q[i].to))continue;
		merge(q[i].from,q[i].to);
		ans+=q[i].val;
//		cout<<q[i].val<<'\n';
		if(cnt==n)break;
	}
	aans=min(aans,ans);
//	cout<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
		edge e;
		e.from=v;e.to=u;e.val=w;
		aa.push_back(e);
		swap(e.from,e.to);
		aa.push_back(e);
	}
	v.push_back(0);
	for(int i=1;i<=k;i++){
		cin>>c[i]; 
		for(int j=1;j<=n;j++)cin>>d[i][j];
	}dfs();
	cout<<aans;
	return 0;
}
