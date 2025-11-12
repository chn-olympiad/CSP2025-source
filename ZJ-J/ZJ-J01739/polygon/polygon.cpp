#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],maxn=0,mpc;
ll ans=0;
void fk(int ui,ll anser,int oi){
	if(ui>oi){
		return;
	}
	for(int k=ui;k<oi;k++){
		anser+=a[k];
		if(anser>a[oi]){
			ans++;
			if(ans>998244353){
				ans=ans%998244353;
			}
		}
		fk(k+1,anser,oi);
		anser-=a[k];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			mpc++;
		}
		maxn=max(a[i],maxn);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(mpc==n){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				ans=ans+(n-i-j+2);
				ans=ans%998244353;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){			    
	    fk(1,0,i);
	}
	cout<<ans;
	return 0;
}
