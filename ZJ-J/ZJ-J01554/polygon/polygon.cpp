#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,h[5005],ans;
long long ksm(long long a,long long b,long long mod=998244353){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;b>>=1;
	}
	return res;
}
void dfs(int k,int choose,int sum,int bian){
	if(k>bian){
		if(sum>a[bian+1]&&choose>=2) ans=(ans+1)%998244353;
		return;
	}
	dfs(k+1,choose+1,sum+a[k],bian);
	dfs(k+1,choose,sum,bian);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		cout<<(ksm(2,n)-1-n-n*(n-1)/2+998244353)%998244353;
	}else{
		for(int i=n;i>=1;i--){
			dfs(1,0,0,i-1);
		}
		cout<<ans;
	}
	return 0;
}
