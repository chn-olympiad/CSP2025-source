//»áÓ®µÄ¡£ 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,_;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[i]==R){
		_=n*m-i+1;
		break;
	} int c=_/n+((_%n)?1:0),x=((_%n)?(_%n):n);
	cout<<c<<" "<<((c&1)?x:(n-x+1))<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
