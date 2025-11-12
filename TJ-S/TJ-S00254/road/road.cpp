#include<bits/stdc++.h>
using namespace std;
int n, m, k, a, ans;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >>k;
	for(int i = 0;i < n;i++){
		cin >> a;
		ans += a;
	}
	cout << ans;
	return 0;
}
