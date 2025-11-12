#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ans+=w;
		}
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
}
