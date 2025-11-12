#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
ll n,i,a[N],maxn=0,ans=0,b[N];
ll Pow(ll x,ll y){
	if(y==0)return 1;
	ll res=Pow(x,y/2)%mod;
	if(y%2==1)return (((res*res)%mod)*x)%mod;
	else return (res*res)%mod;
}
void solve(ll v,ll sum){
	if(v>=i){
		if(sum>a[i])ans=(ans+1)%mod;
		return;
	}
	solve(v+1,sum);
	solve(v+1,sum+a[v]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		ans=(mod+Pow(2,n)-1-n-(n*(n-1)/2)%mod)%mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(i=3;i<=n;i++)solve(1,0);
	cout<<ans%mod;
	return 0;
}
