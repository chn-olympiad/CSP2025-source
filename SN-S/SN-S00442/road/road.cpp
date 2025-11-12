//汤佳忆  SN-S00442  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	
	return 0;
}

