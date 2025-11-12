#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
int a[50005];
int dp[1001][1001];
int tiao[1001][2];
int maxs=0;
bool vis[50005];
void dfs(int num,int sum){
	if(sum>cnt){
		if(num-1>=maxs){
			maxs=num-1;
		}
		return;
	}
	else{
		int s=0;
		for(int i=tiao[sum][0];i<=tiao[sum][1];i++){
			if(vis[i]==false){
				s++;
			}
		}
		if(s==(tiao[sum][1]-tiao[sum][0]+1)){
			for(int i=tiao[sum][0];i<=tiao[sum][1];i++){
				vis[i]=true;
			}
			dfs(num+1,sum+1);
			for(int i=tiao[sum][0];i<=tiao[sum][1];i++){
				vis[i]=false;
			}
		}
		else{
			dfs(num,sum+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k0=0;
	int k1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			k0++;
		}
		else if(a[i]=1){
			k1++;
		}
	}
	if(k0+k1==n){
		if(k==0){
			cout<<k0;
			return 0;
		}
		else if(k==1){
			cout<<k1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
		if(dp[i][i]==k){
			cnt++;
			tiao[cnt][0]=i;
			tiao[cnt][1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=(dp[i][j-1]^a[j]);
			if(dp[i][j]==k){
				cnt++;
				tiao[cnt][0]=i;
				tiao[cnt][1]=j;
			}
		}
	}
	dfs(1,1);
	cout<<maxs;
	return 0;
}
