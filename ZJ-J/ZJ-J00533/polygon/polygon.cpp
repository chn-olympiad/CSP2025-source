#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,a[5001],t;
int p2(int x){
	int base=2,ans=1;
	while(x){
		if(x%2)ans=ans*base%mod;
		base=base*base%mod;
		x>>=1;
	}
	return ans;
}
int dfs(int d,int now,int l){
	if(now>a[t]){
		if(l>=2)return p2(t-d-1);
		if(l==1)return p2(t-d-1)-1;
		if(l==0)return p2(t-d-1)-t+d;
	}
	if(d==t-1)return 0;
	return dfs(d+1,now,l)+dfs(d+1,now+a[d+1],l+1);
}
void A(){
	int ans=0;
	for(t=3;t<=n;t++){
		ans=(ans+dfs(0,0,0))%mod;
	}
	cout<<ans<<endl;
}
void B(){
	cout<<(p2(n)-n*(n-1)/2-n-1+mod)%mod<<endl;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flg=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flg=0;
	}
	sort(a+1,a+n+1); 
	if(n<=20)A();
	else if(flg)B();
	return 0;
}
//11.1 10:42
//code by K.S.
//want 64pts.
