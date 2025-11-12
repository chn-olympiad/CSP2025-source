#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
struct node {
	string s1,s2;
} a[N];
ll cmp(node x,node y) {
	x.s1.size()<y.s2.size();
}
ll findd(string xn,string iy){
	for(ll i=0;i<xn.size();i++){
		ll flag=1;
		for(ll j=0;j<iy.size();j++){
			if(iy[i]!=xn[i]){
				flag=0;
				break;
			}
		}
		if(flag) return i;
	}
	return INT_MAX;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	for(ll i=1; i<=n; i++) {
		cin>>a[i].s1>>a[i].s2;
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1; i<=q; i++) {
		string q1,q2;
		cin>>q1>>q2;
		ll ans=0;
		for(ll j=1; a[j].s1.size()<=q1.size()&&j<=n; j++) {
			ll findi=findd(q1,a[j].s1);
			//cout<<a[j].s1<<":";
			if(findi<q1.size()) {
				//cout<<"he";
				ll flag=1;
				string ts=q1;
				for(ll k=0;k<a[j].s1.size(); k++) {
					ts[findi+k]=a[j].s2[k];
				}
				//cout<<ts;
				findi=findd(q1,a[i].s1);
				ans+=(ts==q2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

