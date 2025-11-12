#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const long long mod=998244353;
int a[N];
long long ans;
bool vis[N];
int n;
void dfs(int k){
	if(k>n){
		int sum=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				mx=a[i];
			}
		}
		if(sum-mx>mx){
			ans++;
			ans%=mod;
		}
		return ;
	}
	vis[k]=0;
	dfs(k+1);
	vis[k]=1;
	dfs(k+1);
}
void solve(){
	for(int i=3;i<=n;i++){
		long long sum=1;
		for(int j=n;j>=n-i+1;j--){
			sum*=j;
			sum/=(n-j+1);
			sum%=mod;
		}
		ans+=sum;
		ans%=mod;
	}
	printf("%lld",ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    bool f1=0;
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
//        a[i]=1;
    	if(a[i]!=1){
    		f1=1;
		}
	}
	if(!f1){
		solve();
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
