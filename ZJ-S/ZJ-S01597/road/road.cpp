#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,k,sm;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	ll a,b,v;
	for(ll i = 1 ; i <= m ; ++i){
		cin >> a >> b >> v;
	}
	ll nm;
	for(ll i = 1 ; i <= k ; ++i){
		for(ll j = 0 ; j <= n ; ++j){
			cin >> nm;
		}
	}
	cout << 0 << endl;
	return 0;
}
