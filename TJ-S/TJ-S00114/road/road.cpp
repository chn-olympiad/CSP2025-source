#include<iostream>
using namespace std;
string t1,t2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m,u,v,w;
	long long ans;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		if(i<n){
			ans += w;
		}
	}
	cout << ans;
	return 0;
}
