#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
long long ksm(int x,int k){
	if(k==0) return 1;
	if(k==1) return x;
	int t=k/2;
	long long tmp=ksm(x,t);
	if(k%2==1) return tmp%mod*tmp%mod*x%mod;
	else return tmp%mod*tmp%mod;
}
void dfs(int st,int mx,int sum,int tk){
	if(st==n){
		if(tk<3) return ;
		if(mx*2<sum) ans++;
		ans%=mod;
		return ;
	}
	dfs(st+1,max(mx,a[st+1]),sum+a[st+1],tk+1);
	dfs(st+1,mx,sum,tk);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=20){
		dfs(0,0,0,0);
		cout<<ans<<endl;
	}else{
		long long s=ksm(2,n);
		cout<<((s-1-n-(n-1)*n/2)%mod+mod)%mod<<endl;
	}
	return 0;
}
