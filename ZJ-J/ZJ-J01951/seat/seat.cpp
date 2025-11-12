//AC 100pts
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[105],t;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			int k=(i+n-1)/n,l;
			if(k%2) l=(i-1)%n+1;
			else l=n-(i-1)%n;
			cout<<k<<' '<<l<<'\n';
			return;
		}
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
