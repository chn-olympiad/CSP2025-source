#include <iostream>

using namespace std;
const int mod = 998244353;
const int N = 5005;
int a[N];
int mx[N];
bool vis[N];
int n;

long long dfs(int i,int cnt,long long ans,long long maxn,long long sum){
	if(cnt==i) return ans;
	for(int j=1;j<=n;j++){
		maxn=max(maxn,1ll*a[j]);
		if(sum+a[j]>maxn*2&&!vis[j]){
			vis[j]=1;
			dfs(i,cnt+1,ans+1,maxn,sum+a[j]);
			vis[j]=0;
		} 
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx[i]=max(mx[i-1],a[i]);
		if(a[i]<=1) cnt1++;
	} 
	if(n<3||n==3&&a[1]+a[2]+a[3]<=max(a[1],max(a[2],a[3]))*2){
		cout<<0;
		return 0;
	}
	else if(cnt1==n){
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long cnt=1;
			for(int j=n;j>(n-i);j--){
				cnt*=j%mod;
			}
			ans+=cnt%mod;
			cout<<ans<<'\n';
		}
		
	}
	else{	
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=dfs(i,0,0,0,0)%mod;
		}
		cout<<ans;
	}

	return 0;
}

