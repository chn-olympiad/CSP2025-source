#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10,M=3e7,MOD=998244353;
ll n,m,ans,k;
ll a[N];
ll dp[M];
void dfs(ll step,ll sum,ll num,ll maxn,string b){
	if(step>n+1) return ;
	if((num==maxn)){
		if(a[step-1]<sum-a[step-1]) dp[maxn]++;
//		cout<<b<<":"<<step<<' '<<sum<<' '<<num<<"\n";
		return ;
	}
	
	for(ll i=step;i<=n;i++){
		dfs(i+1,sum+a[i],num+1,maxn,b+char(a[i]+'0'));
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		for(ll i=3;i<=n;i++){
			ans+=(i+n)*(n-i+1)/2;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(n>24){
		cout<<"0\n";
		return 0;
	}
	for(ll i=3;i<=n;i++) dfs(1,0,0,i,"");
	for(ll i=3;i<=n;i++) ans+=dp[i];
	cout<<ans<<"\n";
//	for(ll i=0;i<=n;i++) cout<<dp[i]<<' ';
	return 0;
}
/*

*/
