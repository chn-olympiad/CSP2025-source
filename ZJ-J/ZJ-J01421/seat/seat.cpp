#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=1e2+10,M=1e2+10,MOD=1e9+7;
ll n,m,k,a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m);
	ll num=n*m-(lower_bound(a+1,a+1+n*m,k)-a-1);
	ll ansn,ansm=(num+n-1)/n;
	if(ansm%2==1){
		if(num%n==0) ansn=n;
		else ansn=num%n;
	}else{
		if(num%n==0) ansn=1ll;
		else ansn=n-num%n+1;
	}
	cout<<ansm<<" "<<ansn;
}
int main(){
	IOS;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
