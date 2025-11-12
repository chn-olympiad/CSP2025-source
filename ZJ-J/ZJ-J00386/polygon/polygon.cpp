#include<bits/stdc++.h>
#define int long long
const int m=998244353;
using namespace std;
int n,ans,v[5005],h,a[5005];
int c[5005];
void dfs(int x,int mx,int s){
	if(mx*2<s){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(i,max(mx,a[i]),s+a[i]);
			v[i]=0;
		}  
	}
	return;
}
int qpow(int a,int b){
	int s=1;
	while(b){
		if(b&1)
		  s=s*a%m;
		a=a*a%m;
		b=b/2;
	}
	return s;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)h++; 
	}
	if(h==n){
		c[1]=1;
		for(int i=2;i<=n;i++){
			c[i]=c[i-1]*i%m;
		} 
		for(int i=3;i<=n;i++){//在n个中选出i个(i边形) 
			ans=(ans+c[n]%m*qpow(c[n-i],m-2)%m*qpow(c[i],m-2)%m)%m; 
		}
		cout<<(ans+1)%m;
		return 0;
	}  
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
