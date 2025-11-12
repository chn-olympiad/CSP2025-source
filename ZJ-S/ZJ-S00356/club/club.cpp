#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll n,i,a1,a2,a3;
	bool operator<(node x){
		return n<x.n;
	}
}dp[N][5];
ll n,ans,a[N][5];bool p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[1][1].n=a[1][1];dp[1][1].a1=1;
		dp[1][2].n=a[1][2];dp[1][2].a2=1;
		dp[1][3].n=a[1][3];dp[1][3].a3=1;
		for(int i=2;i<=n;i++){
			sort(dp[i-1]+1,dp[i-1]+4);
			dp[i][1].n=dp[i-1][1].n+a[i][1];
			dp[i][2].n=dp[i-1][1].n+a[i][2];
			dp[i][3].n=dp[i-1][1].n+a[i][3];
			dp[i][1].a1=dp[i-1][1].a1+1;
			dp[i][2].a1=dp[i-1][1].a2+1;
			dp[i][3].a1=dp[i-1][1].a3+1;
		}
		sort(dp[n]+1,dp[n]+4);
		cout<<dp[n][1]<<"\n";
	}
	return 0;
}//i can't