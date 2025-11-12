//钟景其 SN-S00726 西安市曲江第一中学 

#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+5;
int dp[N][3];
int arr[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>dp[i][j];
			}
		}
		int k=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i][j],dp[i+1][j]+dp[i][j+1]);

			}
		}
		for(int i=1;i<=n;i++){

			int max1=max(dp[i][1],dp[i][2]),max2=max(dp[i][3],max1);
			arr[i]=max2;
		}

		int ans=0;
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=arr[i];
		}
		cout<<ans<<endl;
	}

	return 0;
}





