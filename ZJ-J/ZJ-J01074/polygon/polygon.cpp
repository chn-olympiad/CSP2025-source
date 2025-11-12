#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],ans=0;
void dfs(long long x,long long sum,long long maxV,long long cnt){
	if(x>n){
		if(sum>maxV*2&&cnt>=3)ans++;
		ans%=mod;
		return ;
	}
	dfs(x+1,sum,maxV,cnt);
	dfs(x+1,sum+a[x],a[x],cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		long long k=(n+1)*n/2+1;
		ans=(ans-k+mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
