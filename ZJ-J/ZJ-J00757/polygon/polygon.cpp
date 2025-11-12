#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005],powtwo[10005],maxa,ans,dp[50005];
void dfs(int k,int mx,int sum,int cnt){
	if(k>n){
		if(sum>2*mx&&cnt>=3) ans++;
		return;
	}
	dfs(k+1,max(mx,a[k]),sum+a[k],cnt+1);
	dfs(k+1,mx,sum,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans%mod<<"\n";
		return 0;
	}
	powtwo[0]=1;
	for(int i=1;i<=10000;i++){
		powtwo[i]=(powtwo[i-1]*2)%mod;
	}
	if(maxa==1){
		cout<<(powtwo[n]-n-n*(n-1)/2-1+mod)%mod<<"\n";
		return 0;
	}
	dp[0]=1;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=sum;j>=0;j--){
			if(dp[j]){
				dp[j+a[i]]+=dp[j];
				dp[j+a[i]]%=mod;
			}
		}
		for(int j=2*a[i]+1;j<=sum;j++){
			ans+=dp[j];
			ans%=mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}//64pts