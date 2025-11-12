//SN-J00797 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],p[5001],ny[5001],ans;
const int mod=998244353;
void dfs(int now,int sum,long long maxx,int num,bool b){
	if(num>=3&&sum>maxx*2&&b){ans++;ans%=mod;}
	if(now>n)return;
	dfs(now+1,sum,maxx,num,0);
	dfs(now+1,sum+a[now],max(a[now],maxx),num+1,1);
}
long long pow(long long a){
	long long ret=1,x=a,b=998244351;
	while(b){
		if(b%2)ret=(ret*x)%mod;
		b>>=1;
		x=(x*x)%mod;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20)dfs(1,0,0,0,0);
	else {
		p[0]=1;ny[0]=1;
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]*i;
			p[i]%=mod;
			ny[i]=pow(p[i]);
		}
		for(int i=3;i<=n;i++){
			ans+=(((p[n]*ny[n-i])%mod)*ny[i])%mod;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
