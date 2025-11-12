#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500001];
struct node{
	ll l,r;
}b[500001];
bool cmp(node q,node p){
	if(q.r==p.r)return q.l>p.l;
	return q.r<p.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	bool f=1;
	ll sum1=0,sum0=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!='1'&&a[i]!='0'){
			f=0;
		}
		if(a[i]=='1'){
			sum1++;
		}
		if(a[i]=='0'){
			sum0++;
		}
	}
	if(f&&k==1){
		cout<<sum1;
		return 0;
	}
	else if(f&&k==0){
		ll ans=0;
		for(ll i=1;i<=n;){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i+=2;
			}
			else{
				i++;
			}
		}
		cout<<sum0+ans;
		return 0;
	}
	ll ans=1,shu=0;
	for(ll i=1;i<=n;i++){
		ll num=0;
		for(ll j=i;j<=n;j++){
			num^=a[j];
			if(num==k){
				b[++shu]={i,j};
			}
		}
	}
	sort(b+1,b+shu+1,cmp);
	ll end=b[1].r;
	for(ll i=2;i<=shu;i++){
		if(b[i].l>end){
			ans++;
			end=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}

