#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
vector<int > road[maxn];
vector<int > costroad[maxn];
int a[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[u].push_back(v);
		road[v].push_back(u);
		ans+=w;
	
		
	}	
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
	
		
	}
	cout<<ans;	
	return 0;
}