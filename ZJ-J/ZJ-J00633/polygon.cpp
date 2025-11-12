#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int n,a[5005],ans,r,pd,pf=1;
int f(int k){
	int x=1;
	for(int i=1;i<=k;i++){
		x=(x*2)%mod;
	}
	return x;
}
void dfs(int i,int x,int s,int v){
	pd=0;
	if(v>=2 and s>x){
		ans+=f(r-i+1);
		ans--;
		ans%=mod;
		pd=1;
		return ;
	}
	if(i==r){
		return ;
	}
	dfs(i+1,x,s+a[i],v+1);
	if(pd){
		pd=0;
		return ;
	}
	dfs(i+1,x,s,v);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]){
			pf=0;
		}
	}
	if(pf){
		for(int i=1;i<=n-2;i++){
			int l=(f(i)-1)%mod;
			ans+=(l*(n-i-1))%mod;
			ans%=mod;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		r=i;
		dfs(1,a[i],0,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
