#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[1005], sum=1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a[1];
	for(ll i=2; i<=n*m; i++){
		cin >> a[i];
		if(a[i]>a[1])sum++;
	}
//	cout<<sum<<'\n';
	ll l=(sum+n-1)/n, h=(sum-1)%n+1;
	if(l%2)cout<<l<<' '<<h;
	else cout<<l<<' '<<n-h+1;
	return 0;
}

