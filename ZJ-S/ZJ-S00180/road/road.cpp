#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w", stdout);
	int n,m,t;
	cin >> n >> m>> t;
	int a, b, c, ans = 0;
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> c;
		ans+=c;
	}	
	cout << ans;
	return 0;
}
