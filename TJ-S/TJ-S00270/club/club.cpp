#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node{
	ll w;
	int cnt1;
	int cnt2;
	int cnt3;
};

ll T, n;
ll d[5];
int arr[114514][5];
Node dp[114514][5];

bool cmp(ll a, ll b){
	return a>b;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin>>T;
	
	while(T--){
		memset(dp, 0, sizeof(dp));
		cin>>n;
		
		for(int i=1; i<=n; i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		
		for(int i=1; i<=n; i++){
			if(dp[i-1][1].cnt1 <= n/2){
				if(dp[i-1][1].w+arr[i][1]>dp[i][1].w && dp[i-1][1].cnt1<n/2){
					dp[i][1] = {dp[i-1][1].w+arr[i][1], dp[i-1][1].cnt1+1, dp[i-1][1].cnt2, dp[i-1][1].cnt3};
				}
				if(dp[i-1][1].w+arr[i][2]>dp[i][2].w && dp[i-1][1].cnt2<n/2){
					dp[i][2] = {dp[i-1][1].w+arr[i][2], dp[i-1][1].cnt1, dp[i-1][1].cnt2+1, dp[i-1][1].cnt3};
				}
				if(dp[i-1][1].w+arr[i][3]>dp[i][3].w && dp[i-1][1].cnt3<n/2){
					dp[i][3] = {dp[i-1][1].w+arr[i][3], dp[i-1][1].cnt1, dp[i-1][1].cnt2, dp[i-1][1].cnt3+1};
				}
			}
			if(dp[i-1][2].cnt2 <= n/2){
				if(dp[i-1][2].w+arr[i][1]>dp[i][1].w && dp[i-1][2].cnt1<n/2){
					dp[i][1] = {dp[i-1][2].w+arr[i][1], dp[i-1][2].cnt1+1, dp[i-1][2].cnt2, dp[i-1][2].cnt3};
				}
				if(dp[i-1][2].w+arr[i][2]>dp[i][2].w && dp[i-1][2].cnt2<n/2){
					dp[i][2] = {dp[i-1][2].w+arr[i][2], dp[i-1][2].cnt1, dp[i-1][2].cnt2+1, dp[i-1][2].cnt3};
				}
				if(dp[i-1][2].w+arr[i][3]>dp[i][3].w && dp[i-1][2].cnt3<n/2){
					dp[i][3] = {dp[i-1][2].w+arr[i][3], dp[i-1][2].cnt1, dp[i-1][2].cnt2, dp[i-1][2].cnt3+1};
				}
			}
			if(dp[i-1][3].cnt3 < n/2){
				if(dp[i-1][3].w+arr[i][1]>dp[i][1].w && dp[i-1][3].cnt1<n/2){
					dp[i][1] = {dp[i-1][3].w+arr[i][1], dp[i-1][3].cnt1+1, dp[i-1][3].cnt2, dp[i-1][3].cnt3};
				}
				if(dp[i-1][3].w+arr[i][2]>dp[i][2].w && dp[i-1][3].cnt2<n/2){
					dp[i][2] = {dp[i-1][3].w+arr[i][2], dp[i-1][3].cnt1, dp[i-1][3].cnt2+1, dp[i-1][3].cnt3};
				}
				if(dp[i-1][3].w+arr[i][3]>dp[i][3].w && dp[i-1][3].cnt3<n/2){
					dp[i][3] = {dp[i-1][3].w+arr[i][3], dp[i-1][3].cnt1, dp[i-1][3].cnt2, dp[i-1][3].cnt3+1};
				}
			}
			
			cout<<dp[i][1].w<<" "<<dp[i][2].w<<" "<<dp[i][3].w<<endl;
		}
		
		cout<<max(dp[n][1].w, max(dp[n][2].w, dp[n][3].w))<<endl;
	}
	
	return 0;
}
