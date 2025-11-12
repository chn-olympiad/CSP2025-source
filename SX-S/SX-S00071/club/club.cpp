#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N][3],fp[N],n,ans,b[N],dp[N];
//int dp[N][N];
void dfs(int k,int cnt1,int cnt2,int cnt3){
	if(k>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][fp[i]];
		}
		ans=max(sum,ans);
		return;
	}
	if(cnt1+1<=n/2){
		fp[k]=1;
		dfs(k+1,cnt1+1,cnt2,cnt3);
	}
	if(cnt2+1<=n/2){
		fp[k]=2;
		dfs(k+1,cnt1,cnt2+1,cnt3);
	}
	if(cnt3+1<=n/2){
		fp[k]=3;
		dfs(k+1,cnt1,cnt2,cnt3+1);
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool cnt=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) cnt=0;
		}
		if(n<=30){
			dfs(1,0,0,0);
			cout<<ans<<endl;
		}else{
			if(cnt){
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
				sort(b+1,b+n+1,greater<int>());
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=b[i];
				}
				cout<<ans<<endl;
			}else{
				for(int i=1;i<=n;i++){
					dp[i]=dp[i-1]+max({a[i][1],a[i][2],a[i][3]});
				}
				cout<<dp[n]<<endl;
			}
		}
	}
	return 0;
}