#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],dp[10005],ans=0,q[10005];
bool vis[10005][10005];
struct node{
	int l,r;
};
vector<node>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((q[j])^(q[i-1]))==k){
				v.push_back({i,j});
		//		int x=(q[j])^(q[i-1]);
				//cout<<i<<" "<<j<<" "<<x<<'\n';
			}
		}
	}
	for(int i=1;i<=v.size();i++){
		dp[i]=1;
	}
	for(int i=1;i<=v.size();i++){
		
		for(int j=1;j<=v.size();j++){
			if(v[i-1].r<v[j-1].l){
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
		
	}
	for(int i=1;i<=v.size();i++){
		ans=max(ans,dp[i]);
	//	cout<<dp[i]<<" ";
	}
//	cout<<"\n";
	cout<<ans;
	return 0;
}
