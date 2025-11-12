#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5025;
const ll M=998244353;
ll n,a[N],dp[N][N],ans=0,maxn=0;
bool pd=0;
void dfs(ll t,ll num,ll sum,ll maxn){
	if(t==n+1){
		if(sum>=3&&num>maxn*2){
			ans++;
			ans%=M;
		}
		return;
	}
	if(n-t+1<3-sum)return;
	dfs(t+1,num+a[t],sum+1,a[t]);
	dfs(t+1,num,sum,maxn);
	return;
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pd=1;
		maxn=max(maxn,a[i]);
	}
	if(pd==0){
		ll numm=n*(n-1)*(n-2)/6;
		numm%=M;
		ans=numm;
		for(int i=4;i<=n;i++){
			numm*=(n-i+1);
			numm/=i;
			numm%=M;
			ans+=numm;
			ans%=numm;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
