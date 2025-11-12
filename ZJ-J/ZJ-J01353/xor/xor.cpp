#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],sum[500005];
bool check(ll x){
	ll L=1,cnt=0;
	for(int i=1;i<=n;++i){
		if((sum[i]^sum[L-1])==k){
			cnt++;
			L=i+1;
		}
	}
	if(cnt>=x) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=((l+r)>>1)+1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}