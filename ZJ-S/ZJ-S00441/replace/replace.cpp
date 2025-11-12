#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1001000;
string fi[N],rep[N],from,to,rr;
ll n,q,ans;
inline void solve(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>fi[i]>>rep[i];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>from>>to;
		if(from.size()!=to.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			rr=from;
			ll pf=from.find(fi[j]),pt=to.find(rep[j]);
			if(pf!=pt) continue;
			if(pf<0||pt<0) continue;
			for(int k=pf,k0=0;k<=pf+rep[j].size()-1;k++,k0++) rr[k]=rep[j][k0];
//			cout<<pf<<' '<<pt<<endl;
//			cout<<fi[j]<<' '<<rep[j]<<endl;
//			cout<<from<<' '<<rr<<' '<<to<<endl;
			if(rr==to) ans++;
		}cout<<ans<<endl;
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}

