//Code Originally Designed by Zhang Aoyi, SN-S00256, NOI CSP-J/S 2025, Shaanxi Province
//Lang: C++, Time: 14:30~18:30, NPU Chang'an Campus
//Xi'an Aerospace City No.1 (Junior) High School
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >q;
//club
int T,n,a[100086][5];
int spAt[100086];
int ans;
ll tj;
//struct spbt{
//	int co1,co2;
//};
//spbt spBt[100086];
void dfs(int id,int sum,int dp1,int dp2,int dp3){
	if(id==n){
		ans=max(ans,sum);
	}
	if(dp1<n/2) dfs(id+1,sum+a[id+1][1],dp1+1,dp2,dp3);
	if(dp2<n/2) dfs(id+1,sum+a[id+1][2],dp1,dp2+1,dp3);
	if(dp3<n/2) dfs(id+1,sum+a[id+1][3],dp1,dp2,dp3+1);
}
void dfsB(int id,int sum,int dp1,int dp2,int dp3){
	if(id==n){
		ans=max(ans,sum);
	}
	if(dp1<n/2) dfs(id+1,sum+a[id+1][1],dp1+1,dp2,dp3);
	if(dp2<n/2) dfs(id+1,sum+a[id+1][2],dp1,dp2+1,dp3);
	//if(dp3<n/2) dfs(id+1,sum+a[id+1][3],dp1,dp2,dp3+1);
}
int dp[100086][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool spA=1,spB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) spA=0;
			if(a[i][3]!=0) spB=0;
		}
		ans=0;
		if(spA){
			for(int i=1;i<=n;i++){
				spAt[i]=a[i][1];
			}
			sort(spAt+1,spAt+1+n);
			for(int i=n;i>n/2;i--){
				ans+=spAt[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(spB){
			dfsB(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;

	}
	return 0;
}


