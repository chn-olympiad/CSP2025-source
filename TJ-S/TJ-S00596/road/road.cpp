#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,v,w,u;
	unsigned long long int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans<<endl;
	return 0;
}
