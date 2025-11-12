#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void dfs(int p,int sum,int maxn,int ch){
	if(p==n+1){
		if(maxn*2<sum&&ch>=3)ans++;
		return ;
	}
	dfs(p+1,sum+a[p],a[p],ch+1);
	dfs(p+1,sum,maxn,ch);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0,0);cout<<ans;
	}else if(a[n]<=1){
		long long x=1;
		for(int i=1;i<=n;i++){
			x*=2;x%=998244353;
		}
		x-=n*(n-1)/2;x-=n;x-=1;
		while(x<0)x+=998244353;
		printf("%lld\n",x);
	}else{
		cout<<0;
	}
	return 0;
}
