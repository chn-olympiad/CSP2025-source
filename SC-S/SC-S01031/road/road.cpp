#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,ans=0;
	cin >> n >> m >> k;
	while(m--){
		cin >> u >> v >> w;
		ans += w;
	}
	cout << ans;
	return 0;
}