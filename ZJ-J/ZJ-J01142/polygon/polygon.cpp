#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int a[5050];
int ans=0;
void dfs(int step,int ls,int cnt,int sum,int mx) {
	if(cnt>=3&&sum>mx*2) {
		ans+=1;
		ans%=mod;
		//std::cout<<cnt<<" "<<sum<<'\n';
	}
	if(step==ls) {
		return;
	}
	dfs(step+1,ls,cnt,sum,mx);
	dfs(step+1,ls,cnt+1,sum+a[step+1],mx);
	return;
}
signed main() {
	std::ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	std::cin>>n;
	bool f=false;
	int cnt0,cnt1;
	for(int i=0; i<n; i++) {
		std::cin>>a[i];
		if(a[i]>1) {
			f=true;
		}
		if(a[i]==0) {
			cnt0+=1;
		}
		if(a[i]==1) {
			cnt1+=1;
		}
	}
	sort(a,a+n);
	if(n<=3) {
		if(a[2]>a[0]+a[1]) {
			std::cout<<1;
		} else {
			std::cout<<0;
		}
		return 0;
	}
	if(!f) {
		ans=0;
		for(int i=3; i<=n; i++) {
			int sum=1;
			for(int j=n-i+1; j<=n; j++) {
				//std::cout<<j<<"*\n";
				sum*=j;
				sum%=mod;
			}
			for(int j=1; j<=i; j++) {
				//std::cout<<j<<" ";
				sum/=j;
			}
			//std::cout<<"\n";
			ans+=sum;
		}
		if(cnt0>=3) {
			for(int i=3; i<=cnt0; i++) {
				int ss=1;
				for(int j=cnt0-i+1; j<=cnt0; j++) {
					//std::cout<<j<<"*\n";
					ss*=j;
					ss%=mod;
				}
				for(int j=1; j<=i; j++) {
					//std::cout<<j<<" ";
					ss/=j;
				}
				//std::cout<<"\n";
				ans-=ss;
			}
		}
		std::cout<<ans;
		return 0;
	}
	for(int i=3; i<=n; i++) {
		dfs(0,i,1,a[i],a[i]);
	}
	std::cout<<ans;
	return 0;
}
