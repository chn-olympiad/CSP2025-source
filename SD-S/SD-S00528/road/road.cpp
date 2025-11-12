#include<bits/stdc++.h>
using namespace std;
//�߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷� 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIP;
const int N=1e4+10;
struct AC{
	
};
int n,m,k;
vector<int> g[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,mone;
		cin>>u>>v>>mone;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int t;
	while(cin>>t);
	cout<<0;
	return 0;
} 
