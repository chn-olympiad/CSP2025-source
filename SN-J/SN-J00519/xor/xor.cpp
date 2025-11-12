#include<bits/stdc++.h>
using namespace std;
int numbers[500005] = {};
int p[500005] = {};
bool check(int i){
	int lenth = p[i];
	for(int j = i-1;j>=i-lenth;j--){
		if(p[j] != -1){
			return false;
		}
	}
	return true;
}
int a(int i,int j){
	int re = 0;
	for(int k = i;k<=j;k++){
		re = re ^ numbers[k];
	}
	return re;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> numbers[i];
	}
	for(int i = 0;i<=n;i++){
		p[i] = -1;
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(a(i,j) == k){
				p[j] = j-i;
				cnt++;
			}
		}
	}
//	//------------------------------
//	for(int i = 0;i<=n;i++){
//		cout << p[i];
//	}
//	
//	
//	int dp[500005] = {};
//	for(int i = 1;i<=n;i++){
//		if(p[i] != -1){
//			if(check(i) == true){
//				dp[i] = dp[i-1]+1;
//			}
//		}
//		dp[i] = dp[i-1];
//	}
//	for(int i = 1;i<=n;i++){
//		cout << dp[i];
//	}
//	cout << dp[n];
cout << cnt;

	fclose(stdin);
	
	fclose(stdout);
		return 0;
}
