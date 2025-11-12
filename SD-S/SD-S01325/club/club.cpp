#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
ll n,T;
pair<ll,ll> a[4][N];
ll f[N][3];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[j][i].first;
			a[j][i].second=j;
		}
	}for(int j=1;j<=3;j++){
		sort(a[j]+1,a[j]+n+1);
	}ll i=1,j=1,k=1;
	for(int i=1;2*i<=n;i++){
		for(int j=1;2*j<=n;j++){
			ll k=n-i-j;
			if(2*k<=n&&k>=0){
				for()
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

