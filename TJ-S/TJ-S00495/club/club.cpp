#include<bits/stdc++.h>
using namespace std;

typedef int INT;
#define int long long

const int N = 1e5+10;

int n;
int n2;
int ans;
int a[N][3+1];

int Solve0(){
	vector<vector<vector<int> > > dp(n2+10,vector<vector<int> >(n2+10,vector<int>(n2+10,0))); //???
	for(int i = 1; i <= n; i ++){
		int n3 = min(n2,i);
		for(int c1 = n3; c1 >= 0; c1 --){
			for(int c2 = n3; c2 >= 0 && i-c1-c2 <= n3; c2 --){
				int c3 = i-c1-c2;
				if(c3 < 0){
					continue;
				}
				if(c1 >= 1){
					dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1-1][c2][c3]+a[i][1]);
				}
				if(c2 >= 1){
					dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1][c2-1][c3]+a[i][2]);
				}
				if(c3 >= 1){
					dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1][c2][c3-1]+a[i][3]);
				}
				ans = max(ans, dp[c1][c2][c3]);
			}
		}
	}
	return ans;
}

int SolveSpecial(){	//特判：内存不够，假如有特殊性质A或B，即第三项一定为0 
	vector<vector<int> > dp(n2+10,vector<int>(n2+10,0));
	for(int i = 1; i <= n; i ++){
		int n3 = min(n2,i);
		for(int c1 = n3; c1 >= 0; c1 --){
			int c2 = i-c1;
			if(!(c2 >= 0 && c2 <= n3)){
				continue;
			}
			if(c1 >= 1){
				dp[c1][c2] = max(dp[c1][c2],dp[c1-1][c2]+a[i][1]);
			}
			if(c2 >= 1){
				dp[c1][c2] = max(dp[c1][c2],dp[c1][c2-1]+a[i][2]);
			}
			ans = max(ans,dp[c1][c2]);
		}
	}
	return ans;
}

int Solve(){
	cin >> n;
	n2 = n/2;
	ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= 3; j ++){
			cin >> a[i][j];
		}
	}
	if(n <= 1e4){
		return Solve0();
	}else{
		return SolveSpecial();
	}
	return 0;
}

INT main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T --){
		printf("%d\n",Solve());
	}
	return 0;
}
