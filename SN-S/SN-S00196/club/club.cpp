#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,ans=0;
int k=3;
int a[N][3],dp[N][3],r[N][3];

int fs(int ans){
	for(int j = 1;j <= k ;++j){
		for(int i = 1;i <= N; ++i){
			if(dp[i][j] > 0){
				r[i][j]=min(r[i][j],dp[i][j]);
			} 
		ans++;
		}
		if(ans > N/2){
			for(int i = 1;i <= N; ++i){
				for(int j = 1;j <= k; ++j){
					sum+=dp[i][j];
				}		
			}		
		}
	}
	return sum;
}
	

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t){
		for(int i = 1;i <= N; ++i){
			for(int j = 1;j <= k; ++j){
				cin >> a[i][j];
				dp[i][j]=max(dp[i][j],a[i][j]);
			}
		}
		fs(0);
		cout << sum;	
	}
	return 0; 
}
