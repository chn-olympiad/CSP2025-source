#include <bits/stdc++.h>
using namespace std;
struct 	Node{
	long long v,w;
};
vector <Node> e[100010];
long long n,m,u,v,w,k,ans,a[100010],f[100010];
void bf(){
	queue <long long> q;
	q.push(1);
	f[1]=1;
	while(!q.empty()){
		long long u=q.front();
		//cout<<u<<endl;
		q.pop();
		long long k=0x3f,l=0;
		for(auto i:e[u]){
			long long v=i.v,w=i.w;
			if(w<k&&f[v]==0)k=w,l=v;
		}
		if(l!=0){
			ans+=k;
			f[l]=1;
			q.push(l);
		}		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int w=a[1]+a[j+1]+a[k+1];
				Node t=e[j][k];
				if(t.w==0||t.w>w)e[j].push_back({k,w}),e[k].push_back({j,w});
			}
		}
	}
	bf();
	cout<<ans;
	return 0;
}
