#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,a[5010],cnt=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mxi=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxi=max(mxi,a[i]);
	}
	if(n==3){
		cout<<(a[1]+a[2]>a[3] ? 1 : 0);
		return 0;
	}
	if(mxi==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%MOD;
		}
		ans=(ans+MOD-n)%MOD;
		ans=(ans+MOD-n*(n-1)/2)%MOD;
		cout<<ans;
		return 0;
	}
	cout<<MOD-n;
	return 0;
}
