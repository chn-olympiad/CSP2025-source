#include<bits/stdc++.h>
using namespace std;
long long n,m,k,vis[5015],c[5015],ans,w[10][5001];
struct nm{
	long long u,v,w;
	bool operator<(const nm &a) const{
		return w>a.w;
	}
};
priority_queue<nm> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(long long i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>w[i-n][j];
			q.push({i,j,w[i-n][j]+c[i]});
		}
	}
	while(q.size()){
		nm fw=q.top();q.pop();
		if(vis[fw.u]&&vis[fw.v]||(fw.u>n&&!vis[fw.u])) continue; 
		ans+=fw.w;
		if(fw.u>n&&!vis[fw.u]){
			for(long long j=1;j<=n;j++){
				q.push({fw.u,j,w[fw.u-n][j]-c[fw.u]});
			}
		}
		vis[fw.u]=1,vis[fw.v]=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
