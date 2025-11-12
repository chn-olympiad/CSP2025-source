#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int o;
bool flag=0;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int a;
		int c;
		cin>>c;
		ans+=c;
		for(int j=1;j<=n;j++){
			cin>>a;
			ans+=a;
		}
	}
	cout<<ans;
	
	return 0;
} 