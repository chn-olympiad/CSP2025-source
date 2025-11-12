#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<pair<long long,long long> > nex;
}a[10014];
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u].nex.push_back(make_pair(w,v));
		a[v].nex.push_back(make_pair(w,u));
	}
	for(int i=m+1;i<=m+k;i++){
		long long x;cin>>x;
		for(long long j=1;j<=m;j++){
			cin>>x;
			a[i].nex.push_back(make_pair(x,j));
			a[j].nex.push_back(make_pair(x,i));
		}
	}
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
	q.push(make_pair(0,1));
	long long vis[10015]={0},ans=0;
	while(!q.empty()){
		long long w=q.top().first,x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		ans+=w;
		vis[x]=1;
		for(int i=0;i<a[x].nex.size();i++){
			q.push(a[x].nex[i]);
		}
	}
	cout<<ans;
	return 0;
}
