#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,k,ans;
struct node{
	int v,w;
};
vector<node>ve[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
		ans+=w;
	}
	if(k==0){
		cout << ans;
	}
	return 0;
}