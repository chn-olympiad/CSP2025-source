#include<bits/stdc++.h>
using namespace std;
int dp[100005][5];
int t,n,x,y,z;
int a[100005][5];
int maxn;
int ans;
void dfs(int step,int x,int y,int z){
	if(step==n+1){
		maxn=max(maxn,ans);
		return;
	}
	if(x>0){
		ans+=a[step][1];
		dfs(step+1,x-1,y,z);
		ans-=a[step][1];
	}
	if(y>0){
		ans+=a[step][2];
		dfs(step+1,x,y-1,z);
		ans-=a[step][2];
	}
	if(z>0){
		ans+=a[step][3];
		dfs(step+1,x,y,z-1);
		ans-=a[step][3];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=ans=0;
		memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,n/2,n/2,n/2);
		cout<<maxn<<"\n"; 
	}
	return 0;
}