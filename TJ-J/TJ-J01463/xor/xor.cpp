#include<bits/stdc++.h>
using namespace std;
int f[500005];
//bool cmp(int x,int b){
//	if(x >= b){
//		return 1;
//	}else{
//		return 0;
//	}
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	int n,k;
//	cin>>n>>k;
//	for(int i = 1;i<=n;i++){
//		cin>>b[i];
//	}
//	for(int i = 1;i<=n;i++){
//		for(int j = n;j>=i;j--){
//			int a = 0;
//			int t = 0;
//			int num;
//			while(t<=i-1){
//				num = b[j-t];
//				a = a xor num;
//				t++;	
//			}
//			if(a == k){
//				dp[n][j] = max(dp[n-1][j],dp[n-1][j-i] + 1);
//			}else{
//				dp[n][j] = dp[n-1][j];
//			}
//
//		}
//
//	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>f[i];
	}
	cout<<n/2;

	

	
	
	
	
	
	
	
	
	return 0;
} 
