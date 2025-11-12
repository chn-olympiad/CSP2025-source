#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int c[N],city[N],ans,ans1=0,n,m,k;
struct e{
	int to,cost;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		ans = 0;
		for(int j = 1;j <= n;j++){
			cin >> city[i];
			ans += city[i];
			ans1 = max(ans1,ans);
		}
	}
	cout << ans1;
	return 0;
}
	
