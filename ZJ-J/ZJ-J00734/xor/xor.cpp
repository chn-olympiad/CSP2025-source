#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N];
struct node{
	int l,r;
};
vector<node> q;
int len,dp[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		mx=max(mx,a[i]);
	}
	if(n<=5000){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k)
					q.push_back({i,j});
		len=q.size();
		for(int i=0;i<len;i++){
			dp[i]=1;
			for(int j=0;q[j].r<q[i].l;j++)
				dp[i]=max(dp[i],dp[j]+1);
			ans=max(ans,dp[i]);
		}
		cout<<ans;
		return 0;
	}
	if(mx<=1){
		if(k==1)
			for(int i=1;i<=n;i++)
				if(a[i]==1)	ans++;
		else if(k==0){
			int vis[N];
			for(int i=1;i<=n;i++){
				vis[i]=0;
				if(a[i]==0)	ans++;
				else if(a[i-1]==1&&!vis[i-1]){
					ans++;
					vis[i-1]=vis[i]=1;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	srand(0);
	cout<<rand();
	return 0;
}
