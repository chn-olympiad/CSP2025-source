#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
int dp[N];
struct Node{
	int l,r;
};
vector<Node> ans; 

bool cmp(Node x,Node y){
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int x=sum[i]^sum[j-1];
			if(x==k){
				ans.push_back({j,i});
				break;
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		for(int j=n;j>=ans[i].r;j--){
			dp[0]=0;
			dp[j]=max(dp[j],dp[ans[i].l-1]+dp[j]-dp[ans[i].r]+1);
			dp[0]=0;
			//cout<<i<<' '<<j<<' '<<dp[j]<<' '<<dp[ans[i].l-1]<<' '<<dp[ans[i].r]<<' '<<ans[i].l-1<<' '<<ans[i].r<<"\n";
		}
	}
	cout<<dp[n];
	return 0;
}
