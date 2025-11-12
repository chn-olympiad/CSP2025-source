#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long u,w;
	friend bool operator<(Node a,Node b){
		return a.w>b.w;
	}
};
bool cmp(Node a,Node b){
	return a.w<b.w;
}
vector<long long> zdl(long long st,long long n,vector<vector<Node> >& e){
	vector<long long> dis(n);
	vector<bool> vis(n,0);
	vector<long long> inq(n,(long long)(1e18));
	priority_queue<Node> q;
	q.push((Node){st,0});
	while(q.size()){
		Node qq=q.top();
		q.pop();
		if(vis[qq.u]==1) continue;
		dis[qq.u]=qq.w;
		vis[qq.u]=1;
		for(Node v:e[qq.u]){
			if(v.u>=n) continue;
			if(inq[v.u]>v.w){
				q.push(v);
				inq[v.u]=v.w;
			}
		}
	}
	return dis;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	vector<vector<Node> > e(n+k);
	for(long long i=0;i<m;++i){
		long long u,v,w;
		cin>>u>>v>>w;
		--u;--v;
		e[u].push_back((Node){v,w});
		e[v].push_back((Node){u,w});
	}
	vector<long long> c(k);
	for(long long i=0;i<k;++i){
		cin>>c[i];
		c[i]+=i>0?c[i-1]:0;
		for(long long j=0;j<n;++j){
			long long w;
			cin>>w;
			e[j].push_back((Node){i+n,w});
			e[i+n].push_back((Node){j,w});
		}
	}
	for(long long i=0;i<n+k;++i){
		sort(e[i].begin(),e[i].end(),cmp);
	}
	long long out=0;
	vector<long long> dis=zdl(0,n,e);
	for(long long i=0;i<n;++i){
		out+=dis[i];
	}
	for(long long j=0;j<k;++j){
		long long ans=c[j];
		vector<long long> dis=zdl(0,n+j+1,e);
		for(long long i=0;i<n+j+1;++i){
			ans+=dis[i];
		}
		out=min(out,ans);
	}
	cout<<out<<endl;
	return 0;
}
