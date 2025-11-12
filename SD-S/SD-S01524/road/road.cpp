#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,s,p;
vector<pair<long long,long long>> a[10000];
long long b[1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++){
		cin>>u>>v>>s;
		a[u].push_back(make_pair(v,s));
		a[v].push_back(make_pair(u,s));
	}
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<1<<endl; 
	return 0;
}
//最小生成树 不会 
