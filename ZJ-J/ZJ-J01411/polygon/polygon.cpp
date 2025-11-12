#include<bits/stdc++.h>
using namespace std;
long long dp[105][50005],n,x,Max,Sum,u,y,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		Max=max(Max,x);
		Sum+=x;
		u=((Sum-x)&7);
		y=x+1;
		if(u>0){
			for(int j=0;j<y;j++){
				dp[x][Sum]+=dp[j][Sum-x];
				if(dp[x][Sum]>4500000000000000000ll)dp[x][Sum]%=998244353;
			}
		}
		if(u>1){
			for(int j=0;j<y;j++){
				dp[x][Sum-1]+=dp[j][Sum-x-1];
				if(dp[x][Sum-1]>4500000000000000000ll)dp[x][Sum-1]%=998244353;
			}
		}
		if(u>2){
			for(int j=0;j<y;j++){
				dp[x][Sum-2]+=dp[j][Sum-x-2];
				if(dp[x][Sum-2]>4500000000000000000ll)dp[x][Sum-2]%=998244353;
			}
		}
		if(u>3){
			for(int j=0;j<y;j++){
				dp[x][Sum-3]+=dp[j][Sum-x-3];
				if(dp[x][Sum-3]>4500000000000000000ll)dp[x][Sum-3]%=998244353;
			}
		}
		if(u>4){
			for(int j=0;j<y;j++){
				dp[x][Sum-4]+=dp[j][Sum-x-4];
				if(dp[x][Sum-4]>4500000000000000000ll)dp[x][Sum-4]%=998244353;
			}
		}
		if(u>5){
			for(int j=0;j<y;j++){
				dp[x][Sum-5]+=dp[j][Sum-x-5];
				if(dp[x][Sum-5]>4500000000000000000ll)dp[x][Sum-5]%=998244353;
			}
		}
		if(u>6){
			for(int j=0;j<y;j++){
				dp[x][Sum-6]+=dp[j][Sum-x-6];
				if(dp[x][Sum-6]>4500000000000000000ll)dp[x][Sum-6]%=998244353;
			}
		}
		for(int k=Sum-((Sum-x)&7)-7;k>x;k-=8){
			for(int j=0;j<y;j++){
				dp[x][k+7]+=dp[j][k-x+7];
				if(dp[x][k+7]>4500000000000000000ll)dp[x][k+7]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+6]+=dp[j][k-x+6];
				if(dp[x][k+6]>4500000000000000000ll)dp[x][k+6]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+5]+=dp[j][k-x+5];
				if(dp[x][k+5]>4500000000000000000ll)dp[x][k+5]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+4]+=dp[j][k-x+4];
				if(dp[x][k+4]>4500000000000000000ll)dp[x][k+4]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+3]+=dp[j][k-x+3];
				if(dp[x][k+3]>4500000000000000000ll)dp[x][k+3]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+2]+=dp[j][k-x+2];
				if(dp[x][k+2]>4500000000000000000ll)dp[x][k+2]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k+1]+=dp[j][k-x+1];
				if(dp[x][k+1]>4500000000000000000ll)dp[x][k+1]%=998244353;
			}
			for(int j=0;j<y;j++){
				dp[x][k]+=dp[j][k-x];
				if(dp[x][k]>4500000000000000000ll)dp[x][k]%=998244353;
			}
		}
		for(int j=0;j<y;j++){
			dp[x][x]+=dp[j][0];
			if(dp[x][x]>4500000000000000000ll)dp[x][x]%=998244353;
		}
		for(int j=Max;j>x;j--){
			if(u>0){
				dp[j][Sum]+=dp[j][Sum-x];
				if(dp[j][Sum]>4500000000000000000ll)dp[j][Sum]%=998244353;
			}
			if(u>1){
				dp[j][Sum-1]+=dp[j][Sum-x-1];
				if(dp[j][Sum-1]>4500000000000000000ll)dp[j][Sum-1]%=998244353;
			}
			if(u>2){
				dp[j][Sum-2]+=dp[j][Sum-x-2];
				if(dp[j][Sum-2]>4500000000000000000ll)dp[j][Sum-2]%=998244353;
			}
			if(u>3){
				dp[j][Sum-3]+=dp[j][Sum-x-3];
				if(dp[j][Sum-3]>4500000000000000000ll)dp[j][Sum-3]%=998244353;
			}
			if(u>4){
				dp[j][Sum-4]+=dp[j][Sum-x-4];
				if(dp[j][Sum-4]>4500000000000000000ll)dp[j][Sum-4]%=998244353;
			}
			if(u>5){
				dp[j][Sum-5]+=dp[j][Sum-x-5];
				if(dp[j][Sum-5]>4500000000000000000ll)dp[j][Sum-5]%=998244353;
			}
			if(u>6){
				dp[j][Sum-6]+=dp[j][Sum-x-6];
				if(dp[j][Sum-6]>4500000000000000000ll)dp[j][Sum-6]%=998244353;
			}
			for(int k=Sum-((Sum-x)&7)-7;k>x;k-=8){
				dp[j][k+7]+=dp[j][k-x+7];
				if(dp[j][k+7]>4500000000000000000ll)dp[j][k+7]%=998244353;
				dp[j][k+6]+=dp[j][k-x+6];
				if(dp[j][k+6]>4500000000000000000ll)dp[j][k+6]%=998244353;
				dp[j][k+5]+=dp[j][k-x+5];
				if(dp[j][k+5]>4500000000000000000ll)dp[j][k+5]%=998244353;
				dp[j][k+4]+=dp[j][k-x+4];
				if(dp[j][k+4]>4500000000000000000ll)dp[j][k+4]%=998244353;
				dp[j][k+3]+=dp[j][k-x+3];
				if(dp[j][k+3]>4500000000000000000ll)dp[j][k+3]%=998244353;
				dp[j][k+2]+=dp[j][k-x+2];
				if(dp[j][k+2]>4500000000000000000ll)dp[j][k+2]%=998244353;
				dp[j][k+1]+=dp[j][k-x+1];
				if(dp[j][k+1]>4500000000000000000ll)dp[j][k+1]%=998244353;
				dp[j][k]+=dp[j][k-x];
				if(dp[j][k]>4500000000000000000ll)dp[j][k]%=998244353;
			}
			dp[j][x]+=dp[j][0];
			if(dp[j][x]>4500000000000000000ll)dp[j][x]%=998244353;
		}
	}
	for(int i=0;i<=Max;i++){
		for(int j=0;j<=Sum;j++){
			if(i*2<j)ans+=dp[i][j];
			if(ans>4500000000000000000ll)ans%=998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
