#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,mod=998244353;
int a[N];
bool vis[N];
int ans,n;
void dfs(int k,int cnt){
	if(k>n){
		if(cnt<3){
			return;
		}
		int tot=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				tot+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(tot>mx*2){
//			cout<<tot<<' '<<mx<<endl;
			ans=(ans+1)%mod;
		}
		return;
	}
	vis[k]=1;
	dfs(k+1,cnt+1);
	vis[k]=0;
	dfs(k+1,cnt);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=3){
		if(n<=2) cout<<0<<endl;
		if(n==3){
			int tot=a[1]+a[2]+a[3];
			int mx=max({a[1],a[2],a[3]});
			if(tot>2*mx){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}else{
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}