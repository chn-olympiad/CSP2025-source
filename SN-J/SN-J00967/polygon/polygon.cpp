#include<bits/stdc++.h>
#define modd 998244353
#define int long long
using namespace std;
int n;
int ans=0;
int a[5005];
int suf[5005];
void dfs(int now,int sum,int maxx){
	if(now>n){
		if(sum>maxx*2){
			ans++;
			ans%=modd;
		}
		return;
	}
	if(maxx*2>sum+suf[now]){
		return;
	}
	dfs(now+1,sum+a[now],max(maxx,a[now]));
	dfs(now+1,sum,maxx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=false;
			break;
		}
	}
	if(flag){
		int res=0;
		for(int i=3;i<=n;i++){
			int val=1;
			for(int j=n;j>=n-i+1;j--){
				val*=j;
				val/=(n-j+1);
				val%=modd;
			}
			res+=val;
			res%=modd;
		}
		cout<<res;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
}
//AC AC AC 不要挂分 aqx 暴力出奇迹 
