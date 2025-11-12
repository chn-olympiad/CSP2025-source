#include<bits/stdc++.h>
using namespace std;
int n,a[100100][10];
struct node{
	int x,y,z,dis;
};
node dp[100100][3];
bool cmp3(int x,int y){
	return x>y;
}
int dfs(int i,int x,int y,int z,int sum){
	if(i>n){
		return sum;
	}
	int mx=0xc0c0c0c0;
	if(x<n/2){
		mx=max(mx,(int)dfs(i+1,x+1,y,z,sum+a[i][1]));
	}
	if(y<n/2){
		mx=max(mx,(int)dfs(i+1,x,y+1,z,sum+a[i][2]));
	}
	if(z<n/2){
		mx=max(mx,(int)dfs(i+1,x,y,z+1,sum+a[i][3]));
	}
	return mx;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		bool flaga=1;
		int qwq=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(i==1&&a[i][j]!=0){
					if(qwq!=0){
						flaga=0;
					}else{
						qwq=j;	
					}
				}else{
					if(a[i][j]!=0){
						if(j!=qwq){
							flaga=0;
						}
					}
				}
			}
		}
		if(flaga==1){
			vector<int>v;
			for(int i=1;i<=n;i++){
				v.push_back(a[i][qwq]);
			}
			sort(v.begin(),v.end(),cmp);
			int sum=0,cnt=0;
			for(int i=0;i<v.size();i++){
				sum+=v[i];
				cnt++;
				if(cnt==n/2)break;
			}
			cout<<sum<<'\n';continue;
		}
		if(n>10){
			for(int i=1;i<=n;i++){
			 	int cur[4];
				for(int i=1;i<=3;i++)cur[i]=INT_MIN;
				if(dp[i-1][1].x<n/2)cur[1]=dp[i-1][1].dis;
				if(dp[i-1][2].x<n/2)cur[2]=dp[i-1][2].dis;
				if(dp[i-1][3].x<n/2)cur[3]=dp[i-1][3].dis;
				dp[i][1].dis=max(cur[1],max(cur[2],cur[3]))+a[i][1],dp[i][1].y++;
				for(int i=1;i<=3;i++)cur[i]=INT_MIN;
				if(dp[i-1][1].y<n/2)cur[1]=dp[i-1][1].dis;
				if(dp[i-1][2].y<n/2)cur[2]=dp[i-1][2].dis;
				if(dp[i-1][3].y<n/2)cur[3]=dp[i-1][3].dis;
				dp[i][2].dis=max(cur[1],max(cur[2],cur[3]))+a[i][2],dp[i][2].y++;
				for(int i=1;i<=3;i++)cur[i]=INT_MIN;
				if(dp[i-1][1].z<n/2)cur[1]=dp[i-1][1].dis;
				if(dp[i-1][2].z<n/2)cur[2]=dp[i-1][2].dis;
				if(dp[i-1][3].z<n/2)cur[3]=dp[i-1][3].dis;
				dp[i][3].dis=max(cur[1],max(cur[2],cur[3]))+a[i][3],dp[i][3].z++;
			}                                    
			cout<<max(dp[n][1].dis,max(dp[n][2].dis,dp[n][3].dis))<<'\n';
			continue;
		}
		cout<<dfs(1,0,0,0,0)<<'\n';
	}           
	return 0;	
}

//S00872
//18:19