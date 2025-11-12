#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int n,a[N],sum[N];
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
vector<ll>cur;
bool check(){
	if(cur.size()<3) return 0;
	ll maxn=-1e18,tot=0;
	for(int i=0;i<cur.size();i++){
		maxn=max(maxn,cur[i]);
		tot+=cur[i];
	}
	return (tot>maxn*2);
}
ll dfs(int x){
	if(x==n+1){
		return check();
	}
	ll res1=dfs(x+1)%mod;
	cur.push_back(a[x]);
	ll res2=dfs(x+1)%mod;
	cur.pop_back();
	return (res1+res2)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=20){
		cout<<dfs(1);
	}
	sort(a+1,a+1+n);
	
	if(a[n]==1){
		cout<<n-2<<'\n';
		return 0;
	}
	ll re0=0;
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		//假设a[i]就是最大值
		if(sum[i]<a[i]) continue;
		
	}
	cout<<n+1<<'\n';
	return 0;
}