#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],Max,ans;
void dfs(int x,int cnt,int sum,int m,int Max){
	if(x>n+1)return;
	if(n-x+1+cnt<m)return;
	if(cnt==m){
		if(sum>Max*2)ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,cnt,sum,m,Max);
	dfs(x+1,cnt+1,sum+a[x],m,max(Max,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>Max*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(Max==1){
		for(int i=1;i<=n-2;i++){
			ans=(ans+i)%mod;
		}
		cout<<ans%mod;
	}
	if(n<=5000){
		for(int i=3;i<=n;i++)dfs(1,0,0,i,0);
		cout<<ans%mod;
		return 0;
	}
	return 0;
}