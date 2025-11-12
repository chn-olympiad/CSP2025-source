#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k;
ll a[N];
ll s[N];
bool check(){
	for(int i=1;i<=n;i++) if(a[i]>1) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll flag=0;
	if(check()) flag=1;
	if(flag==1){
		if(k>1){
			cout<<0;
			return 0;
		}
		ll cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++) if(a[i]==0) cnt++;
		}else{
			for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(n<=10000){
		for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		ll last=0;
		ll sum=0;
		for(ll r=1;r<=n;r++){
			for(ll l=r;l>last;l--){
				if((s[r]^s[l-1])==k){
					sum++;
					last=r;
					break;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	cout<<0;
	return 0;
}
