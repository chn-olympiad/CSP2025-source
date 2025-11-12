#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1000010];


int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin >> n >> m >> k;
	int ans=0;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y >> w[i];
		ans+=w[i];
	}
	cout << ans;
	return 0;
}
