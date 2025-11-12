#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5e2+5;	
ll n,m;
struct Stu{
	ll x;
	ll id;
}a[N];
ll mp[N][N];
ll d(ll i,ll j){
	return (i-1)*m+j;
}
bool cmp(Stu p,Stu q){
	return p.x>q.x;
}
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin>>a[d(i,j)].x;
		}
	}
	a[1].id=1;
	sort(a+1,a+n*m+1,cmp);
	ll now;
	ll ttt=n*m;
	for(ll i=1;i<=ttt;i++){
		if(a[i].id==1){
			now=i;
			break;
		}
	}
	ll f=0;
	for(ll i=1;i<=m;i++){
		if(i&1){
			for(ll j=1;j<=n;j++){
				++f;
				mp[i][j]=f;
			}
		}
		else{
			for(ll j=n;j>=1;j--){
				++f;
				mp[i][j]=f;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(mp[i][j]==now){
				cout<<i<<' '<<j<<'\n';
				return;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}
