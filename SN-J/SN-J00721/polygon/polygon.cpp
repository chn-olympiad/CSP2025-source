//SN-J00721  Õı •ø≠ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	if(n<=20){
		for(int i=0;i<n;i++)cin>>a[i];
		int N=(1<<n)-1,ans=0;
		for(int i=0;i<=N;i++){
			int maxx=0,s=0;
			for(int k=0;k<n;k++){
				if((1<<k)&i){
					maxx=max(maxx,a[k]);
					s+=a[k];
				}
			}
			if(s>2*maxx)ans++,ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);
	if(maxx==1){
		int ans=0;
		for(int len=3;len<=n;len++){
			ans=(ans+(n-len+1))%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

