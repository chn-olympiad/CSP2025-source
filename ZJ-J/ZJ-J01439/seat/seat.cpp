#include <bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll N = 15,M = 15;
ll n,m,rs,pos,c,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> rs;pos = 1;
	for (ll i = 2;i <= n*m;i++){
		ll a;cin >> a;
		if (a > rs) pos++; 
	}
	if (pos%n == 0){
		c = pos/n;r = (c&1) ? n : 1;
	}else{
		c = pos/n+1;r = (c&1) ? pos%n : (n-pos%n+1);
	}
	cout << c << ' ' << r << '\n';
	return 0;
}
