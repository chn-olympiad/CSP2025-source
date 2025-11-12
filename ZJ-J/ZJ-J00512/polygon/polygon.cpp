#include<bits/stdc++.h>
constexpr int N=22,ln=0x0d000721,mod=998244353;
long long n,a[N],ans;
void dfs(int now,int s,int x,int cnt){
	if(now==n+1){
		if(cnt>=3 and s>x*2){
			ans++;
		}
		return;
	}
	dfs(now+1,s,x,cnt),dfs(now+1,s+a[now],std::max(a[now],(long long)x),cnt+1);
}
long long c(int n,int m){
	__int128 s=1;
	for(int i=n;i>n-m;i--){
		s*=i;
	}
	for(int i=m;i>1;i--){
		s/=i;
	}
	return (long long)s;
}
int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	if(n>500){
		for(int i=3;i<=n;i++){
			ans+=c(n,i)%mod;
			ans%=mod;
		}
		std::cout<<ans;
		return 0;
	}
	dfs(1,0,-1,0);
	std::cout<<ans;
}
//uid:942578
