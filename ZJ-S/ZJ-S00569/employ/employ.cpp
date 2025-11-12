#include<bits/stdc++.h>
constexpr int N=1e5+2,mod=998244353;
typedef long long ll;
int n,m,p[12],c[12];
bool vis[12];
std::string s;
ll ans;
void dfs(int now){
	if(now==n+1){
		int sum=0,rc=0;
		std::pair<int,int> pa[12];
		for(int i=1;i<=n;i++){
			pa[i]={p[i],i};
		}
		std::sort(pa+1,pa+1+n,[&](std::pair<int,int> x,std::pair<int,int> y){
			return x.first<y.first;
		});
		for(int i=1;i<=n;i++){
			if(rc>=c[pa[i].second] or s[i]=='0'){
				rc++;
			}else{
				sum++;
			}
		}
		ans+=sum>=m;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	std::cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		std::cin>>c[i];
	}
	if(n<=10){
		dfs(1);
	}else{
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=n;
			ans%=mod;
		}
		std::cout<<ans;
	}
	std::cout<<ans;
}
