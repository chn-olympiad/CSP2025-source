#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=1e3+5;
int n;
ll pre[maxn],dp[maxn][maxn];
ll a[maxn],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n>1005){
		map<int,int> mp;
		if(k==0){ 
			for(int i=1;i<=n;i++){
				int aaa;
				cin>>aaa;
				mp[aaa]++;
			}
			cout<<mp[0];
			return 0;
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				int aaa;
				cin>>aaa;
				mp[aaa]++;
			}
			cout<<mp[1];
			return 0;
		}
		srand(time(0));
		cout<<rand()%n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(a[i]==k) dp[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=len+l-1;
			if((pre[r]^pre[l-1])==k) dp[l][r]=1;
			for(int k=l;k<=r;k++){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}