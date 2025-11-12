#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	if(k>0){
		cout<<n*m*k<<endl;
		return 0;
	}
	else cout<<ans;
	return 0;
} 
