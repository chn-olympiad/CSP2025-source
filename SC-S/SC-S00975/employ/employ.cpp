#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Mod=998244353;
ll n,m,a[600],sum,nums;
bool can[600],vis[600];
ll jiec[1000];
void jiechen(ll x,ll y){
	ll sums=1;
	for(int i=y+1;i<=x;i++){
		sums*=i;
	}
	for(int i=1;i<=x-y;i++){
		sums/=i;
	}
	printf("%lld",sums);
	return;
}
void dfs(ll ren,ll x){
	if(n-ren<m) return ;
	if(x==n+1){
		sum++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(ren>=a[i]||can[x]==0){
				dfs(ren+1,x+1);
			}
			else{
				dfs(ren,x+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		char d;
		scanf("%c",&d);
		if(d=='1') can[i]=1;
		else can[i]=0;
		if(can[i]==1) nums++;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(nums==n){
		jiechen(n,m);	
		return 0;
	}
	if(m==1){
		ll u=1;
		for(int i=1;i<=n;i++){
			u=(n*i)%Mod;
		}
		printf("%lld",u);
		return 0;
	}
	dfs(0,1);
	printf("%lld",sum);
	return 0;
}