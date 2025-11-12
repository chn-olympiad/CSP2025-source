#include<bits/stdc++.h>
using namespace std;

const int N=10000;
int g[N][N];

int main(){
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	long long ans=0;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	int a;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a;
		}
	}
	cout<<ans;
	return 0;
}