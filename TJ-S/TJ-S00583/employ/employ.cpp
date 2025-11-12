#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	ll ans = 1;
	for(ll i = 1;i <= n;i++){
		ans = (ans*i)%998244353;
	}
	cout << ans;
	return 0;
}
