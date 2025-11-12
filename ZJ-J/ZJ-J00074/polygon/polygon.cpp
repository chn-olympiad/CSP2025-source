#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,a[5001],ans,ma,g,j,res;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=3){
		if(n<3) cout<<0;
		else{
			if(a[1]+a[2]<=a[3]) cout<<0;
			else cout<<1;
		}
	} 
	else if(n<=20){
		res=0;
		for(i=1;i<(1<<n);i++){
			ma=0;ans=0;g=0;
			for(j=1;j<=n;j++)
				if(i&(1<<(j-1))) g++,ma=max(ma,a[j]),ans+=a[j];
			if(ans>ma*2&&g>=3) res++;
			if(res>mod) res-=mod;
		}
		cout<<res%mod;
	}
	else{
		if(a[n]==1){
			ans=1;
			for(i=1;i<=n;i++) ans=(ans*2)%mod;
			cout<<(ans+mod-n-n*(n-1)/2-1)%mod;
		}
		cout<<0<<" ";
	}
	return 0;
}