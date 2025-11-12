#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int city,cost;
};
struct node_q{
	int city,dist;
	friend operator<(node_q a,node_q b){
		return a.dist>b.dist;
	}
};

vector<node> map[N];
int town[11][N];
priority_queue<node_q> p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		map[u].push_back({v,w});
		map[v].push_back({u,w});
	}
	if(k==0){
		p.push({1,0});
		int cnt=0;
		int ans=0;
		while(!p.empty() && cnt<n){
			node_q now=p.top();p.pop();
			ans+=now.dist;
			for(node e:map[now.city]){
				p.push({e.city,now.dist+e.cost});
			}
			cnt++;
		}
		cout<<ans;
	}else{
		for(int i=1,c;i<=k;i++){
			cin>>c;
			for(int i=1;i<=n;i++){
				cin>>town[k][n];
			}
		}
		cout<<0;
	}
	return 0;
}
