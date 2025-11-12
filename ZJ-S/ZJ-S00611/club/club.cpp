#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a1[100005],a2[100005],a3[100005];
int dp[205][205][205];
int f1,f2,f3;
void dfs(int i,int s){
	if(i>n){
		ans=max(ans,s);
		return ;
	}
	if(f1<(n/2)){
		f1++;
		dfs(i+1,s+a1[i]);
		f1--;
	}
	if(f2<(n/2)){
		f2++;
		dfs(i+1,s+a2[i]);
		f2--;
	}
	if(f3<(n/2)){
		f3++;
		dfs(i+1,s+a3[i]);
		f3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,f1=0,f2=0,f3=0;
		memset(dp,0,sizeof(dp));
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0||a3[i]!=0) fa=0;
			if(a3[i]!=0) fb=0;
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(fa==1){
			sort(a1+1,a1+1+n,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(fb==1){
			dp[1][1][0]=a1[1];
			dp[1][0][1]=a2[1];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n/2&&j<=i;j++){
					for(int k=1;k<=n/2&&k<=i;k++){
						dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k],max(dp[i-1][j-1][k]+a1[i],dp[i-1][j][k-1]+a2[i])));
					}
				}
			}
			cout<<dp[n][n/2][n/2]<<endl;//¸Ð¾õÒª·Ï 
			continue;
		}
	}
	return 0;
}
