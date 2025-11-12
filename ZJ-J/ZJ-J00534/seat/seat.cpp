#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ll x=a[1];
	sort(a+1,a+1+n*m,cmp);
	ll pos=-1;
	for(int i=1;i<=n*m;i++) if(a[i]==x) pos=i;
	ll y;
	if(pos%n==0) y=pos/n;
	else y=pos/n+1;
	cout<<y<<" ";
	if(y%2==0){
		if(pos%n==0) cout<<1;
		else cout<<n-pos%n+1;
	}else{
		if(pos%n==0) cout<<n;
		else cout<<pos%n;
	}
	return 0;
}
