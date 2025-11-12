#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,s,ma,ans,a[5010];
int c(int x,int y){
	int i,s=1;
	for(i=x-y+1;i<=x;i++) s=s*i,s%=mod;
	for(i=1;i<=y;i++) s=s/i,s%=mod;
	return s;	
}
void sc(int t,int ma,int sum,int gs){
	if(t==n+1){
		if(sum>ma*2&&gs>=3) ans++,ans%=mod;
		return ;
	}
	sc(t+1,max(ma,a[t]),sum+a[t],gs+1);
	sc(t+1,ma,sum,gs);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]);
	if(ma==1){
		for(i=3;i<=n;i++) s+=c(n,i);
		cout<<s;
		return 0;
	}
	sc(1,0,0,0);
	cout<<ans%mod;
}
