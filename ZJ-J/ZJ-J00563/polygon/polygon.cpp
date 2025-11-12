#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
int n,a[10000],b[10000];
int ans;
int vis[10000];
void dfs(int k,int sum){// 5 10
	if(sum<=a[k]){
//		cout<<sum<<"\n";
	return;
	}// 1 2 3 4 5 
	ans++;
	for(int i=1;i<k;i++){
//		if(vis[i]=1) continue;
		vis[i]=1;
		
		dfs(i,sum-a[i]);
//		sum+=a[i];
		vis[i]=0;
	}
	//bfs(i-1,sum-a[i])
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		b[i]=a[i];
//		b[i]+=a[i-1];
	}sort(a+1,a+1+n);
	if(a[n]==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=n;
		ans-=1;
		int s=n*(n-1)/2;
		ans-=s;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1];
		b[i]+=a[i];
	}for(int i=n;i>=3;i--){
		int k=i;
		if(b[i-1]<=a[i]) continue;
		dfs(k,b[i-1]);
		ans%=mod;
		// É¾a[],ºÍ 
//		cout<<ans<<"\n";
	}cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4


