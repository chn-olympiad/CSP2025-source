#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		ans+=z;
	}
	cout<<ans<<endl;
	return 0;
} 
