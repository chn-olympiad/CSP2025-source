#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n;
int a[N];
long long c[N];
long long ans=0;
long long Pow(long long a,int b){
	long long res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res%mod;
}
int C(int m,int n){
	return c[n]*Pow(c[m],mod-2)%mod*Pow(c[n-m],mod-2)%mod;
}
long long get(int x){
	long long res=0;
	for(int i=0;i<=n-x+1;i++){
		res=(res+C(i,n-x+1))%mod;
	}
	return res;
}
long long get_1(){
	long long res=0;
	for(int i=3;i<=n;i++){
		res=(res+C(i,n))%mod;
	}
	return res;
}
void dfs(int x,int mx,int sum){
	if(sum>2*mx){
		ans+=get(x);
		return;
	}
	if(x>n) return;
	dfs(x+1,(!mx?a[x]:mx),sum+a[x]);
	dfs(x+1,mx,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]*i%mod;
	}
	sort(a+1,a+n+1,[](int x,int y){
		return x>y;
	});
	if(a[1]==1){
		cout<<get_1()<<endl;
	}else{
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
