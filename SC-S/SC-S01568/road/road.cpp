#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		ans+=val;
	}
	if(k!=0){
	}
	cout<<ans;
	return 0;
}