#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,maxx;
int a[5005];
void dfs(int x,int maxx,int sum){
	if(x>n){
		if(sum>2*maxx) ans++;
		return;
	}
	dfs(x+1,max(maxx,a[x]),sum+a[x]);
	dfs(x+1,maxx,sum);
}
int c(int x,int y){
	int sum=1,t=x;
	for(int i=y;i>=y-x+1;i--){
		sum*=i;
		while(sum%t==0&&t>1){
			sum/=t;
			t--;
		} 
		sum%=mod;
	}
	return sum;
}
signed main(){
//	cout<<sizeof(f)/1024/1024;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(maxx==1){
		for(int i=3;i<=n;i++)
			ans=(ans+c(i,n))%mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
