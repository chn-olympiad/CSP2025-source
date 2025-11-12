#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
bool vis[(1<<20)+5];
int mx[(1<<20)+5];
int dp[N];
int main(){
//	freopen()ni bei pian le
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]^a[i];
	vis[0]=true;
	for(int i=1;i<=n;++i){
		int lst=k^sum[i];
		dp[i]=dp[i-1];
		if(vis[lst]){
			dp[i]=max(dp[i],mx[lst]+1);
		}
		vis[sum[i]]=true;
		mx[sum[i]]=max(dp[i],mx[sum[i]]);
	}
	cout<<dp[n]<<endl;
	return 0;
}//mei bi yao dui pai,dan hai si xie le
