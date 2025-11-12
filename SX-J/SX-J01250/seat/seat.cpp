#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll h = 1, l = 1;
ll a[110];
ll cmp(ll x,ll y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	ll s = n * m;
	for(ll i=1;i<=s;i++) cin>>a[i];
	ll p=a[1];
	sort(a+1,a+s+1,cmp);
	if(s%2==0){
		if(a[1]==p){
			cout<<1<<" "<<1;
		}
		else{
			cout<<" "<<m<<1;
		}
	}
	else{
		if(a[1]==p){
			cout<<1<<" "<<1;
		}
		else{
			cout<<m<<" "<<n;
		}
	}
	return 0;
}
