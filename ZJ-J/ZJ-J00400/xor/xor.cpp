#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=500100;
ll n,k,a[N],b[N],g,ans;
pll sg[N];
inline bool cmp(pll& x,pll& y){
	return x.second<y.second||(x.second==y.second&&x.first>y.first);
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[j]^b[i-1])==k){
				g++;
				sg[g].first=i;
				sg[g].second=j;
//				cout<<sg[g].first<<' '<<sg[g].second<<endl;
			}
	sort(sg+1,sg+g+1,cmp);
	ll nowR=0;
	for(int i=1;i<=g;i++){
		if(sg[i].first>nowR){
			nowR=sg[i].second;
			ans++;
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}