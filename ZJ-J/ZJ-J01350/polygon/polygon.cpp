#include <bits/stdc++.h>
using namespace std;
int n,i,a[5010],ma;
const int mod=998244353;
unsigned long long ans;
void sc(int t,int s,int mx,int sum,bool m){
	int i;
	if(s>=3){
		if(t==n+1){
			if(sum>mx*2&&m)
				ans++,ans%=mod;
			return ;
		}
		else 
			if(sum>mx*2&&m)
				ans++,ans%=mod;		
	}
	else if(t==n+1) return ;
	sc(t+1,s,mx,sum,0);
	sc(t+1,s+1,max(mx,a[t]),sum+a[t],1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++) 
		cin>>a[i],ma=max(ma,a[i]);
	sort(a+1,a+n+1);
	if(n==3) cout<<(a[1]+a[2]>a[3]);
	else if(ma==1){
		for (i=n-3;i>=1;i--)
			ans+=n*i,ans%=mod;
		cout<<(ans+1)%mod;
	}
	else sc(1,0,0,0,0),cout<<ans%mod;
}
