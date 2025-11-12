#include<bits/stdc++.h>
constexpr int N=1e5+2;
typedef long long ll;
int T,n,ans;
std::array<int,3> a[N],t;
bool cmp(std::array<int,3> x,std::array<int,3> y){
	return std::max({x[0],x[1],x[2]})>std::max({y[0],y[1],y[2]});
}
void dfs(int now,std::array<int,3> cnt,int sum){
	if(now==n+1){
		ans=std::max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]+1<=n/2){
			std::array<int,3> t=cnt;
			t[i]++;
			dfs(now+1,t,sum+a[now][i]);
		}
	}
}
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>T;
	while(T--){
		ans=0;
		std::cin>>n;
		for(int i=1;i<=n;i++){
			std::cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n<=10){
			dfs(1,t,0);
		}else{
			std::sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=std::max({a[i][0],a[i][1],a[i][2]});
			}
		}
		std::cout<<ans<<'\n';
	}
}
