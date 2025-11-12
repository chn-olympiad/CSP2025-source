#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
struct node{
	ll x,idx;
}c[N];
ll n,k,a[N],b[N],ans,used=-1,maxn;
bool cmp(node x,node y){
	if(x.x==y.x) return x.idx<y.idx;
	return x.x<y.x;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
		c[i].x=b[i],c[i].idx=i;
	}
	sort(c,c+1+n,cmp);
	for(ll i=1;i<=n;i++){
    	if(a[i]==k){
			used=i;
			ans++;
			continue;
		}
		ll t=b[i]^k;
		ll L=0,R=n;
		while(L<R){
			ll mid=(L+R)/2;
			if(c[mid].x>t){
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
//      c[L].idx左边界的前一个 
		while(c[L-1].idx>=used&&c[L-1].x==t&&L>0) L--;
		while(c[L].idx<used&&c[L+1].x==t&&L<n&&c[L].idx<i-1) L++;
		if(c[L].x!=t||c[L].idx>=i||c[L].idx<used) continue;
		else{
			used=i;
			ans++;
		} 
	}
	cout<<ans<<"\n";
	return 0;
}
