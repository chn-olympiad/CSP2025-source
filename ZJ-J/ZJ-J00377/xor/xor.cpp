#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;int n,m,a[N],sum[N],dp[N];map<int,int> vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];dp[0]=0,vis[0]=0;int cc;
	for(int i=1;i<=n;i++) dp[i]=((vis[sum[i]^m]>0||sum[i]==m)?max(dp[vis[sum[i]^m]]+1,dp[i-1]):dp[i-1]),vis[sum[i]]=i;
	cout<<dp[n];
	return 0;
}
//9:37  shenminga,qingzaijuanguwoyici
