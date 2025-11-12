#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,K=(1<<20)+61;
int n,k,a[N],dp[N],sum[N],pos[N];
vector<int>V[K];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]^a[i];
		V[sum[i]].push_back(i);
	}
	for(int i=0;i<(1<<20);i++)reverse(V[i].begin(),V[i].end());
	for(int i=n;i;i--){
		int x=k^sum[i+1];
		while(V[x].size()&&V[x].back()>i)V[x].pop_back();
		if(V[x].size())pos[i]=V[x].back();
		else pos[i]=-1;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(pos[i]!=-1)dp[i]=max(dp[i],dp[pos[i]-1]+1);
	}
	cout<<dp[n]<<'\n';
	return 0;
}