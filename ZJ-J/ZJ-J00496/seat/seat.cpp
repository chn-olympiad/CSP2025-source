#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<pll> velp;
typedef vector<vel> vevel;
bool cmp(ll x,ll y){
	return x>y;
}
void slv(){
	ll n,m;
	cin>>n>>m;
	vel v(n*m+3);
	for(int i=1;i<=n*m;i++){
		cin>>v[i];
	}
	ll tmp=v[1];
	sort(v.begin()+1,v.begin()+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(v[i]==tmp){
			ll ansm=i/n+(i%n!=0);
			ll ansn;
			if(ansm%2==1){
				ansn=i%n;
				if(ansn==0){
					ansn=n;
				}
			}else{
				ansn=n-i%n+1;
				if(ansn==n+1){
					ansn=1;
				}
			}
			cout<<ansm<<' '<<ansn;
			return ;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}