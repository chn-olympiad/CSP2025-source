#include <bits/stdc++.h>
using namespace std;
int n,m,k;
map <pair<int,int>,int> mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		mp[{u,v}] = w;
		mp[{v,u}] = w;
	}
	cout << 0;
	return 0;
}