#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=1e5+7, M=2e2+7;
int T;
int n=0, top=0;
int a[N][5];
int dp[M][M][M];
bool cmp(int a, int b){
	return a>b;
}
struct node{
	int e[3];
	int at;
};
signed main(){
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		memset(a, 0, sizeof a); memset(dp, 0, sizeof dp);
		cin>>n; top=n/2;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int sum23=0, sum3=0;
		for(int i=1;i<=n;i++){
			sum23+=a[i][2]; sum23+=a[i][3];
			sum3+=a[i][3];
		}
		if(sum23==0){
			int a1[N];
			memset(a1, 0, sizeof a1);
			for(int i=1;i<=n;i++){
				a1[i]=a[i][1];
			}
			sort(a1+1, a1+1+n, cmp);
			int Ans=0;
			for(int i=1;i<=top;i++) Ans+=a1[i];
			cout<<Ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=top;j>=0;j--){
				for(int k=top;k>=0;k--){
					for(int l=top;l>=0;l--){
						dp[j][k][l]=max({
							dp[j][k][l],
							j>=1?dp[j-1][k][l]+a[i][1]:0,
							k>=1?dp[j][k-1][l]+a[i][2]:0,
							l>=1?dp[j][k][l-1]+a[i][3]:0
						});
					}
				}
			}
		}
		cout<<dp[top][top][top]<<"\n";
	}
	return 0;
}
