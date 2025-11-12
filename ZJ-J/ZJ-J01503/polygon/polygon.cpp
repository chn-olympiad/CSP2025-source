#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,ans;
int l[N],a[N],f[N];
int sol(int x){
	int base=2,b=x,as=1;
	while(b){
		if(b&1){
			as*=base;
			as%=mod;
		}
		base*=base;
		b>>=1;
	}
	return as%mod;
}
void dfs(int x,int ma,int sum,int step){
	if(step>=3&&sum+a[x]<=ma){
		return;
	}
	if(step>=3&&sum>ma){
		ans+=f[x];ans%=mod;
		return ;
	}
	if(x==0)return;
	dfs(x-1,ma,sum+l[x],step+1);
	dfs(x-1,ma,sum,step);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	sort(l+1,l+n+1);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+l[i];
		f[i]=sol(i);
	}
	f[0]=1;
	for(int i=n;i>=1;i--){
		dfs(i-1,l[i]*2,l[i],1);
	}
	cout<<ans;
	return 0;
}
//1 2 4 5
//1 2 3 5
//2 4 5