#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long a[5005];
long long ans;
int add(long long x,long long y){
	return (x+y>=mod?x+y-mod:x+y);
}
int del(long long x,long long y){
	return (x-y<0?x-y+mod:x-y);
}
void dfs(int step,long long maxa,long long sum,long long num){
	if(step==n+1){
		if(maxa*2<sum&&num>=3)  ans=add(ans,1LL);
		return;
	}
	dfs(step+1,max(maxa,a[step]),sum+a[step],num+1);
	dfs(step+1,maxa,sum,num);
}
void solve1(){
	ans=0;
	dfs(1,-1LL,0LL,0LL);
	cout<<ans<<endl;
}
void q_pow(){
	for(int i=1;i<=n;i++) ans=(ans*2)%mod;
}
long long maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3]) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(n<=20){
		solve1();
		return 0;
	}
	if(maxx<=1){
		ans=1;
		q_pow();
		ans=del(ans,1LL);
		ans=del(ans,n);
		long long tmp=n*(n-1)/2%mod;
		ans=del(ans,tmp);
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}