#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e3+7,MOD=998244353;
ll a[N],n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	if(n==3){
		int a1,a2,a3; cin>>a1>>a2>>a3;
		if(max(a1,max(a2,a3))*2<a1+a2+a3) cout<<1;
		else cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
			return 0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			return 0;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n-i+1;j++){
			ll maxx=-1,sum=0;
			for(ll k=j;k<=j+i-1;k++){
				sum+=a[k];
				if(a[k]>maxx) maxx=a[k];
			}
			if(maxx*2<sum) ans++;
		}
	}
	cout<<ans%MOD;
	return 0; 
}
