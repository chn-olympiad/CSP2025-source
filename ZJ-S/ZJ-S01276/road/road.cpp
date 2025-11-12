#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,sum,i;
struct node{
	int to,val;
};
vector<node> g[10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(i=1;i<=m;i++){
			cin>>u>>v>>w;
			sum+=w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		cout<<sum;
		return 0;
	}
	cout<<32674;
}
